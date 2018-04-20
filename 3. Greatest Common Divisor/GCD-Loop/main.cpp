//
//  main.cpp
//  HW2_A
//
//  Created by Daojing Zhai on 04/04/2018.
//  Copyright © 2018 Daojing Zhai. All rights reserved.
//

#include <iostream>
using namespace std;

int gcd(int x, int y){
    int m = 1;
    while(m!=0){
        if(x<y){
            m = y%x;
            y = m;
        }
        else{
            int temp = x;
            x = y;
            y = temp;
            m = y%x;
            y = m;
        }
    }
    m = x;
    return m;
}

int main(){
    int x,y,m;
    while(cin>>x>>y){
        m = gcd(x,y);
        cout<<m<<endl;
    }
    return 0;
}

