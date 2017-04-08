//
// Created by Sherif on 3/27/2017.
//

void partialSort(vector<int> &arr, int left, int right, int k);          //Sort the first k-th elements.
int  partition(vector<int> &arr, int left, int right) ;                  //Random Pivot

void partialSort(vector<int> &arr, int left, int right, int k) {
    if (left < right)//if range is > 2
    {
        int pivot = partition(arr, left, right);                //Partition around a Pivot, Returns Pivot's position.
        if (pivot >= k) {
            if (left < pivot - 1)
                partialSort(arr, left, pivot - 1, k);           //Recursively partition to the left.
        }
        else {
            if (left < pivot - 1)
                partialSort(arr, left, pivot - 1, k);           //Recursively partition to the left.
            if (right > pivot + 1)
                partialSort(arr, pivot + 1, k, k);              //Recursively partition to the right till the k-th element.
        }
    }
    return;
}

int partition(vector<int> &arr, int left, int right)//Random Pivot avg of n*log(n);
{
    int pivotIdx = rand() % (right - left) + left; //pick a random pivot of range(left ~ right-1).
    int pivot = arr[pivotIdx];                     // pivot value;
    int i = left;                                  // Index of smaller elements
    int j = right-1;
    swap(arr[pivotIdx], arr[right]);               //put the pivot at the end.
    while (i <= j){
        while(arr[i] <= pivot && i <= j)
            ++i;
        while(arr[j] >  pivot && i <= j)
            --j;
        if(i < j)
            swap(arr[i],arr[j]);
    }
    swap(arr[i], arr[right]);                      //put pivot element int its position
    return i;                                      //Return pivot position
}
