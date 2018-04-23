//
//  main.cpp
//  Knapsack Problem
//
//  Created by Daojing Zhai on 05/04/2018.
//  Copyright © 2018 Daojing Zhai. All rights reserved.
//

#include <iostream>
using namespace std;

int w[1000];
int KNAP(int s, int n){
    if (s == 0) return 1;
    if (s<0) return 0;
    if (s>0 && n<1) return 0;
    if (KNAP(s-w[n],n-1)) return 1;
    return KNAP(s,n-1);
}
    
int main() {
    int s,n,m;
    while(cin>>s>>n){
        for (int i=1;i<n+1;i++) cin>>w[i];
        m = KNAP(s,n);
        if (m) cout<<"true"<<endl;
        else cout<<"false"<<endl;
    }
    return 0;
}
