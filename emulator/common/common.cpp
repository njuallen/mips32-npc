#include <cstdio>
#include <cstdlib>

void app_error(const char *msg) {
  fprintf(stderr, "%s\n", msg);
  exit(1);
}
