//
//  main.cpp
//  MinHeap
//
//  Created by Daojing Zhai on 2018/5/15.
//  Copyright © 2018 Daojing Zhai. All rights reserved.
//


#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <sstream>
using namespace std;

#define MAXSIZE 1000

struct Node{
    int content;
    Node *next;
};

int countnode(Node *head){
    Node *p=head;
    int i=0;
    while(p!= NULL){
        i++;
        p = p->next;
    }
    return i;
}

Node *input(string str){
    stringstream conv(str);
    Node *head = NULL;
    Node *current = head;
    int num;
    while (conv >> num) {
        Node *p = new Node;
        p->content = num;
        if(head == NULL){
            head = p;
            head->next = NULL;
            current = head;
        }
        else{
            current->next = p;
            current = p;
            current->next = NULL;
        }
    }
    return head;
}

class MinHeap{
public:
    MinHeap(){
        currentSize = 0;
    };
    ~MinHeap() {delete []heap;};
    void CreatMinHeap(Node *head, int n);
    void printheap();

private:
    int *heap;
    int currentSize;
    void SiftDown(int start, int m);
    Node *head;
    Node *input(string str);
    int countnode(Node *head);
};


void MinHeap::printheap(){
    for(int i=0; i<currentSize-1; i++){
        cout<<heap[i]<<' ';
    }
    cout<<heap[currentSize-1];
    cout<<endl;
}

void MinHeap::CreatMinHeap(Node *head, int n){
    heap = new int[MAXSIZE];
    Node *p=head;
    int i = 0;
    while(p!=NULL) {
        heap[i] = p->content;
        i++;
        p = p->next;
    }
    currentSize = n;
    int currentPos = (currentSize - 2)/2;
    while (currentPos>=0) {
        SiftDown(currentPos, currentSize-1);
        currentPos--;
    }
}

void MinHeap::SiftDown(int start, int m){ //下滑算法，从节点start开始比较
    int i = start, j = 2*i+1;
    int temp = heap[i];
    while(j<=m){
        if (j<m && heap[j]>heap[j+1]) j++;
        if (temp<=heap[j]) break;
        else{
            heap[i] = heap[j];
            i = j;
            j = 2*j+1;
        }
    }
    heap[i] = temp;
}



int main() {
    string Str;
    while(getline(cin,Str)){
        Node *head;
        head = input(Str); //将输入的这串数字读进来，读到一个链表里，head是头
        MinHeap *minheap = new MinHeap;
        //creat a Minheap.
        int count = countnode(head);
        minheap->CreatMinHeap(head, count);
        minheap->printheap();
        cout<<endl;
    }
}
