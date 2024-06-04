#include <stdio.h>
#include <time.h>
#include <math.h>
#define MAXK 1e8
clock_t start,stop;
double duration;
double f1(double x,int n,int a[])
{
    double p = a[0];
    for(int i = 0;i < n;i++)
    {
        p = p + (a[i]*pow(x,i));
    }
    return p;

}
double f2(double x,int n,int a[])
{
    double p = a[n-1];
    for(int i = n-2;i >= 0;i--)
    {
        p = a[i]+p*x;
    }
    return p;
}
int a[10];
int main()
{
    for(int i = 0;i < 10;i++)
    {
        a[i] = i;
    }
    double x = 1.1;
    start = clock();
    for(int i=0;i<=MAXK;i++)
    {
        f1(x,10,a); 
    }
    stop = clock();
    duration = ((double)(stop - start))/CLK_TCK/MAXK;
    printf("this is the time of f1:%6.2e s\n",duration);
    start = clock();
    for(int i=0;i<=MAXK;i++)
    {
        f2(x,10,a); 
    }
    stop = clock();
    duration = ((double)(stop - start))/CLK_TCK/MAXK;
    printf("this is the time of f2:%6.2e s\n",duration);

}