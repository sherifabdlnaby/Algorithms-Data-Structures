//
// Created by Sherif on 3/3/2017.
//

#ifndef MERGESORT_MERGE_H
#define MERGESORT_MERGE_H
//STD::FUNCTION //TODO

template <class T>
bool cmpDefault(T x, T y)
{
    return x < y;
}

template<class T>
void insertionSort(T arr[],int start, int end, bool (*cmp)(T,T) = cmpDefault)
{
    T found;
    int j;
    for (int i = start+1; i <= end; ++i){
        if( cmp(arr[i],arr[i-1]) )
        {
            found = arr[i];
            j = 0;
            for (j = i-1; j >= start; --j) {
                if( cmp(found,arr[j]) )
                    arr[j+1] = arr[j];
                else break;
            }
            arr[j+1] = found;
        }
    }
}

template<class T>
void mergeArrays(T arr[],int start, int end, int mid, bool (*cmp)(T,T) = cmpDefault)
{
    int n = end-start+1;
    int idx1 = start;
    int idx2 = mid+1;
    T *cpyArr = new T[n];
    for (int i = 0; i < n; ++i)
    {
        if (idx1 > mid)
            cpyArr[i] = arr[idx2++];
        else if (idx2 > end)
            cpyArr[i] = arr[idx1++];
        else if (cmp(arr[idx1],arr[idx2]))
            cpyArr[i] = arr[idx1++];
        else
            cpyArr[i] = arr[idx2++];
    }
    int j = 0;
    for(int i=start; i<=end; i++)
        arr[i] = cpyArr[j++];

    return;
}

template<class T>
void mergeSort(T arr[], int start, int end, bool (*cmp)(T,T) = cmpDefault)
{
    if(end <= start)
        return;
    else
    {
        int mid = (start + end)/2;
        mergeSort(arr,start,mid,cmp);
        mergeSort(arr,mid+1,end,cmp);
        mergeArrays(arr,start,end,mid,cmp);
    }
    return;
}

template<class T>
void mergeSortOpt(T arr[], int start, int end, bool (*cmp)(T,T) = cmpDefault)
{
    if(end <= start)
        return;
    else if( end-start < 41 )
        insertionSort(arr,start,end,cmp);
    else
    {
        int mid = (start + end)/2;
        mergeSort(arr,start,mid,cmp);
        mergeSort(arr,mid+1,end, cmp);
        mergeArrays(arr,start,end,mid,cmp);
    }
    return;
}


#endif //MERGESORT_MERGE_H
