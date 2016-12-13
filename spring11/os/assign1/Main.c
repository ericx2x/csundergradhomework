/*************************************/
/* Programmer : Eric Lima            */
/*                                   */
/* Program : Assignment 1            */
/*                                   */
/* Date : February 7th, 2011         */
/*************************************/

#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <syscall.h>
#include <sys/resource.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

/* These are counters to be used with the updated cycles. */
int counter = 0, counter_2g = 0;


/* Below is the union structure */
typedef union{ int exit_status;
  struct{
    unsigned sig_num:7; 
    unsigned core_dmp:1;
    unsigned exit_num:8;
  } parts;
} LE_Wait_Status;

void sig_handler(int signal){

  sigset_t proc_mask;
  sigemptyset(&proc_mask);
  sigprocmask(SIG_SETMASK, &proc_mask, NULL);
  fflush(stdout); /*flush out the prints*/
  execl("./A1", "A1", NULL);
  perror("Error executing a1, exiting..."); 
  exit(3);
}

int main (int argc, char *argv[]){

  pid_t pid, ppid; 
  int priority, ruid, rgid, euid, egid;
  char read_buf[10];
  sigset_t mask, proc_mask;
  struct sigaction new_act;
  int synch_pipe[2];
  LE_Wait_Status exit_union;

  if (pipe(synch_pipe) == -1){
    perror("\nParent pipe creation failed\n");
    exit(7);
  }

  printf("\nParent process report:\n");
  pid = getpid();
  ppid = getppid();
  ruid = getuid();
  euid = geteuid();
  rgid = getgid();
  egid = getegid();
  priority = getpriority(PRIO_PROCESS, 0);
 
  printf("\nPARENT: Process parent ID is -\t\t%d\nPARENT: Process Parent ID -\t%d\nPARENT: Real UID -\t\t%d\nPARENT: REAL GID -\t\t%d\nPARENT: Effective UID -\t\t%d\nPARENT: Effective GID -\t\t%d\nPARENT: Process Priority -\t%d\n", pid, ppid, ruid, rgid, euid, egid, priority);  

  switch (pid = fork()){
  default: 
    printf("Created child with pid %d", pid);
    break;
  case -1: 
    {
      perror("Can't create child");
      exit(4);
      break;
    }
    /*child data*/
  case 0:
    {
      sigemptyset(&mask);
      new_act.sa_mask = mask;
      new_act.sa_handler = sig_handler;
      new_act.sa_flags = 0;

      if (sigaction(SIGTERM, &new_act, NULL) == -1){
	perror("Failed in Sigaction");
	exit(2);
      }

      printf("\nChild process report: \n");
      pid = getpid();
      ppid = getppid();
      ruid = getuid();
      euid = geteuid();
      rgid = getgid();
      egid = getegid();
      priority = getpriority(PRIO_PROCESS, 0);
         
      printf("\nCHILD: Process ID -\t\t%d\nCHILD: Process Parent ID -\t%d\nCHILD: Real UID -\t\t%d\nCHILD: REAL GID -\t\t%d\nCHILD: Effective UID -\t\t%d\nCHILD: Effective GID -\t\t%d\nCHILD: Process Priority -\t%d\n", pid, ppid, ruid, rgid, euid, egid, priority);

      printf("\nChild: About to write pipe and goto endless loop.\n");
      fflush(stdout);
      write(synch_pipe[1], "x", 1);

      while(1){
	counter++;
	if (counter < 0) {
	  counter = 0;
	  counter_2g++;
	}
      }
      break;
    } 
  } // break from the switch

  read(synch_pipe[0], read_buf, 1);
  kill(pid, SIGTERM);

  printf("\nParent: read pipe and send sigterm, wait for exit");

  if ((pid = wait(&exit_union, 6)) == -1){
    perror("Wait failed in Parent");
    exit(6);
  }

  printf("\nParent: child %d exited with %s code %d", 
	 pid, 
	 (exit_union.parts.sig_num == 0)?"exit":"signal", 
	 (exit_union.parts.sig_num == 0)?exit_union.parts.exit_num:exit_union.parts.sig_num);
}
