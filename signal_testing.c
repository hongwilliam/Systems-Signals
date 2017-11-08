#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>

static void sighandler(int signo){
  if (signo == SIGINT){
    //kill -2 PID
    printf("The program is now exiting due to SIGINT \n");
    exit(1);

  }
  if (signo == SIGUSR1){
    kill(getpid(), SIGUSR1);
    //kill -30 PID
    printf("Here is the PID of parent process: %d \n", getppid() );
    sleep(1); }
}


int main(){

  signal(SIGINT, sighandler);
  signal(SIGUSR1, sighandler);

  while (1){
    printf("hello, I'm: %d \n", getpid() );
    sleep(1); }

}
