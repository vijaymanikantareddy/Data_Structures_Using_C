//c program to implement merge sort
#include <stdio.h>
 
void mergeSort(int [], int, int, int);
void partition(int [],int, int);
 
void main()
{
    int arr[20];
    int i, n;
    printf("Enter total number of elements:");
    scanf("%d", &n);
    printf("Enter the elements:");
    for(i = 0; i < n; i++)
         scanf("%d", &arr[i]);
    partition(arr, 0, n - 1);
    printf("After merge sort: ");
    for(i = 0;i < n; i++)
         printf("%d   ",arr[i]);
}
 
void partition(int arr[],int low,int high)
{
    int mid;
    if(low < high)
    {
        mid = (low + high) / 2;
        partition(arr, low, mid);
        partition(arr, mid + 1, high);
        mergeSort(arr, low, mid, high);
    }
}
 
void mergeSort(int arr[],int low,int mid,int high)
{
    int i, mi, k, lo, temp[50];
    lo = low;
    i = low;
    mi = mid + 1;
    while ((lo <= mid) && (mi <= high))
    {
        if (arr[lo] <= arr[mi])
        {
            temp[i] = arr[lo];
            lo++;
        }
        else
        {
            temp[i] = arr[mi];
            mi++;
        }
        i++;
    }
    if (lo > mid)
        for (k = mi; k <= high; k++)
        {
            temp[i] = arr[k];
            i++;
        }
    else
        for (k = lo; k <= mid; k++)
        {
             temp[i] = arr[k];
             i++;
        }
 
    for (k = low; k <= high; k++)
        arr[k] = temp[k];
}
