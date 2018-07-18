//
//  main.cpp
//  HeapSort
//
//  Created by Daojing Zhai on 2018/6/18.
//  Copyright © 2018 Daojing Zhai. All rights reserved.
//

#include <iostream>
const int MAXSIZE = 100;
using namespace std;
int Array[MAXSIZE];

void SiftDown(const int start, const int end){
    // from start to end, make sure Array[start] in the right place.
    int i = start;
    int j = 2*i+1; // j is leftChild of i.
    int temp = Array[i];
    while (j <= end) {
        if (j < end && Array[j] < Array[j+1]) j++;
        if (temp >= Array[j]) break;
        else{
            Array[i] = Array[j];
            i = j;
            j = 2*j+1;
        }
    }
    Array[i] = temp;
    return;
}


void HeapSort(const int inputSize){
    //  HeapSort algorithm. Every iter build a max heap, and place
    //  the top node to the tail of heap;
    int i;
    //  build max heap;
    for (i=(inputSize-2)/2; i>=0; i--)
        SiftDown(i, inputSize-1);
    for (i=inputSize-1; i>=0; i--){
        int temp = Array[i];
        Array[i] = Array[0];
        Array[0] = temp;
        SiftDown(0, i-1);
    }
    for (int i=0; i<inputSize; i++) {
        cout<<Array[i]<<' ';
    }
    cout<<endl;
    return;
}

int main() {
    int inputSize = 10;
    for (int i=0; i<inputSize; i++) {
        cin>>Array[i];
    }
    HeapSort(inputSize);
    return 0;
}
