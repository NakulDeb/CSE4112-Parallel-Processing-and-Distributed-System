#include<bits/stdc++.h>
#include<semaphore.h>
using namespace std;

long long sum = 0;
pthread_mutex_t my_mutex = PTHREAD_MUTEX_INITIALIZER;

void counter(int tnum){
    for(int i=0; i<10; i++){
        pthread_mutex_lock(&my_mutex);
        sum += 1;
        cout<<"THREAD : "<<tnum<<" Sum = "<<sum<<endl;
        if(tnum==2) cout<<endl;
        pthread_mutex_unlock(&my_mutex);
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

    //pthread_mutex_in

    pthread_create(&pid1, NULL, T1, &a);
    pthread_create(&pid2, NULL, T2, &a);

    pthread_join(pid1,NULL);
    pthread_join(pid2,NULL);

    return 0;
}


















