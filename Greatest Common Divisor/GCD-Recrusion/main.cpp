//
//  main.cpp
//  GCD
//
//  Created by Daojing Zhai on 05/04/2018.
//  Copyright © 2018 Daojing Zhai. All rights reserved.
//

#include <iostream>
using namespace std;

int gcd(int x, int y){
    int m;
    if (x<y){
        int temp = x;
        x = y;
        y = temp;
    }                       //set x>=y
    if (x%y==0){
        m = y;
        return m;
    }
    else{
        return gcd(x, x%y);
    }
}

int main(){
    int x,y,m;
    while(cin>>x>>y){
        m = gcd(x,y);
        cout<<m<<endl;
    }
    return 0;
}
