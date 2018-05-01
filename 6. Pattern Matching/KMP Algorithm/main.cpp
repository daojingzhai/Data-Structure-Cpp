//
//  main.cpp
//  KMP Algorithm
//
//  Created by Daojing Zhai on 2018/5/1.
//  Copyright © 2018 Daojing Zhai. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
using namespace std;

const int maxnum = 1000; //max length of pattern.
int next_index[maxnum];


void assignstr(string input, char *target, char *pattern){
    int lengthstr =input.length();
    int pat_index = 0;
    int tar_index = 0;
    int input_index = 0;
    while (input[input_index]!=','){
        target[tar_index] = input[input_index];
        tar_index++;
        input_index++;
    }
    input_index++;
    while (input_index<lengthstr) {
        pattern[pat_index]=input[input_index];
        pat_index++;
        input_index++;
    }
}

void getnext(char *pat, int lengthP){// find next_index[j] of pattern
    int j=0, k=-1;
    next_index[0] = -1;
    while(j<lengthP){
        if(k==-1||pat[j]==pat[k]){
            j++;
            k++;
            next_index[j] = k;
        }
        else k=next_index[k];
    }
}


void KMPsearch(char *pat, char *target){
    getnext(pat, strlen(pat)); // find array next_index[j];

    int posP = 0, posT = 0;
    int flag = 0; //indicate is there are any finding.
    int count = 0;
    int lengthP = strlen(pat), lengthT = strlen(target);
    while (posT<lengthT) {
        if (posP == -1||pat[posP]==target[posT]) {
            posP++;
            posT++;
        }
        else posP = next_index[posP];
        if (posP == lengthP) {
            if (count!=0) {
                cout<<' ';
            }
            cout<<posT-lengthP;
            flag = 1;
            posP = 0;
            posT--;
            count++;
            
        }
    }
    if (flag==1) cout<<endl;
    if (flag==0) cout<<"false"<<endl;
}



int main(){
    string inputstr;
    while (getline(cin,inputstr)) {
        char *target = new char[maxnum];
        char *pattern = new char[maxnum];
        assignstr(inputstr, target, pattern);
        KMPsearch(pattern, target);
        delete []target; //free dynamic array
        delete []pattern; //free dynamic array
    }
    return 0;
}
