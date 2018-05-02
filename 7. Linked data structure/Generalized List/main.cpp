//
//  main.cpp
//  Generalized list
//
//  Created by Daojing Zhai on 2018/5/2.
//  Copyright © 2018 Daojing Zhai. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <assert.h>
using namespace std;

char ip[2048];
int curr_char;

enum utype{ATOM,LIST};

char next_char(){
    char re=ip[curr_char];
    curr_char++;
    return re;
}

struct nde{
    int type;
    nde *next_node;
    union{
        char val;
        nde *next_list;
    };
} gnode;

nde* reverselist(nde *head){
    nde* curr=head;
    nde* temp=NULL;
    nde* prev=NULL;
    while(curr!=NULL){
        if(curr->type==LIST)
            curr->next_list=reverselist(curr->next_list);
        temp=curr->next_node;
        curr->next_node=prev;
        prev=curr;
        curr=temp;
    }
    return prev;
}

void print_list(nde*head){
    nde* curr=head;
    do{
        if(curr->type==ATOM)
            cout<<curr->val;
        else
            print_list(curr->next_list);
        curr=curr->next_node;
    }  while(curr!=NULL);
}

nde* creat_list(){
    char c;
    nde *head=new nde;
    if(ip[curr_char]==')'){
        c=next_char();
        head->type=ATOM;
        head->val='@';
        head->next_node=NULL;
        return head;
    }
    nde *curr_nde=head;
    nde *prev_nde;
    while(1){
        c=next_char();
        switch(c){
            case '(':
                curr_nde->type=LIST;
                curr_nde->next_list=creat_list();
                break;
            default:
                curr_nde->type=ATOM;
                curr_nde->val=c;
                break;
        }
        prev_nde=curr_nde;
        curr_nde=new nde;
        prev_nde->next_node=curr_nde;
        c=next_char();
        if(c==')'){
            prev_nde->next_node=NULL;
            break;
        }
    }
    return head;
}


int main(){
    while(cin.getline(ip,2048)){
        curr_char=1;
        nde *head=creat_list();
        head=reverselist(head);
        print_list(head);
        cout<<endl;
    }
    return 0;
}
