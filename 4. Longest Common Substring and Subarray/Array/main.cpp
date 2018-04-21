//
//  main.cpp
//  Longest Common Subarray
//  Created by Daojing Zhai on 2018/4/21.
//  Copyright © 2018 Daojing Zhai. All rights reserved.
//


#include <iostream>
#include <string>
using namespace std;
string st1;
string st2;

int lcs(int m, int n){      //find the longest common subarray of st1[0 - m-1] and st2[0 - n-1]
    if (m==0||n==0)
        return 0;
    if (st1[m-1] == st2[n-1])
        return lcs(m-1, n-1) + 1;
    else
        return max(lcs(m-1, n), lcs(m, n-1));
}

int find_longest_sub(int m, int n){ //find the longest common subarray.
    int longest = 0;
    for (int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(lcs(i,j)>longest) longest = lcs(i, j);
        }
    }
    return longest;
}


void print_lcs(int m, int n, int longest){    //find start of LCS. Note here we only print the first LCS when there are various LCSs.
    if (longest==0) cout<<"false";
    else{
        int LCS_length = 0;
        for (int i=0; i<=m; i++){
            if (lcs(i, st2.size())>LCS_length){
                cout<<st1[i-1];
                LCS_length = lcs(i, st2.size());
            }
        }
    }
}

int main() {
    while(cin>>st1>>st2){
        int longest = find_longest_sub(st1.size(), st2.size());
        print_lcs(st1.size(), st2.size(), longest);
        cout<<endl;
    }
    
    return 0;
}
