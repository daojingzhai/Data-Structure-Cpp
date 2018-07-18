//
//  main.cpp
//  Prim
//
//  Created by Daojing Zhai on 2018/6/10.
//  Copyright © 2018 Daojing Zhai. All rights reserved.


#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


struct EdgeStruct{
    int len;
    int start;
    int end;
};

struct cmp{
    bool operator()(const EdgeStruct &a,const EdgeStruct &b){
        return a.len > b.len;
    }
};

void Prim(EdgeStruct **Edge, int n){
    priority_queue<EdgeStruct, vector<EdgeStruct>,cmp> minHeap; //Build minimum heap
    bool *Vmst = new bool[n];
    for (int i=0; i<n; i++)
        Vmst[i] = false;
    int numin = 1;
    int pivot = 0; // Initial
    Vmst[pivot] = true;
    int totlen = 0;
    EdgeStruct temp;// Current Edge
    
    
    do{
        for(int i=0; i<n; i++){
            if (i!=pivot && Vmst[i]!=true && Edge[pivot][i].len>0) {
                minHeap.push(Edge[pivot][i]);
            }
        }
        temp = minHeap.top();
        minHeap.pop();
        Vmst[temp.end] = true;
        totlen = totlen + temp.len;
        pivot = temp.end;
        numin++;
    } while(numin<n);
    
    cout<<totlen<<endl;
}
    


int main() {
    int n;
    while (cin>>n) {
        EdgeStruct **Edge = new EdgeStruct*[n];
        for (int i=0; i<n; i++){
            Edge[i] = new EdgeStruct[n];
            for (int j=0; j<n; j++){
                cin>>Edge[i][j].len;
                Edge[i][j].start = i;
                Edge[i][j].end = j;
            }
        }
        Prim(Edge, n);
        for (int i=0; i<n; i++)
            delete [] Edge[i];
        delete [] Edge;
    }
}
