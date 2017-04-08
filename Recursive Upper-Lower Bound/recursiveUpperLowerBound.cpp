#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int recursiveLowerBound(vector<int> &arr, int &target, int start, int end);
int recursiveUpperBound(vector<int> &arr, int &target, int start, int end);

int main() {

    int n,value; // size - Lower/Upper.
    cout << "Enter your list Size: " << endl;
    cin >> n;  vector<int> v(n);
    cout << "Enter your list: " << endl;
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    sort(v.begin(),v.end()); //Sort the list.
    cout<< "Enter The Value: " << endl;
    cin >> value;

    cout << "lower_bound at position "  << recursiveLowerBound(v, value, 0, v.size() - 1) << endl;
    cout << "upper_bound at position "  << recursiveUpperBound(v, value, 0, v.size() - 1) << endl;
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

int recursiveUpperBound(vector<int> &arr, int &target, int start, int end) {
    if(start > end)
        return start;
    int mid = ( start+end ) / 2;
    if( arr[mid] <= target ) //if == target -> Keep searching for a larger input.
        return recursiveUpperBound(arr,target,mid+1,end);
    else
        return recursiveUpperBound(arr,target,start,mid-1);

}