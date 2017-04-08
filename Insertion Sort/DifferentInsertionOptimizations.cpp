#include <iostream>
#include <vector>
using namespace std;


void insertionSort          (vector<int> &arr, int start, int end);
void insertionBinarySort    (vector<int> &arr, int start, int end);
void insertionTwosSort      (vector<int> &arr, int start, int end);
void insertionBinaryTwosSort(vector<int> &arr, int start, int end);
int  recursiveLowerBound    (vector<int> &arr, int &target, int start, int end);

void insertionSort(vector<int> &arr, int start, int end) {
    for (int i = start+1; i <= end; ++i)
        if( arr[i] < arr[i-1] ) {
            int found = arr[i];
            int j = 0;
            for (j = i-1; j >= 0; --j) {
                if (arr[j] > found)
                    arr[j + 1] = arr[j];
                else
                    break;
            }
            arr[j+1] = found;
        }
}

void insertionTwosSort(vector<int> &arr, int start, int end) {
    for (int i = start + 1; i < end; i += 2) {
        int j, largeHolder, smallHolder;
        if (arr[i] > arr[i + 1]) //Swap elements so that a[i] < a[i+1]
            swap(arr[i], arr[i + 1]);
        j = i - 1;
        if (arr[i + 1] < arr[j]) {
            largeHolder = arr[i + 1];
            smallHolder = arr[i];
            for (; j >= 0; --j) {
                if (largeHolder < arr[j])
                    arr[j + 2] = arr[j];
                else
                    break;
            }
            arr[j + 1] = smallHolder;
            arr[j + 2] = largeHolder;
        }
        if (j < 0)
            continue; //Reached the end.
        if (arr[j + 1] < arr[j]) {
            smallHolder = arr[j + 1];
            for (; j >= 0; --j) {
                if (smallHolder < arr[j])
                    arr[j + 1] = arr[j];
                else
                    break;
            }
            arr[j + 1] = smallHolder;
        }
    }
    if( !((end-start+1)%2) ) //Handles the case when size is even (Iterating by 2 will terminate without sorting the last element)
    {
        int found = arr[end];
        int i = end - 1;
        for (; i >= 0; --i) {
            if (arr[i] > found)
                arr[i + 1] = arr[i];
            else
                break;
        }
        arr[i+1] = found;
    }
}

int recursiveLowerBound(vector<int> &arr, int &target, int start, int end) {
    if(start > end)
        return start;
    int mid = ( start+end ) / 2;
    if( arr[mid] >= target ) //if == target -> Keep searching for a smaller input.
        return recursiveLowerBound(arr,target,start,mid-1);
    else
        return recursiveLowerBound(arr,target,mid+1,end);
}

void insertionBinarySort(vector<int> &arr, int start, int end) {
    for (int i = start+1; i <= end; ++i)
        if( arr[i] < arr[i-1] ) {
            int found = arr[i];
            int j = 0;
            int lowerBound = recursiveLowerBound(arr,arr[i],0,i-1);
            for (j = i-1; j >= lowerBound; --j) {
                arr[j + 1] = arr[j];
            }
            arr[j+1] = found;
        }
}

void insertionBinaryTwosSort(vector<int> &arr, int start, int end) {
    for (int i = start + 1; i < end; i += 2) {
        int j, largeHolder, smallHolder;
        if (arr[i] > arr[i + 1]) //Swap elements so that a[i] < a[i+1]
            swap(arr[i], arr[i + 1]);
        j = i - 1;
        if (arr[i + 1] < arr[j]) {
            largeHolder = arr[i + 1];
            smallHolder = arr[i];
            int lowerBound = recursiveLowerBound(arr,largeHolder,0,i-1);
            for (j = i-1; j >= lowerBound; --j) {
                arr[j + 1] = arr[j];
            }
            arr[j + 1] = smallHolder;
            arr[j + 2] = largeHolder;
        }
        if (j < 0)
            continue; //Reached the end.
        if (arr[j + 1] < arr[j]) {
            smallHolder = arr[j + 1];
            int lowerBound = recursiveLowerBound(arr,smallHolder,0,i-1);
            for (j = i-1; j >= lowerBound; --j) {
                arr[j + 1] = arr[j];
            }
            arr[j + 1] = smallHolder;
        }
    }
    if( !((end-start+1)%2) )  //Handles the case when size is even (Iterating by 2 will terminate without sorting the last element)
    {
        int found = arr[end];
        int i = end - 1;
        int lowerBound = recursiveLowerBound(arr,found,start,i-1);
        for (; i >= lowerBound; --i) {
                arr[i + 1] = arr[i];
        }
        arr[i+1] = found;
    }
}
