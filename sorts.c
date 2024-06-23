#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{
    int Key;
    int No;
    int PrimaryKey;
} element;
int CmpTimes[5][5];
int MoveTimes[5][5];
double operationTimes[5][5];
void Swap(element *a, element *b)
{
    element tmp = *a;
    *a = *b;
    *b = tmp;
}
void CreateArray(element array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        array[i].No = 20240000 + i;
        array[i].Key = rand() % 200;
        array[i].PrimaryKey = i;
    }
}
void PrintArray(element array[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("No:%d\tPrimKey:%d\tKey:%d\t\n", array[i].No, array[i].PrimaryKey, array[i].Key);
    }
}
void BubbleSort(element array[], int length, int whichArray) // TODO:set a flag
{
    for (int i = 0; i < length; i++)
    {
        int flag = 0;
        for (int j = 0; j < length - i - 1; j++)
        {
            if (array[j].Key > array[j + 1].Key)
            {
                Swap(&array[j], &array[j + 1]);
                MoveTimes[whichArray][2]++;
                flag = 1;
            }
            CmpTimes[whichArray][2]++;

        }
        if(flag == 0)
              break;
    }
}
void InsertionSort(element array[], int length, int whichArray)
{
    for (int i = 1; i < length; i++)
    {
        int temp = array[i].Key;
        int j = 1;
        for (j = i - 1; j >= 0 ; j--)
            {
                if(array[j].Key > temp)
                {
                     array[j + 1] = array[j];
                    MoveTimes[whichArray][1]++;
                }
                else 
                {
                    CmpTimes[whichArray][1]++;
                    break;
                }
            }
        array[j + 1].Key = temp;
    }
}
void ShellSort(int array[], int length)
{
}
void SelectionSort(element array[], int length, int whichArray)
{
    for (int i = 0; i < length; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < length; j++)
        {
            if (array[j].Key < array[min_index].Key)
                min_index = j;
            CmpTimes[whichArray][3]++;
        }//find the minimum element index
        Swap(&array[i], &array[min_index]);//let the minimum element to the first position
        MoveTimes[whichArray][3]++;
    }
}
void HeapSort(int array[], int length)
{
}
void QuickSort(element array[], int length, int whichArray)
{
    int left = 0;
    int right = length - 1;
    Quick_Inside(array, left, right, whichArray);
}
int main_select(element array[], int left, int right)
{
    int mid = (left + right) / 2;
    if (array[left].Key > array[mid].Key)
        Swap(&array[left], &array[mid]);
    if (array[mid].Key > array[right].Key)
        Swap(&array[mid], &array[right]);
    if (array[left].Key > array[mid].Key)
        Swap(&array[left], &array[mid]);
    Swap(&array[mid], &array[right - 1]);
    return array[right - 1].Key;
}
void Quick_Inside(element array[], int left, int right, int whichArray)
{
    if (left >= right)
        return;
    int privot = main_select(array, left, right);
    CmpTimes[whichArray][4] += 4;
    MoveTimes[whichArray][4] += 4;
    int i = left;
    int j = right - 1;
    for (;;)
    {
        if (i == j)
            break;
        while (array[++i].Key < privot)
        {
            CmpTimes[whichArray][4]++;
        }
        while (array[--j].Key > privot)
        {
            CmpTimes[whichArray][4]++;
        }
        if (i < j)
        {
            Swap(&array[i], &array[j]);
            MoveTimes[whichArray][4]++;
        }
        else
            break;
    }
    Swap(&array[right - 1], &array[i]);
    MoveTimes[whichArray][4]++;
    // printf("%d\n",privot);
    // PrintArray(array,20);
    Quick_Inside(array, left, i - 1, whichArray);
    Quick_Inside(array, i + 1, right, whichArray);
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
    element S1[200];
    element S2[200];
    element S3[200];
    element S4[200];
    clock_t start, end;
    FILE *table_res = NULL;
    FILE *output = NULL;

    CreateArray(array, 200); // 创造一个结构体数组
    table_res = fopen("table_res.txt", "w+");
    fprintf(table_res, "this is original table S:\n");
    for (int i = 0; i < 200; i++)
    {
        fprintf(table_res, "No:%d\tPrimKey:%d\tKey:%d\t\n", array[i].No, array[i].PrimaryKey, array[i].Key);
    }
    QuickSort(array, 200, 1); // 将array进行快速排序
    memcpy(S1, array, 2400);  // 将array的数据拷贝至s1
    fprintf(table_res, "\nthis is first table S1:\n");
    for (int i = 0; i < 200; i++)
    {
        fprintf(table_res, "No:%d\tPrimKey:%d\tKey:%d\t\n", S1[i].No, S1[i].PrimaryKey, S1[i].Key);
    }
    for (int i = 0; i < 200; i++)
        S2[200 - 1 - i] = S1[i];
    fprintf(table_res, "\nthis is second table S2:\n");
    for (int i = 0; i < 200; i++)
        fprintf(table_res, "No:%d\tPrimKey:%d\tKey:%d\t\n", S2[i].No, S2[i].PrimaryKey, S2[i].Key);
    for (int i = 0; i < 100; i++) // 将S1分成两份，随机放在S3的各个部分中
    {
        S3[i] = S1[200 - 1 - i];
        S3[i + 100] = S1[i];
    }
    fprintf(table_res, "\nthis is third table S3:\n");
    for (int i = 0; i < 200; i++)
        fprintf(table_res, "No:%d\tPrimKey:%d\tKey:%d\t\n", S3[i].No, S3[i].PrimaryKey, S3[i].Key);
    for (int i = 0; i < 50; i++) // 将S1分成四份，随机放在S4的各个部分中
    {
        S4[i] = S1[200 - 1 - i];
        S4[i + 50] = S1[i];
        S4[i + 100] = S1[i + 50];
        S4[i + 150] = S1[i + 100];
    }
    fprintf(table_res, "\nthis is fourth table S4:\n");
    for (int i = 0; i < 200; i++)
        fprintf(table_res, "No:%d\tPrimKey:%d\tKey:%d\t\n", S4[i].No, S4[i].PrimaryKey, S4[i].Key);
    fclose(table_res);
    printf("\n");
    output = fopen("output.info", "w+");
    start = clock();
    for (int i = 0; i < 1000; i++)
        InsertionSort(S1, 200, 1);
    end = clock();
    operationTimes[1][1] = (double)(end - start) / CLOCKS_PER_SEC / 1000;
    element tmp2_1[200];
    memcpy(tmp2_1,S2,2400);
    start = clock();
    for (int i = 0; i < 1000; i++)
        InsertionSort(tmp2_1, 200, 2);
    end = clock();
    operationTimes[2][1] = (double)(end - start) / CLOCKS_PER_SEC / 1000;
    element tmp3_1[200];
    memcpy(tmp3_1,S3,2400);
    start = clock();
    for (int i = 0; i < 1000; i++)
        InsertionSort(tmp3_1, 200,3);
    end = clock();
    operationTimes[3][1] = (double)(end-start)/CLOCKS_PER_SEC/1000;
    element tmp4_1[200];
    memcpy(tmp4_1,S4,2400);
    start = clock();
    for (int i = 0; i < 1000; i++)
        InsertionSort(tmp4_1, 200,4);
    end = clock();
    operationTimes[4][1] = (double)(end-start)/CLOCKS_PER_SEC/1000;
    start = clock();
    for (int i = 0; i < 1000; i++)
        BubbleSort(S1,200,1);
    end = clock();
    operationTimes[1][2] = (double)(end-start)/CLOCKS_PER_SEC/1000;
    element tmp2_2[200];
    memcpy(tmp2_2,S2,2400);
    start = clock();
    for (int i = 0; i < 1000; i++)
        BubbleSort(tmp2_2,200,2);
    end = clock();
    operationTimes[2][2] = (double)(end-start)/CLOCKS_PER_SEC/1000;

    element tmp3_2[200];
    memcpy(tmp3_2,S3,2400);
    start = clock();
    for (int i = 0; i < 1000; i++)
        BubbleSort(tmp3_2,200,3);
    end = clock();
    operationTimes[3][2] = (double)(end-start)/CLOCKS_PER_SEC/1000;

    element tmp4_2[200];
    memcpy(tmp4_2,S4,2400);
    start = clock();
    for (int i = 0; i < 1000; i++)
        BubbleSort(tmp4_2,200,4);
    end = clock();
    operationTimes[4][2] = (double)(end-start)/CLOCKS_PER_SEC/1000;

    start = clock();
    for (int i = 0; i < 1000; i++)
        SelectionSort(S1,200,1);
    end = clock();
    operationTimes[1][3] = (double)(end-start)/CLOCKS_PER_SEC/1000;

    element tmp2_3[200];
    memcpy(tmp2_3,S2,2400);
    start = clock();
    for (int i = 0; i < 1000; i++)
        SelectionSort(tmp2_3,200,2);
    end = clock();
    operationTimes[2][3] = (double)(end-start)/CLOCKS_PER_SEC/1000;
    element tmp3_3[200];
    memcpy(tmp3_3,S3,2400);
    start = clock();
    for (int i = 0; i < 1000; i++)
        SelectionSort(tmp3_3,200,3);
    end = clock();
    operationTimes[3][3] = (double)(end-start)/CLOCKS_PER_SEC/1000;
    element tmp4_3[200];
    memcpy(tmp4_3,S4,2400);
    start = clock();
    for (int i = 0; i < 1000; i++)
        SelectionSort(tmp4_3,200,4);
    end = clock();
    operationTimes[4][3] = (double)(end-start)/CLOCKS_PER_SEC/1000;
    start = clock();
    for (int i = 0; i < 1000; i++)
        QuickSort(S1,200,1);
    end = clock();
    operationTimes[1][4] = (double)(end-start)/CLOCKS_PER_SEC/1000;
    element tmp2_4[200];
    memcpy(tmp2_4,S2,2400);
    start = clock();
    for (int i = 0; i < 1000; i++)
        QuickSort(tmp2_4,200,2);
    end = clock();
    operationTimes[2][4] = (double)(end-start)/CLOCKS_PER_SEC/1000;

    element tmp3_4[200];
    memcpy(tmp3_4,S3,2400);
    start = clock();
    for (int i = 0; i < 1000; i++)
        QuickSort(tmp3_4,200,3);
    end = clock();
    operationTimes[3][4] = (double)(end-start)/CLOCKS_PER_SEC/1000;
    
    element tmp4_4[200];
    memcpy(tmp4_4,S4,2400);
    start = clock();
    for (int i = 0; i < 1000; i++)
        QuickSort(tmp4_4,200,4);
    end = clock();
    operationTimes[4][4] = (double)(end-start)/CLOCKS_PER_SEC/1000;

    fprintf(output, "this is compare times\n");
    fprintf(output, "\tA1\t\tA2\t\tA3\t\tA4\n");
    fprintf(output, "S1 :%d\t\t%d\t\t%d\t\t%d\n", CmpTimes[1][1], CmpTimes[1][2], CmpTimes[1][3], CmpTimes[1][4]);
    fprintf(output, "S2 :%d\t\t%d\t\t%d\t\t%d\n", CmpTimes[2][1], CmpTimes[2][2], CmpTimes[2][3], CmpTimes[2][4]);
    fprintf(output, "S3 :%d\t\t%d\t\t%d\t\t%d\n", CmpTimes[3][1], CmpTimes[3][2], CmpTimes[3][3], CmpTimes[3][4]);
    fprintf(output, "S4 :%d\t\t%d\t\t%d\t\t%d\n", CmpTimes[4][1], CmpTimes[4][2], CmpTimes[4][3], CmpTimes[4][4]);
    fprintf(output, "\n");
    fprintf(output, "this is move times\n");
    fprintf(output, "\tA1\t\tA2\t\tA3\t\tA4\n");
    fprintf(output, "S1 :%d\t\t%d\t\t%d\t\t%d\n", MoveTimes[1][1], MoveTimes[1][2], MoveTimes[1][3], MoveTimes[1][4]);
    fprintf(output, "S2 :%d\t\t%d\t\t%d\t\t%d\n", MoveTimes[2][1], MoveTimes[2][2], MoveTimes[2][3], MoveTimes[2][4]);
    fprintf(output, "S3 :%d\t\t%d\t\t%d\t\t%d\n", MoveTimes[3][1], MoveTimes[3][2], MoveTimes[3][3], MoveTimes[3][4]);
    fprintf(output, "S4 :%d\t\t%d\t\t%d\t\t%d\n", MoveTimes[4][1], MoveTimes[4][2], MoveTimes[4][3], MoveTimes[4][4]);
    fprintf(output, "\n");
    fprintf(output, "this is operation times\n");
    fprintf(output, "\tA1\t\tA2\t\tA3\t\tA4\n");
    fprintf(output, "S1 :%lf\t\t%lf\t\t%lf\t\t%lf\n", operationTimes[1][1], operationTimes[1][2], operationTimes[1][3], operationTimes[1][4]);
    fprintf(output, "S2 :%lf\t\t%lf\t\t%lf\t\t%lf\n", operationTimes[2][1], operationTimes[2][2], operationTimes[2][3], operationTimes[2][4]);
    fprintf(output, "S3 :%lf\t\t%lf\t\t%lf\t\t%lf\n", operationTimes[3][1], operationTimes[3][2], operationTimes[3][3], operationTimes[3][4]);
    fprintf(output, "S4 :%lf\t\t%lf\t\t%lf\t\t%lf\n", operationTimes[4][1], operationTimes[4][2], operationTimes[4][3], operationTimes[4][4]);
    fclose(output);
    return 0;
}