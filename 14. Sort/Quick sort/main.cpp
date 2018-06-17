//
//  main.cpp
//  QuickSort
//
//  Created by Daojing Zhai on 2018/6/17.
//  Copyright © 2018 Daojing Zhai. All rights reserved.
//

#include <iostream>
const int MAXSIZE = 100;
int Array[MAXSIZE];
using namespace std;int Partition(int low, int high){
    int pivotpos = low;
    int pivot = Array[low];
    for (int i=low+1; i<=high; i++) {
        if (Array[i]<pivot) {
            pivotpos++;
            if (pivotpos!=i) {
                int temp = Array[pivotpos];
                Array[pivotpos] = Array[i];
                Array[i] = temp;
            }
        }
    }
    Array[low] = Array[pivotpos];
    Array[pivotpos] = pivot;
    return pivotpos;
}


void QuickSort(int left, int right){
    if (left<right) {
        int pivotpos = Partition(left, right);
        QuickSort(left, pivotpos-1);
        QuickSort(pivotpos+1, right);
    }
    return;
}




int main() {
    int inputSize = 10;
    for (int i=0; i<inputSize; i++) {
        cin>>Array[i];
    }
    QuickSort(0, inputSize-1);
    for (int l=0; l<inputSize; l++) {
        cout<<Array[l]<<' ';
    }
    cout<<endl;
    return 0;
}
