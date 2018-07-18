//
//  main.cpp
//  SelectSort
//
//  Created by Daojing Zhai on 2018/6/17.
//  Copyright © 2018 Daojing Zhai. All rights reserved.
//

#include <iostream>
const int MAXSIZE = 100;
int Array[MAXSIZE];
using namespace std;

void SelectSort(int left, int right){
    for (int i=left; i<right; i++) {
        int k = i;
        for (int j = i+1; j<=right; j++) {
            if (Array[j] < Array[k]) {
                int temp = Array[k];
                Array[k] = Array[j];
                Array[j] = temp;
            }
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
    SelectSort(0, inputSize-1);
    return 0;
}
