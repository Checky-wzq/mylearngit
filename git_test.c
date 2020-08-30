

#include <stdio.h>

#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include "math.h"

void handler_test()
{
}
//子线程执行函数
void *pthread_test(void *arg)
{
    // static time_t lasttime;
    // time_t  nowtime;

    // while(1)
    // {
    //     time(&nowtime);
    //     char *localtime=ctime(&nowtime);//北京时间
    //     if(abs(difftime(nowtime,lasttime))>=1)
    //     {

    //         printf("local time: %s\r\n",localtime);
    //         lasttime = nowtime;    
    //     }
        

    // }
    // return NULL;


    static struct timeval lasttime;
    struct timeval  nowtime;

    while(1)
    {
        gettimeofday(&nowtime,0);
        if(nowtime.tv_sec-lasttime.tv_sec>=1)
        {
            char *localtime = ctime(&(nowtime.tv_sec)); 
            printf("local time: %s\r\n",localtime);  
            lasttime.tv_sec = nowtime.tv_sec; 
        }
        

    }
    return NULL;

}


int main(void)
{
    pthread_t tid =-1;

    //signel
    pthread_create(&tid,NULL,pthread_test,NULL);

    while(1)
    {
        printf("This is while!!!!\n");
        sleep(5);
    }
    return 0;
}
