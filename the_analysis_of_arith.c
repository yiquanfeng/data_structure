#include <stdio.h>
#include <time.h>


int main(){

    time_t start = 0,end = 0;
    double time_sum = 0.0;

    start = clock();
    //loop your code here
    end = clock();
    time_sum = (double)(end - start)/CLOCKS_PER_SEC;//if you loop your code,you are supposed to divide the loop time here
    printf("the time your code consume:%lf seconds",time_sum);
}