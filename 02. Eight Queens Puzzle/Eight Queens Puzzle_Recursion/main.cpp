//
//  main.cpp
//  Eight Queens Puzzle_Recursion
//
//  Created by Daojing Zhai on 15/04/2018.
//  Copyright © 2018 Daojing Zhai. All rights reserved.
//
#include <iostream>
#include <cmath>

using namespace std;
#define QUEEN 8     //number of queens
#define INITIAL -10000   //Initial condition.


// using a 1D array to mark the cheese, where 1-N is the row number, and Queen[i] is the column number of the ith row.
int mark[QUEEN];

void initial(){ // in the begining, there is no cheese and all of the mark are 0;
    for(int i=1; i<QUEEN+1; i++){
        mark[i] = INITIAL;
    }
}

//print the solution
void print(){
    for(int i=1; i<QUEEN+1; i++)
        cout<<mark[i];
    cout<<endl;
}


//Judge could be placed in ith row and kth col.
int judge(int i,int k){
    int j=1;
    while(j<i){
        if(mark[j]==k || abs(j-i)==abs(mark[j]-k))
            return 0;
        j++;
    }
    return 1;
}

//We want to place a queen in kth row.
void place(int k){
    int j;
    if(k>QUEEN)
        print();
    else{
        for(j=1;j<=QUEEN;j++){
            if(judge(k,j)){
                mark[k] = j;
                place(k+1);
            }
        }
    }
}

int main()
{
    int n;
    while(cin>>n){
        initial();
        mark[1]=n;
        place(2);
    }
    return 0;
}


