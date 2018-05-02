//
//  main.cpp
//  Doubly linkedin list
//
//  Created by Daojing Zhai on 04/04/2018.
//  Copyright © 2018 Daojing Zhai. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <string.h>

using namespace std;

struct Node{
    string content;
    Node *next;
    Node *forward;
};

Node *input(char* str);
void output(Node *h);
void remove(Node *h);

Node *input(char* str){
    const char *sep = " ";
    char * p = strtok(str, sep);
    Node* head = new Node;
    head->content = p;
    head->next = head;
    head->forward = head;
    Node* temp = head;
    p = strtok(NULL, sep);
    while(p){
        Node *next_node = new Node;
        next_node->next = head;
        head->forward=next_node;
        next_node->content = p;
        temp->next=next_node;
        next_node->forward=temp;
        temp = next_node;
        p = strtok(NULL, sep);
    }
    return head;
}


void output(Node *h){
    Node *p=h->forward;
    for (; p!=h; p=p->forward)
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

int main(){
    string str;
    while(getline(cin,str)){
        Node *head;
        head = input((char *)str.data());
        if(head==NULL)
            break;
        output(head);
        remove(head);
    }
    return 0;
}

