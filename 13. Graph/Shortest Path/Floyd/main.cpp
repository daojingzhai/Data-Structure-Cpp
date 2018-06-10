//
//  main.cpp
//  Floyd Algorithm
//
//  Created by Daojing Zhai on 2018/6/9.
//  Copyright © 2018 Daojing Zhai. All rights reserved.
//

#include <iostream>
using namespace std;

void Floyd(int **Edge, int n, int u, int v){
    int **Path = new int*[n];
    
    // Initialize Path
    for (int i=0; i<n; i++){
        Path[i] = new int[n];
        for (int j=0; j<n; j++) {
            if (i!=j && Edge[i][j]!=-1)
                Path[i][j] = i;
            else
                Path[i][j] = -1;
        }
    }
    
    // Floyd algorithm
    for (int k=0; k<n; k++)
        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
                if (Edge[i][k]>0 && Edge[k][j]>0) {
                    if (Edge[i][j]<0) {
                        Edge[i][j] = Edge[i][k]+Edge[k][j];
                        Path[i][j] = Path[k][j];
                    }
                    else if (Edge[i][k]+Edge[k][j]<Edge[i][j]){
                        Edge[i][j] = Edge[i][k]+Edge[k][j];
                        Path[i][j] = Path[k][j];
                    }
                }
    cout<<Edge[u][v]<<endl;
    
    
    // Print Path
    cout<<v<<"->";
    int current = Path[u][v];
    while (current!=u){
        cout<<current<<"->";
        current = Path[u][current];
    }
    cout<<current;
    
    return;
}


int main() {
    int n,u,v;
    while (cin>>n>>u>>v) {
        int **Edge = new int*[n];
        for (int i=0; i<n; i++){
            Edge[i] = new int[n];
            for (int j=0; j<n; j++){
                cin>>Edge[i][j];
            }
        }
        Floyd(Edge, n, u, v);
        for (int i=0; i<n; i++)
            delete [] Edge[i];
        delete [] Edge;
    }
}
