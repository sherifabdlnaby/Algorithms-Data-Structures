//
// Created by Sherif on 3/3/2017.
//

#ifndef BINARY_VS_LINEAR_SEARCH_BINARYLINEARSEARCH_H
#define BINARY_VS_LINEAR_SEARCH_BINARYLINEARSEARCH_H

bool linearSearch(int *arr, int target, int start, int end) {
    for (int i = start; i <= end; ++i)
    {
        if (arr[i] == target)
            return true;
    }
    return false;
}

bool binarySearch(int *arr, int target, int start, int end) {
    while (start <= end) {
        int mid = (start + end) / 2; //May overflow(int) if array is too big (use long long instead).
        if (arr[mid] == target)
            return true;
        else if (arr[mid] < target)
            start = mid + 1;
        else if (arr[mid] > target)
            end = mid - 1;
    }
    return false; //NOT FOUND
}

bool recursiveBinarySearch(int *arr, int target, int start, int end) {
    if(start > end)
        return false;
    int mid = ( start+end ) / 2; //May overflow(int) if array is too big (use long long instead).
    if (arr[mid] == target)
        return true;
    else if( arr[mid] > target )
        return recursiveBinarySearch(arr,target,start,mid-1);
    else
        return recursiveBinarySearch(arr,target,mid+1,end);
}


#endif //BINARY_VS_LINEAR_SEARCH_BINARYLINEARSEARCH_H
