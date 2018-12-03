#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/stat.h>

using namespace std;

void my_Daemon(void)
{
  
  pid_t id = fork();
  if(id < 0)
  {
    cout << "fork error" << endl;
    exit(1);
  }
  if(id > 0)//parent
  {
    exit(0);
  }
   
  umask(0);
  setsid();

  close(0);
  close(1);
  close(2);
  signal(SIGCHLD,SIG_IGN);

}

int main()
{
  my_Daemon();
  while(1)
  {
    sleep(1);
  }
}
