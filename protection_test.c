#include "types.h"
#include "stat.h"
#include "user.h"
#include "mmu.h"
int
main(int argc, char *argv[])
{
  
  char *value = sbrk(0);
  sbrk(PGSIZE);
  *value=50;
  mprotect(value, 1) ;
  int child=fork();
  if(child==0){
	printf(1, "ٰٰٰٰٰValue = %d, has been protected . . .\n",*value); 
        munprotect(value, 1) ;  
        *value=5;
        printf(1, "Value changed to %d\n",*value); 
        exit();
  }
  else if(child>0){
        wait();
        printf(1, "** trap started **\n"); 
        *value=5; 
        exit(); 
  } 

 exit();
}
