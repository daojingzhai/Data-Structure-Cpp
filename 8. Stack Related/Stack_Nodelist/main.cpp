//
//  main.cpp
//  Stack_NodeList
//
//  Created by Daojing Zhai on 2018/5/6.
//  Copyright © 2018 Daojing Zhai. All rights reserved.
//

# include <iostream>
using namespace std;

class Stack{
public:
    Stack(){top = NULL;};
    ~Stack() {makeEmpty();};
    void makeEmpty();
    bool IsEmpty(){
        if (top == NULL) return 1;
        else return 0;
    };
    bool push(int x);
    bool pop(int &x);
private:
    struct Node{
        int content;
        Node *next;
    };
    Node *top;
};

bool Stack::push(int x){
    Node *p = new Node;
    p-> content = x;
    p->next = top;
    top = p;
    delete p;
    return true;
}

bool Stack::pop(int &x){
    if (IsEmpty()) {
        cout<<"stack is empty.\n";
        return false;
    }
    else{
        Node *p = new Node;
        p = top;
        x = p->content;
        top = top->next;
        return true;
    }
}

void Stack::makeEmpty(){
    Node *p = new Node;
    p = top;
    delete p;
    top = NULL;
}
