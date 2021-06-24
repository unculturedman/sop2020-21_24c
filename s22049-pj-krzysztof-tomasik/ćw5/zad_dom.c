#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  pid_t masterPid = getpid();
  pid_t childPid = fork();

  if (childPid == 0) {
    pid_t newChildPid = fork();
    if (newChildPid > 0) {
      fork();
    }
  }

  if (masterPid == getpid()) {
    childPid = fork();
    if (childPid == 0) {
      pid_t newChildPid = fork();
      if (newChildPid > 0) {
        fork();
      }
    }
  }

  if (masterPid == getpid()) {
    getchar();
  }

  printf("PID: %d, PPID: %d\n", getpid(), getppid());

  return 0;
}
