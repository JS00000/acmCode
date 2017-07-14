#include <time.h>
#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <stdlib.h>
#include <string.h>

typedef long long ll;


clock_t start, finish;
ll Fn = 0, n = 0;

int dfs(int x)
{
    if (x == 0) return 0;
    if (x == 1) return 1;
    ll t = dfs(x-1) + dfs(x-2);
    if (x > n)
    {
        n = x;
        Fn = t;
    }
    return t;
}

void timeout_info(int signo)
{
    printf("n = %lld Fn = %lld\n", n, Fn);
    finish = clock();
    printf("Time cost:%lu\n", finish - start);
    fflush(stdout);
}

/* init sigaction */
void init_sigaction(void)
{
    struct sigaction act;
 
    act.sa_handler = timeout_info;
    act.sa_flags   = 0;
    sigemptyset(&act.sa_mask);
    sigaction(SIGALRM, &act, NULL);
}

/* init */
void init_time(void)
{
    struct itimerval val;
 
    val.it_value.tv_sec = 0;
    val.it_value.tv_usec = 100000;
    val.it_interval = val.it_value;
    setitimer(ITIMER_REAL, &val, NULL);
}


int main(int argc, char const *argv[])
{
    // init_sigaction();
    // init_time();
    // start = clock();

    // printf("%d\n", dfs(45));

    // finish = clock();
    // printf("Time cost:%lu\n", finish - start);
    
    int n = 100000000, m;

    start = clock();
    int j;
    for (j = 0; j < n; j++) m = j+j;
    finish = clock();
    printf("%lu\n", finish - start);

    start = clock();
    for (int i = 0; i < n; i++) m = i+i;
    finish = clock();
    printf("%lu\n", finish - start);

    start = clock();
    for (j = 0; j < n; j++) m = j+j;
    finish = clock();
    printf("%lu\n", finish - start);

    start = clock();
    for (int i = 0; i < n; i++) m = i+i;
    finish = clock();
    printf("%lu\n", finish - start);

    start = clock();
    for (j = 0; j < n; j++) m = j+j;
    finish = clock();
    printf("%lu\n", finish - start);

    start = clock();
    for (int i = 0; i < n; i++) m = i+i;
    finish = clock();
    printf("%lu\n", finish - start);


    return 0;
}
