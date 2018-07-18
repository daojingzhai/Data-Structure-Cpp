//
//  main.cpp
//  InsertSort
//
//  Created by Daojing Zhai on 2018/6/17.
//  Copyright © 2018 Daojing Zhai. All rights reserved.
//

#include <iostream>
const int MAXSIZE = 100;
int Array[MAXSIZE];
using namespace std;
void InsertSort(int left, int right){
    int i,j,temp;
    for (i=left+1; i<=right; i++) {
        if (Array[i]<Array[i-1]) {
            temp = Array[i];
            j = i-1;
            while (j>=left && temp<Array[j]) {
                Array[j+1] = Array[j];
                j--;
            }
            Array[j+1] = temp;
        }
    }
    for (int l=0; l<=right; l++) {
        cout<<Array[l]<<' ';
    }
    cout<<endl;
}


int main() {
    int inputSize = 10;
    for (int i=0; i<inputSize; i++) {
        cin>>Array[i];
    }
    InsertSort(0, inputSize-1);
    return 0;
}
