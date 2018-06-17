//
//  main.cpp
//  ShellSort
//
//  Created by Daojing Zhai on 2018/6/17.
//  Copyright © 2018 Daojing Zhai. All rights reserved.
//


#include <iostream>
const int MAXSIZE = 100;
int Array[MAXSIZE];
using namespace std;
void ShellSort(int left, int right){
    int i,j,temp;
    int gap = right-left+1;
    while (gap > 1) {
        gap = gap/3+1;
        for (i = left+gap; i<=right; i++) {
            if (Array[i]<Array[i-gap]) {
                temp = Array[i];
                j = i-gap;
                while (j>=left && Array[j]>temp) {
                    Array[j+gap] = Array[j];
                    j = j-gap;
                }
                Array[j+gap] = temp;
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
    ShellSort(0, inputSize-1);
    return 0;
}
