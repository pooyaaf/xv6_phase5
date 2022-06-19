#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
   int ppid = getpid();

   if (fork() == 0) {
      uint * nullp = (uint*)0;
      printf(1, "***********NULL DEREFERENCE CATCHED *********** \n");
      printf(1, "%x %x\n", nullp, *nullp);

      printf(1, "*********** FAILED ***********\n");
      kill(ppid);
      exit();
   } else {
      wait();
   }

   printf(1, "*********** SECCESS ***********\n");
   exit();
}