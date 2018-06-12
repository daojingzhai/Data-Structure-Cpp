//
//  main.cpp
//  Binarysearch
//
//  Created by Daojing Zhai on 2018/5/28.
//  Copyright © 2018 Daojing Zhai. All rights reserved.
//

#include <iostream>
using namespace std;

void Binarysearch(int head, int tail, int target, int count, int *list){
    if (head > tail){
        cout<<0<<' '<<count<<endl;
        return;
    }
    count++;
    int mid = (head+tail)/2;
    if (target == list[mid])
        cout<<1<<' '<<count<<endl;
    else if (target < list[mid])
        Binarysearch(head, mid-1, target, count, list);
    else
        Binarysearch(mid+1, tail, target, count, list);
    return;
}


int main(){
    int tot;
    while (cin>>tot) {
        int target;
        int count = 0;
        int *list=new int[tot];
        cin>>target;
        int element;
        for (int i = 0; i<tot; i++) {
            cin>>element;
            list[i] = element;
        }
        Binarysearch(0, tot-1, target, count, list);
    }
    return 0;
}
