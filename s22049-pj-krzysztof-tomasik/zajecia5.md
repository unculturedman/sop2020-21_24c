Procesy w C, Forki, Clone'y (haha nie) i te inne
================================================

`pid_t fork()` kopiuje program w osobny proces i odpala go od następnej instrukcji. Zwraca natomiast nowe id procesu. Po tym rozpoznajemy czy znajdujemy się w forkowanym procesie, czy w procesie forkującym. Forkujący program ma zapisane pid swojego childa, a dla childa ta zmienna będzie pusta. `pid_t getpid()` zwraca pid procesu, `pid_t getppid()` zwraca pid procesu rodzica.

```c
pid_t childPid = fork();
if (childPid == 0) {
  //instrukcje, które wykona tylko child
}
if (childPid > 0) {
  //instrukcje, które wykona tylko parent
}
```

Przykład: Program odpalający 100 podprocesów i oczekujący na ich zamknięcie.

```c
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  pid_t masterPid = getpid();
  for (int i = 0;i<100;i++) {
    fork();
    if (getpid() != masterPid) {
      break;
    }
  }

  if (getpid() == masterPid) {
    int status;
    for (int i = 0;i<100;i++) {
      wait(&status);
    }
  }

  return 0;
}
```

`clone()` działa podobnie do forka - również tworzy drugi proces, który wykonuje się równolegle, jednakże klonowany proces może dzielić pamięć z rodzicem, zamiast kopiowania całej pamięci. Przydatne, gdy chcesz zrównoleglić jakieś obliczenia.

W folderze ćw5 znajduje się zadanie domowe.
