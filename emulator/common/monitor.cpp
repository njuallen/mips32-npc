#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "common.h"

bool finished = false;

#define check_finished() if(finished) { printf("Program has ended\n"); return 0; }

/* We use the ``readline'' library to provide more flexibility to read from stdin. */
char* rl_gets() {
  static char *line_read = NULL;

  if (line_read) {
    free(line_read);
    line_read = NULL;
  }

  line_read = readline("(nemu) ");

  if (line_read && *line_read) {
    add_history(line_read);
  }

  return line_read;
}

static int cmd_c(char *args, int *ret_code) {
  check_finished()
  return sc(-1, ret_code);
}

static int cmd_q(char *args, int *ret_code) {
  return -2;
}


static int cmd_help(char *args, int *ret_code);

static int cmd_si(char *args, int *ret_code) {
  check_finished()
  unsigned step_num;
  /*if no step number is specified, by default it execute one instruction*/
  if(args==NULL) {
    return sc(1, ret_code);
  }
  if(sscanf(args, "%u", &step_num) > 0)
    return si(step_num, ret_code);
  else
    printf("Error, si command should be followed by a number!\n");
  return 0;
}

static int cmd_sc(char *args, int *ret_code) {
  check_finished()
  unsigned step_num;
  /*if no step number is specified, by default it execute one instruction*/
  if(args==NULL)
    return sc(1, ret_code);
  if(sscanf(args, "%u", &step_num) > 0)
    return sc(step_num, ret_code);
  else
    printf("Error, si command should be followed by a number!\n");
  return 0;
}

const char *regs[32] = {
  "zero", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
  "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
  "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
};

int cmd_info(char *args, int *ret_code)
{
  check_finished()
  char subcmd[5];
  if(sscanf(args, "%4s", subcmd)>0)
  {
    if(strcmp(subcmd, "r")==0)
    {
      // print pc
      printf("$pc: 0x%08x\n", read_reg(32));
      // print in eight lines
      for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 4; j++) {
          int regno = 4 * i + j;
          printf("$%s 0x%08x  ", regs[regno], read_reg(regno));
        }
        printf("\n");
      }
      return 0;
    }
  }
  printf("Error, illegal subcommand!\nNote" 
      "that, only 'r' is allowed!\n");
  return 1;
}

static struct {
  const char *name;
  const char *description;
  int (*handler) (char *, int *);
} cmd_table [] = {
  /*only cmd_q can return a negative value!*/
  { "help", "Display informations about all supported commands", cmd_help }, 
  { "c", "Continue the execution of the program", cmd_c }, 
  { "q", "Exit Monitor", cmd_q }, 
  { "si", "Single step", cmd_si}, 
  { "sc", "Single cycle", cmd_sc}, 
  { "info", "Print information", cmd_info}
};

#define NR_CMD (sizeof(cmd_table) / sizeof(cmd_table[0]))

/*
 * commands should not be no longer than 4 characters
 * or it will be difficult to format them
 */
static int cmd_help(char *args, int *ret_code) {
  /* extract the first argument */
  char *arg = strtok(NULL, " ");
  int i;

  if(arg == NULL) {
    /* no argument given */
    for(i = 0; i < NR_CMD; i ++) {
      printf("%-4s - %s\n", cmd_table[i].name, cmd_table[i].description);
    }
  }
  else {
    for(i = 0; i < NR_CMD; i ++) {
      if(strcmp(arg, cmd_table[i].name) == 0) {
        printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
        return 0;
      }
    }
    printf("Unknown command '%s'\n", arg);
  }
  return 0;
}

// ret_code is the code that the program on our cpu returns
int monitor(void) {
  while(1) {
    char *str = rl_gets();
    char *str_end = str + strlen(str);

    /* extract the first token as the command */
    char *cmd = strtok(str, " ");
    if(cmd == NULL) { continue; }

    /* treat the remaining string as the arguments, 
     * which may need further parsing
     */
    char *args = cmd + strlen(cmd) + 1;
    if(args >= str_end) {
      args = NULL;
    }

    int i;
    for(i = 0; i < NR_CMD; i ++) {
      if(strcmp(cmd, cmd_table[i].name) == 0) {
        // if return code != 0,
        // we know that either the program ended(timeout(-1), normal(1))
        // or the user manually exited using "q" command(-2)
        int ret_code = 0;
        int ret = cmd_table[i].handler(args, &ret_code);

        if(ret) {
          // use q to exit monitor
          if(ret == -2)
            return 0;
          else if(ret == -1)
            printf("*** FAILED *** (timeout)\n");
          else if(ret == 1) {
            if(ret_code <= 1)
              printf("*** PASSED ***\n");
            else
              printf("*** FAILED *** (code: %d)\n", ret_code);
          }
          finished = true;
        }
        break;
      }
    }
    if(i == NR_CMD) { printf("Unknown command '%s'\n", cmd); }
  }
}
