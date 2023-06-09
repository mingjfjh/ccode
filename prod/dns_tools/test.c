#include <sys/socket.h>
#include <linux/if_arp.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <time.h>
#include <sys/time.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stddef.h>
#include <sys/un.h>
#include <signal.h>

#include <netdb.h>
extern int h_errno;

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

/******依赖产品的头文件******/
#include "common_flash.h"
#include "iof_lib_drv.h"
#include "common_ifaddrs.h"
#include "prod_common_hal.h"
#include "prod_common_system.h"
#include "prod_common_lan.h"


int main(int argc, char *argv[])
{
    struct hostent *host = NULL;

    printf("[ywcdbg][%s][%d] argc = [%d] ------------ \n", __func__, __LINE__, argc);

    if(2 != argc)
    {
        printf("[ywcdbg][%s][%d] argc = [%d] ------------ \n", __func__, __LINE__, argc);
        return -1;
    }
    for(int i = 0; i < argc; i++)
    {
        printf("[ywcdbg][%s][%d] argv[%d] = [%s] ------------ \n", __func__, __LINE__, i, argv[i]);
    }

    host = gethostbyname(argv[1]); 
    for(int i = 0; i < argc; i++)
    {
        if(NULL != host->h_addr_list[i])
            printf("[ywcdbg][%s][%d] host[%d] = [%s] ------------ \n", __func__, __LINE__, i, inet_ntoa(*(struct in_addr*)host->h_addr_list[i]));
    }

    return 0;
}

