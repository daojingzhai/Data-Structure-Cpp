//
//  main.cpp
//  KMP Algorithm
//
//  Created by Daojing Zhai on 2018/5/2.
//  Copyright © 2018 Daojing Zhai. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int strlen(char *p){
    int l=0;
    while(*p && *p!='\n'){
              l++;
              p++;
          }
    return l;
}

const int maxnum = 1000; //max length of pattern.
int next_index[maxnum];

void assignstr(string input, char *target, char *pattern){
    int lengthstr = input.length();
    int pat_index = 0;
    int tar_index = 0;
    int input_index = 0;
    while (input[input_index]!=','){
        target[tar_index] = input[input_index];
        tar_index++;
        input_index++;
    }
    input_index++;
    while (input_index<lengthstr){
        pattern[pat_index]=input[input_index];
        pat_index++;
        input_index++;
    }
}

void getnext(char *pat, int lengthP){
    int j=0, k=-1;
    next_index[0] = -1;
    while(j<lengthP){
        if(k==-1||pat[j]==pat[k]){
            j++;
            k++;
            next_index[j] = k;
        }
        else
            k=next_index[k];
    }
}

void KMPsearch(char *pat, char *target){
    getnext(pat, strlen(pat));
    int posP = 0, posT = 0;
    int flag = 0;
    int count = 0;
    int lengthP = strlen(pat);
    int lengthT = strlen(target);
    if (lengthP == 1){ //单独讨论lengthP=1的情况
        for (int i=0; i<lengthT; i++) {
            if (target[i] == pat[0]){
                if (count!=0) cout<<' ';
                cout<<i;
                flag = 1;
                count++;
            }
        }
    }
    else{ //KMP算法求解lengthP!=1的情况
        while (posT<lengthT && posP<lengthP){
            if (posP == -1||pat[posP]==target[posT]){
                posP++;
                posT++;
            }
            else posP = next_index[posP];
            if (posP == lengthP){
                if (count!=0)
                    cout<<' ';
                cout<<posT-lengthP;
                flag = 1;
                posP = 0;
                posT = posT-lengthP+1;
                count++;
            }
        }
        
    }
    if (flag==1) cout<<endl;
    if (flag==0) cout<<"false"<<endl;
}

int main(){
    string inputstr;
    while (getline(cin,inputstr)){
        char *target = new char[maxnum];
        char *pattern = new char[maxnum];
        assignstr(inputstr, target, pattern);
        KMPsearch(pattern, target);
        delete []target;
        delete []pattern;
    }
    return 0;
}
