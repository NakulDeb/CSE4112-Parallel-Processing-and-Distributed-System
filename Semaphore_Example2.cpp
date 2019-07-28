#include<bits/stdc++.h>
#include<semaphore.h>
using namespace std;

void sleep(int n){
    for(int i=0; i<n; i++){
        i = i;
    }
}

long long sum = 0;
sem_t my_sem;

void counter(int tnum){
    for(int i=0; i<20; i++){

        sem_wait(&my_sem);
        sleep(100000000);

        sum += 1;
        cout<<"THREAD : "<<tnum<<" Sum = "<<sum<<endl;
        if(tnum==2) cout<<endl;

        sem_post(&my_sem);
    }
}

void* T1(void * arg){
    counter(1);
    pthread_exit(NULL);
}
void* T2(void* arg){
    counter(2);
    pthread_exit(NULL);
}


int main()
{

    pthread_t pid1, pid2;
    int a = 1;

    sem_init(&my_sem,0,1);

    pthread_create(&pid1, NULL, T1, &a);
    pthread_create(&pid2, NULL, T2, &a);

    pthread_join(pid1,NULL);
    pthread_join(pid2,NULL);
    sem_destroy(&my_sem);

    return 0;
}


















