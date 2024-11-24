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

void insettion_sort1118(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        // 将大于key的元素后移
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// 11月15
void inserttion_sort_3(int arr[], int n)
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

void shell_sort_4(int arr[], int n)
{
    // 初始化gap
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j;

            // 对间隔为gap的子序列进行插入排序 4 5 6 7 8 9 5 2 3
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
/*
// 11月15练习
int partition_2(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; i++)
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

int partition_3(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; i++)
    {
        if (arr[j] < pivot)
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

*/

int partion_4(int arr[], int low, int high)
{
    int pivot = arr[high]; // 选择最右边的元素为基准
    int i = low - 1;       // i是较小元素的指引

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            // 交换arr[i]和arr[j]
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }

    // 把基准元素放到正确的位置
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

// 堆调整，使得index为根节点的子树成为最大堆
void heapify(int arr[], int n, int index)
{
    int largest = index; // 假设当前节点是最大值
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    // 检查左节点是否比根节点大
    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }

    // 检查右节点是否比根节点大
    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    // 如果最大值不是根节点，交换位置并递归调整子树
    if (largest != index)
    {
        int temp = arr[index];
        arr[index] = arr[largest];
        arr[largest] = temp;

        // 递归调整子树
        heapify(arr, n, largest);
    }
}

void head_sort(int arr[], int n)
{
    // 构建最大堆（从最后一个非叶子节点开始）
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    // 逐步将堆顶元素移到数组末尾，并重新调整堆
    for (int i = n - 1; i > 0; i--)
    {
        //  将堆顶（最大值）与当前末尾元素交换
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // 重新调整堆，范围是[0, i-1]
        heapify(arr, i, 0);
    }
}

// 11月18日堆排序练习
void headpify1118(int arr[], int n, int index)
{
    int largest = index; // 假设当前节点是最大值
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    // 检查左子节点是否比根节点大
    if (left < n && arr[left] > arr[largest])
    {
        /* code */
        largest = left;
    }

    // 检查右子节点是否比当前节点大
    if (right < n && arr[right] > arr[largest])
    {
        /* code */
        largest = right;
    }

    if (largest != index)
    {
        /* code */
        int temp = arr[index];
        arr[index] = arr[largest];
        arr[largest] = temp;

        headpify(arr, n, largest);
    }
}

void heap_sort1118(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        headpify1118(arr, n, i);
    }

    // 逐步将堆顶元素移到数组末尾，并重新调整堆
    for (int i = n - 1; i > 0; i--)
    {
        // 将堆顶元素（最大值）和当前末尾元素交换
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // 重新调整堆
        headpify1118(arr, i, 0);
    }
}

void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1; // 左数组大小
    int n2 = right - mid;    // 右数组大小

    // 创建临时数组
    int L[n1], R[n2];

    // 拷贝数据到临时数组
    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = arr[mid + 1 + j];
    }

    // 合并临时数组到arr
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i++];
        }
        else
        {
            arr[k] = R[j++];
        }

        k++;
    }

    // 拷贝剩余数组
    while (i < n1)
    {
        arr[k++] = L[i++];
    }

    while (j < n2)
    {
        arr[k++] = R[j++];
    }
}

void merge_sort(int arr[], int left, int right)
{
    if (left < right)
    {
        // 找到中点
        int mid = left + (right - left) / 2;

        // 递归对左右两部分进行排序
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        // 合并已排序部分
        merge(arr, left, mid, right);
    }
}
