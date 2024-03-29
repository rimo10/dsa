#include <iostream>
#include <vector>
using namespace std;
void printarr(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int Partition(vector<int> &arr, int lb, int ub)
{
    int pivot = arr[lb];
    int start = lb;
    int end = ub;
    while (start < end)
    {
        while (arr[start] <= pivot)
        {
            start++;
        }
        while (arr[end] > pivot)
        {
            end--;
        }
        if (start < end)
        {
            printarr(arr);
            swap(arr[start], arr[end]);
            printarr(arr);
        }
        printarr(arr);
    }
    swap(arr[lb], arr[end]);
    printarr(arr);
    return end;
}
int PartitionEnd(vector<int> &arr, int lb, int ub)
{
    int pivot = arr[ub];
    int i = (lb - 1);
    for (int j = lb; j <= ub - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[ub]);
    return (i + 1);
}
void QuickSort(vector<int> &arr, int lb, int ub)
{
    if (lb < ub)
    {
        int idx = Partition(arr, lb, ub);
        QuickSort(arr, lb, idx - 1);
        QuickSort(arr, idx + 1, ub);
    }
}
int main()
{
    // vector<int> arr = {7, 6, 10, 5, 9, 2, 1, 34, 15, 8};
    vector<int> arr = {6, 9, 10, 5};
    int lb = 0, ub = arr.size() - 1;
    QuickSort(arr, lb, ub);
    for (int i = 0; i <= ub; i++)
    {
        cout << arr[i] << " ";
    }
}
