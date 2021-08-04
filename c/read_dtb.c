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