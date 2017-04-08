//
// Created by Sherif on 3/27/2017.
//
#include <cstdlib>
#include <vector>

using namespace std;

int  partition(vector<int> &arr, int left, int right);
int  quickSelect(vector<int> &arr, int left, int right, int order);

//Select the K-th(order) smallest element, for largest or another sorting use cmp() in partition... 
int quickSelect(vector<int> &arr, int left, int right, int order)
{
    if (left < right)//if range is > 2
    {
        int pivot = partition(arr, left, right);                           //Partition around a Pivot, Returns Pivot's position.
        if(pivot == order)
            return arr[pivot];
        if(pivot > order)
            return quickSelect(arr, left, pivot - 1, order);
        else
            return quickSelect(arr, pivot + 1, right, order);
    }
    return arr[order];
}


int partition(vector<int> &arr, int left, int right)
{
    int pivotIdx = rand() % (right - left) + left;	//pick a random pivot of range(left ~ right-1).
    int pivot = arr[pivotIdx];                    	// pivot value;
    int i = left;                                 	// Index of smaller elements
    int j = right-1;
    swap(arr[pivotIdx], arr[right]);              	//put the pivot at the end.
    while (i <= j){
        while(arr[i] <= pivot && i <= j)
            ++i;
        while(arr[j] >  pivot && i <= j)
            --j;
        if(i < j)
            swap(arr[i],arr[j]);
    }
    swap(arr[i], arr[right]);						//put pivot element int its position
    return i;                                     	//Return pivot position
}
