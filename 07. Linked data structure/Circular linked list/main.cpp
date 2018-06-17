//
//  main.cpp
//  Circular linkedin list
//
//  Created by Daojing Zhai on 03/04/2018.
//  Copyright © 2018 Daojing Zhai. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>

using namespace std;

struct Node{
    int content;
    Node *next;
};

Node *input(string str);
void output(Node *h);
void remove(Node *h);

int main(){
    string str;
    while(getline(cin,str)){
        Node *head;
        head = input(str);
        if(head==NULL)
            break;
        output(head);
        remove(head);
    }
    return 0;
}

Node *input(string str){
    stringstream conv(str);
    Node *tail = NULL;
    Node *head = NULL;
    int num;
    while (conv >> num) {
        Node *p = new Node;
        p->content = num;
        if(head == NULL){
            head = p;
            p->next = head;
            tail = head;
        }
        else{
            p->next = head;
            tail->next = p;
            head = p;
        }
    }
    return head;
}

void output(Node *h){
    Node *p=h;
    for (; p->next!=h; p=p->next)
        cout<<p->content<<" ";
    cout<<p->content<<endl;
}

void remove(Node *h){
    Node *tail = h;
    while(tail->next!=h) tail=tail->next;
    while(h!= h->next){
        Node *p = h;
        h = h->next;
        tail->next = h;
        delete p;
    }
    delete h;
}



