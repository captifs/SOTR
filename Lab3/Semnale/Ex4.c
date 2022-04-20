// La primirea semnalului SIGUSR1, procesul aflat în execuţie creeazã 5 procese
// fiu. Fiecare dintre acestea îşi scrie numãrul de ordine asociat în fişierul test.txt.
// Pentru a determina transmiterea semnalului SIGUSR1, utilizatorul programului
// trebuie să realizeze următoarele acţiuni:
// - intră într-un nou terminal, imediat după lansarea în execuţie a
// programului ;
// - cu ajutorul comenzii shell ps, determină PID-ul procesului asociat
// programului aflat în execuţie;
// - transmite semnalul SIGUSR1 folosind cu comanda shell kill în forma:
//  kill –SIGUSR1 PID_Proces


#include <unistd.h>

#include <signal.h>

#include <stdio.h>

void sighandler(int sig) {
  int i, pid;
  FILE * f;
  f = fopen("test.txt", "wt");
  fprintf(f, "Procesul părinte\n");
  fclose(f);
  for (i = 0; i < 5; i++) {
    if ((pid = fork()) < 0) {
      printf("Eroare la apelare fork() !");
      exit(0);
    }
    if (!pid) {
      f = fopen("test.txt", "at");
      fprintf(f, "S-a executat procesul fiu %d\n", i + 1);
      fclose(f);
      exit(1);
    }
  }
  printf("\n GATA ! \n");
}
int main() {
  if (signal(SIGUSR1, sighandler) == SIG_ERR)
    printf("Eroare la semnal !");
  pause();
  return 0;
}
