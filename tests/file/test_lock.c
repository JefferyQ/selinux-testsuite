#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/file.h>
#include<fcntl.h>
#include<unistd.h>
#include<linux/unistd.h>
#include<selinux/selinux.h>

/*
 * Test the lock file operation on a file whose name is given as the first 
 * argument. The second argument must be the SID we are to use to test
 * the actual lock() operation by changing the SID of the file we are
 * given.
 */
int main(int argc, char **argv) {

  int fd;
  int rc;

  if( argc != 3 ) {
    printf("usage: %s filename context\n", argv[0]);
    exit(2);
  }

  fd = open(argv[1], O_RDONLY, 0);
  
  if(fd == -1) {
    perror("test_lock:open");
    exit(2);
  }

  rc = fsetfilecon(fd, argv[2]);
  if (rc < 0) {
    perror("test_lock:fsetfilecon");
    exit(2);
  }

  rc = flock(fd, LOCK_EX);
  if( rc == -1 ) {
    perror("test_lock:LOCK_EX");
    exit(1);
  }

  close(fd);
  exit(0);

}
