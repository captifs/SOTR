// Folosind semnalul SIGALRM, programul afişeazã informaţii despre momentul
// curent de timp. Afişarea informaţiilor este făcută în mod ciclic de către procesul
// fiu. 

#include <stdio.h>

#include <stdlib.h>

#include <unistd.h>

#include <signal.h>

#include <errno.h>

#include <time.h>

static void ex() {
  char * sir;
  time_t timp;
  timp = time(NULL);
  sir = ctime( & timp);
  printf("\n Momentul curent de timp: %s ", sir);
}
void alarma() {
  int i;
  if (signal(SIGALRM, ex) == SIG_ERR) {
    perror("Eroare la signal()");
    exit(1);
  }
  for (i = 0; i < 3; i++) {
    alarm(2);
    pause();
  }
}

int main() {
  int st;
  switch (fork()) {
  case -1:
    printf("Eroare fork()");
    return -1;
  case 0:
    printf("\n Proces fiu \n");
    alarma();
  default:
    printf("Proces părinte\n");
    wait( & st);
    return 0;
  }
  return 0;
}
