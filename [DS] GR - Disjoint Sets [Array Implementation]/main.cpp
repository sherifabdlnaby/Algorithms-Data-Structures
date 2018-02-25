#include <iostream>
#include "disjointsets.h"

using namespace std;

int main() {
    int noOfSets;
    cout << "Enter Number of Sets: " << endl;
    cin >> noOfSets;

    DisjointSets disjointSets(noOfSets);

    int choice = -1;
    while(choice != 0)
    {
        cout << "1- Union\n2- Find\n0- Exit\nEnter choice: " << endl;
        cin >> choice;
        if(choice == 1)
        {
            int i, j;
            cout << "Please enter pairs (i,j) of sets you want to union separated by space: " << endl;
            cin >> i >> j;
            cout << (disjointSets.Union(i,j) ? "Success" : "Already Unioned") << endl;
        }
        else if(choice == 2){
            int i;
            cout << "Please enter set id:" << endl;
            cin >> i;
            cout << i << " representative (root) is : " << disjointSets.Find(i);
        }
        else if(choice == 0)
            break;
    }
}