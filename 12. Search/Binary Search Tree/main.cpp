//
//  main.cpp
//  Binary Search Tree
//
//  Created by Daojing Zhai on 2018/5/28.
//  Copyright © 2018 Daojing Zhai. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>

using namespace std;
#define MAXSIZE 1000

class BSTree{
public:
    BSTree(){
        data = -1;
        leftchild = NULL;
        rightchild = NULL;
    };
    ~BSTree(){
        BSTree *temp1,*temp2 = new BSTree;
        temp1 = leftchild;
        temp2 = rightchild;
        delete temp1;
        delete temp2;
        data = -1;
    };
    void InsertBST(BSTree *&root, int key);
    void preorderPrint(BSTree *root);
    void deletekey(BSTree *&root, int key);
    void deletekeynote(BSTree *&node);
    
private:
    BSTree *leftchild;
    BSTree *rightchild;
    int data;
};


void BSTree::InsertBST(BSTree *&root, int key){
    // Insert key to the Binary search tree with *root.
    if (!root) {
        BSTree *node = new BSTree;
        node->data = key;
        node->leftchild = node->rightchild = NULL;
        root = node;
        return;
    }
    if (root->data == key) return;
    else if (root->data > key)   InsertBST(root->leftchild, key);
    else InsertBST(root->rightchild, key);
    return;
}

void BSTree::deletekey(BSTree *&root, int key){
    // Delete a key
    if(!root) return;
    else{
        if (key == root->data)  deletekeynote(root);
        else if (key < root->data)  deletekey(root->leftchild, key);
        else deletekey(root->rightchild, key);
    }
    return;
}

void BSTree::deletekeynote(BSTree *&node){
    // Delete a key note
    BSTree *temp = new BSTree;
    if (!node->leftchild && !node->rightchild){
        temp = node;
        delete temp;
        node = NULL;
    }
    else if (!node->rightchild){
        temp = node->leftchild;
        node->data = temp->data;
        node->leftchild = temp->leftchild;
        node->rightchild = temp->rightchild;
    }
    else if (!node->leftchild){
        temp = node->rightchild;
        node->data = temp->data;
        node->leftchild = temp->leftchild;
        node->rightchild = temp->rightchild;
    }
    else{
        temp = node->rightchild;
        BSTree *prev = node;
        while (temp->leftchild) {
            prev = temp;
            temp = temp->leftchild;
        }
        node->data = temp->data;
        if (prev == node)
            prev->rightchild = NULL;
        else
            prev->leftchild = NULL;
    }
}


void BSTree::preorderPrint(BSTree *root){
    // PretorderPrint the Binary Tree.
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



int main(){
    int tot;
    while(cin>>tot){
        BSTree *root = new BSTree;
        root = NULL;
        int element;
        int key;
        for (int i = 0; i<tot; i++) {
            cin>>element;
            root->InsertBST(root, element);
        }
        cin>>key;
        root->preorderPrint(root);
        cout<<endl;
        root->deletekey(root, key);
        root->preorderPrint(root);
        cout<<endl;
    }
    return 0;
}

