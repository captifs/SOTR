// Exemplu de setare a momentului la care va fi declanşat automat un semnal de
// alarmare. Durata de timp ce se va scurge pânã la producerea evenimentului,
// exprimată în secunde, va fi introdusă de de la tastaturã cãtre utilizatorul
// programului. 

#include <stdio.h>

#include <unistd.h>

#include <signal.h>

void semnal() {
  printf("Alarmã !!!");
  exit(0);
}

int main() {
  int sec;
  signal(SIGALRM, semnal);
  printf("Dupã câte secunde doriţi sã se declanşeze alarma ?: ");
  scanf("%d", & sec);
  alarm(sec);
  while (1);
  return 0;
}
