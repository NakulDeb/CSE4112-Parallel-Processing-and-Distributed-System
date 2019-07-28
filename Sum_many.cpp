#include<bits/stdc++.h>
#define ll long long
using namespace std;

class Sum_many{
public:
    ll limit;
    ll ans;
};

void* sum_0_to_N(void *arg){
    Sum_many *limit_ptr = (Sum_many*) arg;
    ll sum = 0;
    for(long long i = 0; i <= limit_ptr->limit; i++){
        sum += i;
    }
    limit_ptr->ans = sum;
    pthread_exit(0);
}

int main(int argc, char **argv)
{
    if(argc<2){
        printf("Usage: %s <num>\n",argv[0]);
        exit(-1);
    }
    ll proc_num = argc-1;
    pthread_t tid[proc_num];

    Sum_many ob[proc_num];

    for(ll i=0; i<proc_num; i++){
        ob[i].limit = atoll(argv[i+1]);
        pthread_attr_t attr;
        pthread_attr_init(&attr);
        pthread_create(&tid[i], &attr, sum_0_to_N, &ob[i].limit);
    }

    for(ll i=0; i<proc_num; i++){
        pthread_join(tid[i],NULL);
        printf("Sum for Thread : %d = %lld\n",tid[i], ob[i].ans);
    }
    return 0;

}
