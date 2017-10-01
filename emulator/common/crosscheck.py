#!/usr/bin/python

import os, sys

# colors
KNRM = "\x1B[0m"
KRED = "\x1B[31m"
KGRN = "\x1B[32m"
KYEL = "\x1B[33m"
KBLU = "\x1B[34m"
KMAG = "\x1B[35m"
KCYN = "\x1B[36m"
KWHT = "\x1B[37m"

def green(str):
    return KGRN + str + KNRM

def red(str):
    return KRED + str + KNRM

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

    ret = os.execl(emulator, emulator, "+max-cycles=%s" % timeout, "-d")


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


def cross_check(emu_a, in_a, out_a, emu_b, in_b, out_b, program, trace):
    instr_count = 0
    ret = 0
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
                    # both succeeds
                    print "[ %s ] %s after %d instructions" % (green("PASSED"), program, instr_count)
                    ret = 0
                    break
                else:
                    # both failed
                    print "[ %s ] %s after %d instructions" % (red("FAILED"), program, instr_count)
                    ret = 1
                    break
            else:
                print "[ %s ] %s after %d instructions" % (red("CROSSCHECK_FAILED"), program, instr_count)
                f.write("================ %s ================\n" % emu_a);
                f.write(output_a);
                f.write("---------------- %s ----------------\n" % emu_b);
                f.write(output_b);
                f.write("====================================\n");
                ret = 2
                break
    return ret

def crosscheck_main():
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
            return cross_check(emu_a, in_a, out_a, emu_b, in_b, out_b, program, trace)
        else:
            # emulator b
            run_emulator(pipes, emu_b, program, timeout)
    else:
        # emulator a
        run_emulator(pipes, emu_a, program, timeout)


if __name__ == "__main__":
    # if we failed, we return an error code
    # so that make will stop running other tests
    # so we do not have to scroll up to find which ones have failed
    ret = crosscheck_main()
    sys.exit(ret)
