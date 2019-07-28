#include<bits/stdc++.h>
using namespace std;

long long sum = 0;
long long limit = 1000000;

pthread_mutex_t mutex_1 = PTHREAD_MUTEX_INITIALIZER;

void* counter(void * arg){
    long long offset = *(long long*)arg;
    for(long long i = 0; i<=limit; i++){
        pthread_mutex_lock(&mutex_1);
        sum+=offset;
        pthread_mutex_unlock(&mutex_1);
    }
    pthread_exit(NULL);
}

int main()
{
    pthread_t pid1;
    long long offset1 = 1;
    pthread_create(&pid1, NULL, counter, &offset1);


    pthread_t pid2;
    long long offset2 = -1;
    pthread_create(&pid2, NULL, counter, &offset2);

    pthread_join(pid1,NULL);
    pthread_join(pid2,NULL);

    printf("Sum = %lld\n",sum);
}
