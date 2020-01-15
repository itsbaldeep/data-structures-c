#include <stdio.h>
#define swap(x, y) int t = x; x = y; y = t;

void quick_sort(int[], int, int);
int partition(int[], int, int);

void main()
{
    int arr[] = {10, 70, 30, 50, 40};
    int low = 0;
    int high = 4;

    quick_sort(arr, low, high);

    for (int i = low; i <= high; i++)
    {
        printf("%d ", arr[i]);
    }
}

void quick_sort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}
