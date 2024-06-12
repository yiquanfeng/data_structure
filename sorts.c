#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int Key;
    int No;
    int PrimaryKey;
} element;

void Swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void CreateArray(element array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        array[i].No = 20240000 + rand()%100;
    }
}
void PrintArray(int array[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d\t", array[i]);
    }
}
void BubbleSort(int array[], int length) // TODO:set a flag
{
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length - i - 1; j++)
        {
            if (array[j] > array[j + 1])
                Swap(&array[j], &array[j + 1]);
        }
    }
}
void InsertionSort(int array[], int length)
{
    for (int i = 1; i < length; i++)
    {
        int temp = array[i];
        int j = 1;
        for (j = i - 1; j >= 0 && array[j] >= temp; j--)
            array[j + 1] = array[j];
        array[j + 1] = temp;
    }
}
void ShellSort(int array[], int length)
{

}
void SelectionSort(int array[], int length)
{
    for(int i = 0;i < length;i++)
    {
        int min_index = i;
        for(int j = i+1;j < length;j++)
        {
            if(array[j] < array[min_index])
                min_index = j; 
        }
        Swap(&array[i],&array[min_index]);
    }
}
void HeapSort(int array[], int length)
{
}
void QuickSort(int array[], int length)
{
    int left = 0;
    int right = length - 1;
    Quick_Inside(array,left,right);
}
int main_select(int array[],int left,int right)
{
    int mid = (left + right) / 2;
    if(array[left] > array[mid])
        Swap(&array[left],&array[mid]);
    if(array[mid] > array[right])
        Swap(&array[mid],&array[right]);
    if(array[left] > array[mid])
        Swap(&array[left],&array[mid]);
    Swap(&array[mid],&array[right-1]);
    return array[right-1];
}
void Quick_Inside(int array[],int left,int right)
{
    if(left >= right) 
    {
        return;
    }
    int privot = main_select(array,left,right);
    int i = left;
    int j = right -1;
    for(;;)
    {
        if(i == j) break;
        while(array[++i] < privot){}
        while(array[--j] > privot){}
        if(i < j)
                Swap(&array[i],&array[j]);
        else break;
    }
    Swap(&array[right-1],&array[i]);
    // printf("%d\n",privot);
    // PrintArray(array,20);
    Quick_Inside(array,left,i-1);
    Quick_Inside(array,i+1,right);
}
void MergeSort(int array[], int length)
{
}
void Merge()
{
}
int main()
{
    element array[200];
    clock_t start, end;
    FILE* output = NULL;

    CreateArray(array, 200);
    PrintArray(array, 20);
    printf("\n");
    start = clock();
    for (int i = 0; i < 10000; i++)
    {
        // InsertionSort(array, 20);
        // BubbleSort(array,20);
        // SelectionSort(array,20);
        QuickSort(array,20);
    }
    end = clock();
    printf("time:%10.20f secs\n", (double)(end - start) / CLOCKS_PER_SEC/10000);
    PrintArray(array, 20);
    output = fopen("output.info",'w+');

    fclose(output);
    return 0;
}

// 直接插入，折半插入，冒泡，快排，简单选择，二路归并
// 对算法的稳定性和复杂度分析