#include "sortingAlgorithms.h"

// 直接插入排序的实现

void insertion_sort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        // 将大于key的元素向后移动
        while (j >= 0 && arr[j] > key)
        {
            /* code */
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void shell_sort(int arr[], int n)
{
    //  初始化间隔gap
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        //  使用间隔gap进行插入排序
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j;

            //  对间隔为gap的元素进行插入排序
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
            }

            arr[j] = temp;
        }
    }
}
