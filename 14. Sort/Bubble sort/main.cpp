//
//  main.cpp
//  BubbleSort
//
//  Created by Daojing Zhai on 2018/6/17.
//  Copyright © 2018 Daojing Zhai. All rights reserved.
//

#include <iostream>
const int MAXSIZE = 100;
int Array[MAXSIZE];
using namespace std;
void BubbleSort(int left, int right){
    int pass = left+1;
    int exchange = 1;
    while (pass <= right && exchange) {
        exchange = 0;
        for (int j = right; j >= pass; j--) {
            if (Array[j-1]>Array[j]) {
                int temp = Array[j];
                Array[j] = Array[j-1];
                Array[j-1] = temp;
                exchange = 1;
            }
        }
        pass ++;
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
    BubbleSort(0, inputSize-1);
    return 0;
}
