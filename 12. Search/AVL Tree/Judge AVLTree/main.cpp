//
//  main.cpp
//  Judge AVLTree
//
//  Created by Daojing Zhai on 2018/5/28.
//  Copyright © 2018 Daojing Zhai. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <queue>
#include <stdlib.h>

using namespace std;
#define MAXSIZE 1000

class AVLTree{
public:
    AVLTree(){
        data = -1;
        leftchild = NULL;
        rightchild = NULL;
    };
    ~AVLTree(){
        AVLTree *temp1,*temp2 = new AVLTree;
        temp1 = leftchild;
        temp2 = rightchild;
        delete temp1;
        delete temp2;
        data = -1;
    };
    void InsertAVL(AVLTree *&root, int key);
    void preorderPrint(AVLTree *root);
    int GerTreeBalance(AVLTree *root);
    void JudgeAVL(AVLTree *root);
private:
    AVLTree *leftchild;
    AVLTree *rightchild;
    int data;
    int balance;
    
};


void AVLTree::InsertAVL(AVLTree *&root, int key){
    //Insert key to the Binary search tree with *root.
    if (!root) {
        AVLTree *node = new AVLTree;
        node->data = key;
        node->leftchild = node->rightchild = NULL;
        root = node;
        return;
    }
    if (root->data == key) return;
    else if (root->data > key)   InsertAVL(root->leftchild, key);
    else InsertAVL(root->rightchild, key);
    return;
}


void AVLTree::preorderPrint(AVLTree *root){
    //PretorderPrint the Binary Tree.
    if(root==NULL)
    return;
    cout << root->data;
    if(root->leftchild!=NULL){
        cout<<' ';
        preorderPrint(root->leftchild);
    }
    if(root->rightchild!=NULL){
        cout<<' ';
        preorderPrint(root->rightchild);
    }
}

int AVLTree::GerTreeBalance(AVLTree *root){
    if (root == NULL) return 0;
    if (root->leftchild == NULL && root->rightchild == NULL){
        root->balance = 0;
        return 1;
    }
    else{
        int left = GerTreeBalance(root->leftchild);
        int right = GerTreeBalance(root->rightchild);
        root->balance = right - left;
        if (left>=right)
            return left+1;
        else
            return right+1;
    }
}



void AVLTree::JudgeAVL(AVLTree *root){
    queue<AVLTree*> Q;
    Q.push(root);
    
    while(!Q.empty()){
        AVLTree *current = Q.front();
        if (abs(current->balance)>1){
            cout<<"False";
            return;
        }
        else{
            if (current->leftchild!=NULL || current->rightchild!=NULL){
                if (current->leftchild !=NULL) Q.push(current->leftchild);
                if (current->rightchild !=NULL) Q.push(current->rightchild);
                Q.pop();
            }
            else
                Q.pop();
        }
    }
    cout<<"True";
}

int main(){
    int tot;
    while(cin>>tot){
        AVLTree *root = new AVLTree;
        root = NULL;
        int element;
        for (int i = 0; i<tot; i++) {
            cin>>element;
            root->InsertAVL(root, element);
        }
        root->preorderPrint(root);
        root->GerTreeBalance(root);
        root->JudgeAVL(root);
        cout<<endl;
    }
    return 0;
}
