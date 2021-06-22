#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*
* Zaczęte na ćwiczeniach, skończone w domku
*/

int main(int argc, char *argv[]) {
    FILE *f;
    int i;
    int loop;
    int *liczby;
    bool printFlag = false;
    char filename[255];
    char tempchar;

    for (loop = 1; loop < argc; loop++) {
        if (strcmp(argv[loop], "--print") == 0) {
            printFlag = true;
        } else {
            strcpy(filename, argv[loop]);
        }
    }

    if (argc < 2) {
        f = stdin;
    } else {
        f = fopen(filename, "r");
    }

    if (f == NULL) {
        return 1;
    }

    if (printFlag) {
      tempchar = fgetc(f);
      while (tempchar != EOF) {
        putchar(tempchar);
        tempchar = fgetc(f);
      }
    } else {
      fscanf(f, "%d\n", &i);
      liczby = malloc(i * sizeof(i));

      for (loop = 0; loop < i;loop++) {
          int a;
          fscanf(f, "%d\n", &a);
          liczby[loop] = a;
      }

      if (f != NULL) {
        fclose(f);
      }

      for (loop = i;loop > 0;--loop) {
          int a = liczby[loop-1];
          printf("%d\n", a);
      }

      if (liczby != NULL) {
        free(liczby);
      }

    }

    return 0;
}
