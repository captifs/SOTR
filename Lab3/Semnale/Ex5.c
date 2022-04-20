// Program ce determinã capacitatea de stocare a informaţiilor specificã unui pipe
// fără nume folosind semnale. Procesul scrie informaţii în pipe fãrã a fi interesat
// de existenţa unui potenţial consumator. Deoarece procesul consumator nu existã,
// la un moment dat pipe-ul se umple. Ca urmare, se va produce un eveniment care
// va genera un semnal tratat prin apelarea unei funcţii specifice. 

#include <signal.h>

#include <stdio.h>

#include <unistd.h>

int p[2];
int total = 0;
void gata() {
  printf("Capacitatea pipe-ului este de %d octeţi \n", total);
  raise(SIGTERM);
}
int main() {
  char c = '*';
  if (pipe(p) < 0) {
    printf("Eroare la creare pipe !");
    exit(1);
  }
  signal(SIGALRM, gata);
  alarm(1);
  while (1) {
    if (write(p[1], & c, 1) != 1) {
      printf("Scriu in pipe ! \n");
      exit(1);
    }
    total++;
  }
  return 0;
}
