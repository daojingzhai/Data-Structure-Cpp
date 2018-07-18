//
//  main.cpp
//  Palindromic Subsequence by Manacher Method
//
//  Created by Daojing Zhai on 2018/4/20.
//  Copyright © 2018 Daojing Zhai. All rights reserved.
//

#include <iostream>
#include <strstream>
#include <string>
using namespace std;
const int N=1000;
string st,st_derived;
int R[N];              //radius of the palindromic substring

void input(string st){
    st_derived = "$#"; //eg: $%A%B%C%D%
    for (int i=0; i<st.size();i++){
        st_derived += st[i];
        st_derived += "#";
    }
}

int findr(int i){   //find the redius when st_derived[i] is the center.
    int count=1;
    while(i-count>0){
        if(st_derived[i+count]!=st_derived[i-count]) break;
        count++;
    }
    return count;
}

void findR(){ //find R[N]
    R[0] = 1;
    int pos = 1;
    R[pos] = 1;
    int max = pos+R[pos]-1;    //initial.
    for (int i=2; i<st_derived.size();i++){
        if(i+R[2*pos-i]<max) R[i] = R[2*pos-i];
        else{
            R[i] = findr(i);
            pos = i;
            max = pos+R[pos]-1;
        }
    }
}

int findmax_index(){ //find max element in a array
    int max_index=0;
    int i=0;
    while(i<st_derived.size()){
        if(R[max_index]<R[i]) max_index=i;
        i++;
    }
    return max_index;
}

void output(int i){ //output the largest
    for(int j=i-R[i]+2;j<=i+R[i]-2;j=j+2)
        cout<<st_derived[j];
}

int main(){
    while(cin>>st){
        input(st);
        findR();
        output(findmax_index());
        cout<<endl;
    }
    return 0;
}

