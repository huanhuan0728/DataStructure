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

//   11月13日重复练习
void inserttion_sort_2(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        // 将大于key的元素向右移动
        while (j >= 0 && arr[j] > key)
        {
            /* code */
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// 11月15
void inserttion_sort_3(int arr[].int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        for (j; j >= 0; j++)
        {
            // 把大于key的元素右移
            while (arr[j] >= key && j >= 0)
            {
                arr[j + 1] = arr[j];
                j -= i;
            }

            arr[j + 1] = key;
        }
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

// 11月3第二次练习
void shell_sort_2(int arr[], int n)
{
    //  初始化gap
    for (int gap = n / 2; gap > 0; gap /= 2)
    {

        // 对间隔gap的子序列进行插入排序
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j;

            // 对间隔为gap的元素进行插入排序
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

// 11月15
void shell_sort_3(int arr[], int n)
{
    //  初始化gap
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        // 对间隔为gap的子序列进行插入排序
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j;

            // 对间隔为gap的元素进行插入排序
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

void quick_sort(int arr[], int low, int high)
{
    if (low < high)
    {
        //  分区操作，返回基准元素的索引
        int pivot_index = partition(arr, low, high);

        // 递归的对基准元素的左右的子数组进行快速排序
        quick_sort(arr, low, pivot_index - 1);
        quick_sort(arr, pivot_index + 1, high);
    }
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // 选择最右边的元素为基准
    int i = low - 1;       // i是较小元素的索引

    for (int j = low, j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            // 交换arr[i]和arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // 把基准元素放到正确的位置
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

// 11月15练习
int parttion_2(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low, j < high; i++)
    {
        if (arr[j] < pivot)
        {
            i++;
            // 交换arr[i]和arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    //  把基准元素放到正确的位置
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}
