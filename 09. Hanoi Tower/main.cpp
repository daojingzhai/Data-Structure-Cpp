//
//  main.cpp
//  Hanoi Tower
//
//  Created by Daojing Zhai on 2018/5/7.
//  Copyright © 2018 Daojing Zhai. All rights reserved.
//

#include <iostream>
using namespace std;

void Hanoi(int n, char A, char B, char C){
    if (n==1) cout<<"Move "<<A<<" to "<<C<<endl;
    else{
        Hanoi(n-1, A, C, B);
        cout<<"Move "<<A<<" to "<<C<<endl;
        Hanoi(n-1, B, A, C);
    }
}

int main() {
    int n;
    char A = 'A';
    char B = 'B';
    char C = 'C';
    cout<<"Please input towper height:";
    cin>>n;
    Hanoi(n, A, B, C);
    return 0;
}
