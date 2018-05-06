//
//  main.cpp
//  Stack_Array
//
//  Created by Daojing Zhai on 2018/5/6.
//  Copyright © 2018 Daojing Zhai. All rights reserved.
//

# include <iostream>
using namespace std;
const int STACK_SIZE = 100;

class Stack{
public:
    Stack(){top = -1;};
    ~Stack() {makeEmpty();};
    bool push(int i);
    bool pop(int &i);
    void makeEmpty(){
        top = -1;
    };
    int IsEmpty(){
        if (top == -1) return 1;
        else return 0;
    };
    int IsFull(){
        if (top == STACK_SIZE-1) return 1;
        else return 0;
    }
private:
    int top;
    int buffer[STACK_SIZE];
};

bool Stack::push(int i){
    if (IsFull()) {
        cout<<"stack is overflow.\n";
        return false;
    }
    else{
        top++;
        buffer[top] = i;
        return true;
    }
}

bool Stack::pop(int &i){
    if (IsEmpty()){
        cout<<"stack is empty.\n";
        return false;
    }
    else{
        i = buffer[top];
        top--;
        return true;
    }
}
