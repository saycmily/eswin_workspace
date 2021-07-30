#include <stdio.h>
 
int main()
{
    int fd;
    puts("read dtb file:");
    fd = open("/home/cmily/driver/c/test_print.c", O_RDONLY);
    if(fd < 0) {
        perror("open");
        exit(0);
    }
    printf("\n/home/cmily/driver/c/test_print.c opend, fd=%d\n", fd);
    
    return 0;
}
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
main()
{
    int fd, size;
    char s[] = "Linux Programmer!\n", buffer[80];
    fd = open("/tmp/temp", O_WRONLY|O_CREAT);
    write(fd, s, sizeof(s));
    close(fd);
    fd = open("/tmp/temp", O_RDONLY);
    size = read(fd, buffer, sizeof(buffer));
    close(fd);
    printf("%s", buffer);
}