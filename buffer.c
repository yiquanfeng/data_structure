//表示多项式的构成
//第一种使用单纯数组，下标表示次方，存储的值表示系数
#include <stdio.h>
#define max 10

double function1(double x,int n,int a[])
{
    if(n == 0)
    {
        printf("error!there is a mistake number input.\n");
        return 1;
    }
    int p = a[n-1];
    for(int i = n-2;i >= 0;i--)
    {
        p = a[i]+p*x;
    }
    return p;
}
//第二种方法存储一个多项式的数据
//创建一个结构数组，其中有两个参数，一个是指数，一个是系数
struct array{
    double xishu;
    int zhishu;  
};

double function2(double x,int n,struct array* a[])
{
    
}
int main()
{
    int a[max];
    struct array arr[max];
    for(int i = 0;i < max;i++)
    {
        a[i] = i ;
    }
    printf("%f",function1(1.1,max,a));
    return 0;
}