// Programul creeazã un proces fiu care aşteaptã semnale de la pãrinte. Procesul
// pãrinte transmite 10 semnale SIGALRM dupã care "omoarã" procesul fiu,
// transmiţându-i semnalul SIGTERM. 


#include <stdio.h>

#include <stdlib.h>

#include <unistd.h>

#include <signal.h>

void t_SIGALRM() {
  printf("Sunt procesul cu PID %d şi am primit semnalul SIGALRM !!! \n",
    getpid());
}
int main() {
  int pid, st, i;
  char c;

  signal(SIGALRM, t_SIGALRM);
  if ((pid = fork()) == 0) {
    while (1) pause(); //procesul fiu aşteaptã semnale de la procesul pãrinte
  } else {
    for (i = 0; i < 10; ++i) {
      printf("%d Sunt procesul cu PID %d şi trimit SIGALRM...\n", i, getpid());
      kill(pid, SIGALRM);
    }
    printf("Trimit SIGTERM...\n");
    kill(pid, SIGTERM); // trimit semnal de terminare a procesului fiu
    wait( & st);
  }
  return 0;
}
