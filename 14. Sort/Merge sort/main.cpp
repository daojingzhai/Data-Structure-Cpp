//
//  main.cpp
//  MergeSort
//
//  Created by Daojing Zhai on 2018/6/17.
//  Copyright © 2018 Daojing Zhai. All rights reserved.
//


#include <iostream>
const int MAXSIZE = 100;
using namespace std;


void Merge(int (&Array1)[MAXSIZE], int (&Array2)[MAXSIZE], int left, int mid, int right){
    //  Merge Array1[left ... mid] and Array1[mid+1 ... right], store in Array2[];
    int i = left;
    int j = mid+1;
    int k = left;
    while (i <= mid && j<= right) {
        if (Array1[i] <= Array1[j]) {
            Array2[k] = Array1[i];
            i++;
        }
        else{
            Array2[k] = Array1[j];
            j++;
        }
        k++;
    }
    while (i <= mid) {
        Array2[k] = Array1[i];
        k++;
        i++;
    }
    while (j <= right) {
        Array2[k] = Array1[j];
        j++;
        k++;
    }
    return;
}


void MergePass(int (&Array1)[MAXSIZE], int (&Array2)[MAXSIZE], int len, int inputSize){
    //  Merge Array1 each len with its neighbor; Store in Neighbor;
    int i = 0;
    int j;
    while (i + 2*len < inputSize) {
        Merge(Array1, Array2, i, i+len-1, i+2*len-1);
        i = i+2*len;
    }
    if (i+len < inputSize) {
        Merge(Array1, Array2, i, i+len-1, inputSize-1);
    }
    else{
        for (j=i; j<inputSize; j++)
            Array2[j] = Array1[j];
    }

    return;
}

void MergeSort(int (&Array1)[MAXSIZE], int inputSize){
    //    MergeSort Algorithm;
    int len = 1;
    int Array2[MAXSIZE];
    while (len < inputSize) {
        MergePass(Array1, Array2, len, inputSize);
        len = len*2;
        MergePass(Array2, Array1, len, inputSize);
        len = len*2;
    }
    for (int i=0; i<inputSize; i++) {
        cout<<Array1[i]<<' ';
    }
    cout<<endl;
    return;
}


int main() {
    int inputSize = 10;
    int Array[MAXSIZE];
    for (int i=0; i<inputSize; i++) {
        cin>>Array[i];
    }
    MergeSort(Array, inputSize);
    return 0;
}
