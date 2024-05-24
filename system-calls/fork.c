#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
 
    // make two process which run same
    // program after this instruction  
    printf("parent_pid = %d\n", getpid());
	
    pid_t p = fork();
    if (p<0) {
      perror("fork fail");
      return 1;
    }
    printf("p = %d | process_id(pid) = %d\n", p, getpid());
    return 0;
}
