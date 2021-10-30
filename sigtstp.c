#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>

int main(void)
{

  void sigtstp_handler(int sig);
  char s[200];

  if (signal(SIGTSTP, sigtstp_handler) == SIG_ERR){
     perror("signal");
     exit(1);
  }

  printf("Enter a string:\n");

  if (fgets(s, 200, stdin) == NULL)
      perror("gets");
  else
      printf("you entered: %s\n", s);

  return 0;
}

void sigtstp_handler(int sig)
{
  printf("This is special signal handler for <signal TSTP>!\n");
}
