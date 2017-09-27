#!/usr/bin/python

import os, sys

def run_emulator(pipes, emulator, program, timeout):
    # redirect stdin
    os.dup2(pipes[0], 0)
    # redirect stdout
    os.dup2(pipes[3], 1)
    # redirect stderr to stdout
    # os.dup2(1, 2)

    # pipes has been dupped, now they should be closed
    for i in range(0, 4):
        os.close(pipes[i])

    ret = os.execl(emulator, emulator, "+max-cycles=%s" % timeout, "+loadmem=%s" % program, "-d")


def get_emulator_io(pipes):
    # This is the parent process 
    # Closes file descriptor w
    os.close(pipes[0])
    os.close(pipes[3])
    emu_in = os.fdopen(pipes[1], "w", 0)
    emu_out = os.fdopen(pipes[2], "r")
    return emu_in, emu_out


def get_two_pipes():
    # use this to redirect emulator's input
    in_r, in_w = os.pipe() 
    # use this to redirect emulator's out
    out_r, out_w = os.pipe()
    return in_r, in_w, out_r, out_w

# step one instruction
# and get the result of this execution
# result: (ret_code, output)
def si(emu_in, emu_out):
    l = "si\n"
    emu_in.write(l)
    # consume prompt and input echo
    emu_out.readline()

    # then we try to get registers
    l = "info r\n"
    emu_in.write(l)
    l = emu_out.readline()

    code = 0
    output = ""
    # the emulator is still running
    # program not ended
    # we can continue to read registers
    if l[0:6] == "(nemu)":
        code = 0
        for i in range(0, 9):
            output += emu_out.readline()
    elif l[0:14] == "*** PASSED ***":
        code = 1
        output = l
    else:
        # error
        code = 2
        output = l
    return code, output


def cross_check(in_a, out_a, in_b, out_b, program, trace):
    instr_count = 0
    with open(trace, "w") as f:
        while True:
            code_a, output_a = si(in_a, out_a)
            code_b, output_b = si(in_b, out_b)
            instr_count += 1
            # print code_a, output_a
            # print code_b, output_b
            if code_a == code_b and output_a == output_b:
                f.write(output_a);
                # add an blank line to seperate trace of different instruction
                f.write("\n");
                if code_a == 0:
                    continue
                elif code_a == 1:
                    print "[ PASSED ] %s after %d instructions" % (program, instr_count)
                    break
                else:
                    print "[ FAILED ] %s after %d instructions" % (program, instr_count)
                    break
            else:
                print "[ CROSSCHECK_FAILED ] %s after %d instructions" % (program, instr_count)
                f.write("================ %s ================\n" % emu_a);
                f.write(output_a);
                f.write("---------------- %s ----------------\n" % emu_b);
                f.write(output_b);
                f.write("====================================\n");
                break

if __name__ == "__main__":
    assert len(sys.argv) == 6, "Expect emulator a, emulator b, program to load , output crosscheck file and timeout.\n"
    emu_a = sys.argv[1]
    emu_b = sys.argv[2]
    program = sys.argv[3]
    trace = sys.argv[4]
    timeout = sys.argv[5]

    pipes = get_two_pipes()
    pid = os.fork()
    if pid:
        in_a, out_a = get_emulator_io(pipes)
        pipes = get_two_pipes()
        pid = os.fork()
        if pid:
            in_b, out_b = get_emulator_io(pipes)
            # do cross checking
            cross_check(in_a, out_a, in_b, out_b, program, trace)
        else:
            # emulator b
            run_emulator(pipes, emu_b, program, timeout)
    else:
        # emulator a
        run_emulator(pipes, emu_a, program, timeout)
