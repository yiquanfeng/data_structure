#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>

int calculate(char* s) {
    int n =strlen(s);
    int buffer[100];
    int top = 0;
    int num = 0;
    char pretype ='+';

    for(int i = 0;i < n;++i)
    {
        if(isdigit(s[i]))
            num = num*10 + (int)(s[i] - '0');
        if(!isdigit(s[i]) && s[i] != ' ' || i == n-1)
        {
            switch (pretype)
            {
                case '+':
                    buffer[top++] = num;
                    break;
                case '-':
                    buffer[top++] = -num;
                    break;
                case '*':
                    buffer[top - 1] *= num;
                    break;
                case '/':
                    buffer[top - 1] /= num;
                    break;    
                default:
                    buffer[top - 1] = num;
                    break; 
            }
            pretype = s[i];
            num=0;
        }
    }
    int res = 0;
    for(int i = 0;i < top ; i++)
    {
        res += buffer[i];
    }
    return res;
}

int main()
{
    char s[30] = "10+42";
    printf("%d",calculate(s));
    return 0;
}