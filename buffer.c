//表示多项式的构成
//第一种使用单纯数组，下标表示次方，存储的值表示系数
#include <stdio.h>
#include <stdbool.h>

void odd_even_sort(int arr[], int n) {
    bool isSorted = false;
    while (!isSorted) {
        isSorted = true;
        // 奇数位置比较
        for (int i = 1; i < n; i += 2) {
            if (arr[i] < arr[i - 1]) {
                int temp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = temp;
                isSorted = false;
            }
        }
        // 偶数位置比较
        for (int i = 2; i < n; i += 2) {
            if (arr[i] < arr[i - 1]) {
                int temp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = temp;
                isSorted = false;
            }
        }
    }
}
void bidirectional_bubble_sort(int arr[], int n) {
    for (int i = 0; i < n / 2; i++) {
        // 从左到右冒泡
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        // 从右到左冒泡
        for (int j = n - 2; j > i; j--) {
            if (arr[j] < arr[j - 1]) {
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
    }
}
int main() {
    int arr[] = {5, 2, 9, 1, 7, 3, 8, 4, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    odd_even_sort(arr, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

 //线性表的顺序存储的各种操作实现
 //insert a value into the array
 //delete a value
 //线性表的链式存储的各种操作实现**比较重要，后面经常使用
 //calculate the length of the linked list
 //look for a element  Kth or the value
//insert a element
//delete a element
//广义表 表示二元多项式  用代码实现一下
//使用十字链表表示矩阵


//后缀表达式
//堆栈的LIFO，并手动排序，列出可能性
//栈的顺序存储
//出栈入栈 公用数组
//the linked storage of the stack
//the operation of this linked storage
//将中缀表达式转换成后缀表达式，并且运算
//感觉可以编写一个计算器的程序，以前觉得这个简单，现在看起来没那么简单
//堆栈的其他应用，函数调用，递归实现（需要了解），深度优先算法，回溯算法，迷宫吗
//队列的FIFO还有各种operation
//顺序存储和链式存储的实现
