#include<bits/stdc++.h>
#include<semaphore.h>
using namespace std;

long long sum = 0;
long long limit = 1000000;

sem_t sem1;

void* counter(void * arg){
    long long offset = *(long long*)arg;
    for(long long i = 0; i<=limit; i++){
        sem_wait(&sem1);
        sum+=offset;
        sem_post(&sem1);
    }
    pthread_exit(NULL);
}

int main()
{
    sem_init(&sem1,0,1);
    pthread_t pid1;
    long long offset1 = 1;
    pthread_create(&pid1, NULL, counter, &offset1);


    pthread_t pid2;
    long long offset2 = -1;
    pthread_create(&pid2, NULL, counter, &offset2);

    pthread_join(pid1,NULL);
    pthread_join(pid2,NULL);

    printf("Sum = %lld\n",sum);

    sem_destroy(&sem1);
    return 0;
}
