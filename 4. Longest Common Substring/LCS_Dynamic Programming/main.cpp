//
//  main.cpp
//  Longest Common Substring problem
//  Dynamic Programming
//
//  Created by Daojing Zhai on 2018/4/20.
//  Copyright © 2018 Daojing Zhai. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
string st1;
string st2;

int lcs(int m, int n){      //find the longest common substring of st1[0 - m-1] and st2[0 - n-1]
    if (m==0||n==0)
        return 0;
    if (st1[m-1] == st2[n-1])
        return lcs(m-1, n-1) + 1;
    else
        return 0;
}

int find_longest_sub(int m, int n){ //find the longest common substring.
    int longest = 0;
    for (int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(lcs(i,j)>longest) longest = lcs(i, j);
        }
    }
    return longest;
}


int find_start_index(int m, int n, int longest){    //find start of LCS. Note here we only print the first LCS when there are various LCSs.
    int st1_start_index = 0;
    for (int i=1; i<=m; i++){
        int temp = 0;
        for(int j=1; j<=n; j++){
            if(lcs(i,j)==longest){
                st1_start_index = i-longest;
                temp = 1;
                break;
            }
        }
        if(temp==1) break;
    }
    return st1_start_index;
}

int main() {
    while(cin>>st1>>st2){
        int longest = find_longest_sub(st1.size(), st2.size());
        int st1_start_index = find_start_index(st1.size(), st2.size(), longest);
        for(int j=0; j<longest; j++){
            cout<<st1[st1_start_index+j];
        }
        if (longest==0) cout<<"false";
        cout<<endl;
    }

    return 0;
}
    
