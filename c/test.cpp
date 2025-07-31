#include<stdio.h>
#include<malloc.h>
long long* Fibonacci(size_t N)
{
    if (N == 0)
        return NULL;
    long long* fibArray = (long long*)malloc(sizeof(long long)*N);
    fibArray[0]= 0;
    if(N > 1) fibArray[1]= 1;// 以空间换时间for(int i=2;i<N; ++i)
    for(int i=2;i<N; ++i)
    {
        fibArray[i]=fibArray[i-1]+ fibArray[i -2];
    }
    return fibArray;
}
int main()
{
    size_t N = 10;
    long long* fib = Fibonacci(N);
    if (fib) {
        for (size_t i = 0; i < N; ++i) {
            printf("%lld ", fib[i]);
        }
        printf("\n");
        free(fib);
    }
    return 0;
}