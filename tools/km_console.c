#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>

int main(int argc, char *argv[])
{
    char *tty = ttyname(STDOUT_FILENO);
    if (!tty) {
        perror("ttyname");
        return 1;
    }
    printf("Current TTY is %s\n", tty);

    int fd = open(tty, O_RDWR);
    if (fd < 0) {
        perror("open tty");
        return 1;
    }

    if (ioctl(fd, TIOCCONS) < 0) {
        perror("TIOCCONS");
        return 1;
    }

    printf("Kernel console redirected to %s\n", tty);
    return 0;
}

