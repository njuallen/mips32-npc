#ifndef __COMMON_H
#define __COMMON_H

#include <cstdio>
#include <cstring>
#include <cstdlib>

#ifdef __cplusplus
# include <stdexcept>
# define print_and_die(s) throw std::runtime_error(s)
#else
# define print_and_die(s) do { fprintf(stderr,"%s\n",s); abort(); } while(0)
#endif

#define demand(cond,str,...) \
  do { if(!(cond)) { \
      char __str[256]; \
      snprintf(__str,256,"in %s, line %d: " str, \
               __FILE__,__LINE__,##__VA_ARGS__); \
      print_and_die(__str); \
    } } while(0)

// for debugging
int sc(unsigned int ncycle, int *ret_code);
int si(unsigned int ninstr, int *ret_code);
unsigned int read_reg(int reg_no);

// device
void init_device(void);
bool is_finished(void);
int get_exit_code(void);

void app_error(const char *msg);

int monitor(void);
#endif // __COMMON_H
