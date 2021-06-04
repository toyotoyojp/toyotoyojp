
#include <stdio.h>
#include <stdlib.h>

#include <time.h>

#define N 10

int fib(int n){	
	int i ;
    int fn2=0, fn1=1, fn=0;
 
    for (i =2; i <= n; i++){
        fn = fn1 +fn2;
        fn2 = fn1;
        fn1 = fn;
    } 
    return fn;
}

int fib1(int n){
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fib1(n-1) + fib1(n-2);

}
int memo[N+1];

int fib3(int n){
    int ret;
    
    if (memo[n] > 0)
        return memo[n];

    if (n == 0)
        ret = 0;
    else if (n == 1)
        ret = 1;
    else
        ret =fib1(n-1) + fib1(n-2);
    memo[n] = ret;
    return ret;
}

int main(void) {

    clock_t start, finish;

    start =clock();

   printf("%d \n",fib(N));
    printf("%d \n",fib1(N));
 printf("%d \n",fib3(N));

    finish =clock();

    printf("%f\n", (double)(finish-start)/CLOCKS_PER_SEC);








	return 0;
}