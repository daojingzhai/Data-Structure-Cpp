//
//  main.cpp
//  Eight Queens Puzzle_backtracking
//
//  Created by Daojing Zhai on 11/04/2018.
//  Copyright © 2018 Daojing Zhai. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;
#define QUEEN 8     //number of queens
#define INITIAL -10000   //Initial condition.

int mark[QUEEN]; // using a 1D array to mark the cheese, where 1-N is the row number, and Queen[i] is the column number of the ith row.

void initial(){ // in the begining, there is no cheese and all of the mark are 0;
    for(int i=0; i<QUEEN; i++){
        mark[i] = INITIAL;
    }
}


int judge(int row, int col){ //judge whether we can put a cheese in [row][col]
    if (mark[row]!=INITIAL) return 0;
    for (int i=0; i<QUEEN; i++){
        if(mark[i]==col||abs(i-row)==abs(mark[i]-col))
            return 0;
    }
    return 1;
}

void print(){ //print the cheese position
    for(int i=0;i<QUEEN;i++){
        cout<<mark[i]+1;
    }
    cout<<endl;
}

void problem_solve(int n){
    int i=0;
    int j=n-1;
    while(i<QUEEN){
        while(j<QUEEN){
            if (judge(i, j)){
                mark[i] = j;
                j=0;
                break;
            }
            else j++;
        }
        if (mark[i]==INITIAL){ //No finding in ith row. we have to back to i-1th row and change the point.
            if (i==1) break; //it indicate that we have searched all the possible conditions.
            else{
                i--;
                j = mark[i]+1;
                mark[i] = INITIAL;
                continue;
            }
        }
        if (mark[i]!=INITIAL){ //we find possible position in the row.
            if (i==QUEEN-1) {
                print();
                j = mark[i]+1;
                mark[i]=INITIAL;
                continue;
            }
        i++;
        }

    }
    
}

int main(){
    int n;
    while(cin>>n){
        initial();
        problem_solve(n);
    }
    return 0;
}
