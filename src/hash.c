#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <zconf.h>
#include <wait.h>

#define SIZE 16

unsigned long
doHash(char *key) {

       int pid, status;
   // first we fork the process
   if (pid = fork()) {
       // pid != 0: this is the parent process (i.e. our process)
       waitpid(pid, &status, 0); // wait for the child to exit
   } else {
       /* pid == 0: this is the child process. now let's load the
          "ls" program into this process and run it */

       const char executable[] = "./lib/rg32hash/bin/tinyrg32";

       // load it. there are more exec__ functions, try 'man 3 exec'
       // execl takes the arguments as parameters. execv takes them as an array
       // this is execl though, so:
       //      exec         argv[0]  argv[1] end
       execl(executable, executable, key,    NULL);

       /* exec does not return unless the program couldn't be started.
          when the child process stops, the waitpid() above will return.
       */


   }
   return status; // this is the parent process again.

}


uint32_t adler32(const void *buf, size_t buflength) {
    const uint8_t *buffer = (const uint8_t *) buf;

    uint32_t s1 = 1;
    uint32_t s2 = 0;

    for (size_t n = 0; n < buflength; n++)
    {
        s1 = (s1 + buffer[n]) % 65521;
        s2 = (s2 + s1) % 65521;
    }
    return (s2 << 16) | s1;
}


int main(int argc, char *argv[]) {
    unsigned long hash;
    if (argc == 2)
    {
        printf("%s, %i\n", argv[1], strlen(argv[1]));
        hash = doHash(argv[1]);
        printf("%s", hash);
    }
    else
    {
        printf("Error, usage: %s <string>\n", argv[0]);
        return -1;
    }

    return 0;
}
