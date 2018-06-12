//
//  main.cpp
//  AVL Tree
//
//  Created by Daojing Zhai on 2018/5/28.
//  Copyright © 2018 Daojing Zhai. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

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
    int GetTreeHeight(AVLTree *root);
    void preorderPrint(AVLTree *root);

private:
    AVLTree *leftchild;
    AVLTree *rightchild;
    int data;
    int balancefactor;
    void rightRotate(AVLTree *&root);
    void leftRotate(AVLTree *&root);
    void leftrightRotate(AVLTree *&root);
    void rightleftRotate(AVLTree *&root);
    
};


void AVLTree::InsertAVL(AVLTree *&root, int key){
    //Insert key to the Binary search tree with *root.
    AVLTree *pr=NULL, *p = root, *q;
    stack<AVLTree *> st;
    while(p!=NULL){
        pr = p;
        st.push(pr);
        if(key < p->data) p = p->leftchild;
        else p = p->rightchild;
    }
    
    // New node
    p = new AVLTree;
    p->data = key;
    p->balancefactor = 0;
    
    // If Null tree;
    if (pr == NULL){
        root = p;
        return;
    }
    
    if (key<pr->data) pr->leftchild = p;
    else pr->rightchild = p;
    while(st.empty() == false){
        pr = st.top();
        st.pop();
        if (p == pr->leftchild) pr->balancefactor--;
        else pr->balancefactor++;
        if (pr->balancefactor == 0) break;
        if (pr->balancefactor == 1 || pr->balancefactor == -1) p = pr;
        else{
            if (pr->balancefactor == 2){
                if (pr->rightchild->balancefactor == 1) leftRotate(pr);
                else if (pr->rightchild->balancefactor == -1) rightleftRotate(pr);
            }
            else if (pr->balancefactor == -2){
                if (pr->leftchild->balancefactor == -1) rightRotate(pr);
                else if (pr->leftchild->balancefactor == 1) leftrightRotate(pr);
            }
            break;
        }
    }
    
    if (st.empty() == true) root = pr;
    else{
        q = st.top();
        if (q->data > pr->data) q->leftchild = pr;
        else q->rightchild = pr;
    }
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

int AVLTree::GetTreeHeight(AVLTree *root){
    if (root == NULL) return 0;
    else if (root->leftchild == NULL && root->rightchild == NULL)
        return 1;
    else{
        int left = GetTreeHeight(root->leftchild);
        int right = GetTreeHeight(root->rightchild);
        if (left>=right)    return left+1;
        else    return right+1;
    }
}

void AVLTree::rightRotate(AVLTree *&root){
    AVLTree *pivot = root;
    root = pivot->leftchild;
    pivot->leftchild = root->rightchild;
    root->rightchild = pivot;
    root->balancefactor = pivot->balancefactor = 0;
}

void AVLTree::leftRotate(AVLTree *&root){
    AVLTree *pivot = root;
    root = pivot->rightchild;
    pivot->rightchild = root->leftchild;
    root->leftchild = pivot;
    root->balancefactor = pivot->balancefactor = 0;
}

void AVLTree::leftrightRotate(AVLTree *&root){
    AVLTree *subR = root, *subL = subR->leftchild;
    root = subL->rightchild;
    subL->rightchild = root->leftchild;
    root->leftchild = subL;
    if (root->balancefactor <= 0)
        subL->balancefactor = 0;
    else
        subL->balancefactor = -1;
    
    subR->leftchild = root->rightchild;
    root->rightchild = subR;
    if (root->balancefactor == -1)
        subR->balancefactor = 1;
    else
        subR->balancefactor = 0;
    root->balancefactor = 0;
}

void AVLTree::rightleftRotate(AVLTree *&root){
    AVLTree *subL = root, *subR = subL->rightchild;
    root = subR->leftchild;
    subR->leftchild = root->rightchild;
    root->rightchild = subR;
    if (root->balancefactor <= 0)
        subR->balancefactor = 0;
    else
        subR->balancefactor = 1;
    
    subL->rightchild = root->leftchild;
    root->leftchild = subL;
    if (root->balancefactor == 1)
        subL->balancefactor = -1;
    else
        subL->balancefactor = 0;
    root->balancefactor = 0;
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
        cout<<endl;
    }
    return 0;
}
