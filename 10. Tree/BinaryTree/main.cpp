//
//  main.cpp
//  Binary Tree
//
//  Created by Daojing Zhai on 2018/5/15.
//  Copyright © 2018 Daojing Zhai. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
using namespace std;

#define MAXSIZE 1000

class BinaryTree{
public:
    BinaryTree(){
        data = '\0';
    };
    ~BinaryTree();
    int leftnodecount(BinaryTree *root, int &count);
    void createBinaryTree(BinaryTree *&root, char *src, int &count);
    void postorderPrint(BinaryTree *root);
    void transleftright(BinaryTree *root);
    void routeFromLeafToRoot(BinaryTree *root, char *res, int resCount, char *allRoute, int &routeCount);
private:
    BinaryTree *leftchild;
    BinaryTree *rightchild;
    char data;
};


void BinaryTree::createBinaryTree(BinaryTree *&root, char *src, int &count){
    // Input root, node data, previous src index.
    // Create Binary Tree based on preorder.
    if(count==strlen(src))
        return;
    
    if(src[count]!='@'){
        root=new BinaryTree();
        root->leftchild = NULL;
        root->rightchild = NULL;
        root->data = src[count];
        
        count = count + 1;
        createBinaryTree(root->leftchild, src, count);
        createBinaryTree(root->rightchild, src, count);
        return;
    }
    else{
        count = count + 1;
        return;
    }
}

void BinaryTree::postorderPrint(BinaryTree *root){
    //PostorderPrint the Binary Tree.
    if(root==NULL)
        return;
    
    if(root->leftchild!=NULL){
        postorderPrint(root->leftchild);
    }
    if(root->rightchild!=NULL){
        postorderPrint(root->rightchild);
    }
    cout << root->data;
    return;
}

int BinaryTree::leftnodecount(BinaryTree *root, int &count){
    //Count leftnode number;
    if (root == NULL)
        return count;
    if (root->leftchild == NULL && root->rightchild == NULL) count++;
    
    leftnodecount(root->leftchild, count);
    leftnodecount(root->rightchild, count);
    
    return count;
};

void BinaryTree::transleftright(BinaryTree *root){
    //Transfer left and right child.
    if (root == NULL)
        return;
    else{
        BinaryTree *temp = root->leftchild;
        root->leftchild = root->rightchild;
        root->rightchild = temp;
        transleftright(root->leftchild);
        transleftright(root->rightchild);
        return;
    }
}


void BinaryTree::routeFromLeafToRoot(BinaryTree *root, char* res, int resCount, char *allRoute, int &routeCount){
    // Recursion function. Store rote form leaf to root.
    if(root==NULL)
        return;
    
    if(root->leftchild!=NULL){
        res[resCount] = root->data;
        routeFromLeafToRoot(root->leftchild,res,resCount+1,allRoute,routeCount);
    }
    if(root->rightchild!=NULL){
        res[resCount] = root->data;
        routeFromLeafToRoot(root->rightchild,res,resCount+1,allRoute,routeCount);
    }
    if(root->leftchild==NULL && root->rightchild==NULL){
        res[resCount] = root->data;
        for (int i = 0; i <= resCount;i++){
            allRoute[i + routeCount] = res[resCount-i];
        }
        
        routeCount = routeCount + resCount + 1;
        allRoute[routeCount]=',';
        routeCount += 1;
    }
    
    res[resCount] = '\0';
    return;
}
                                     

                                     
int main() {
    char Str[MAXSIZE];
    memset(Str, '\0', MAXSIZE);
    while(cin.getline(Str,MAXSIZE)){
        BinaryTree *root = NULL;

        //creat a binary tree
        int count = 0;
        root->createBinaryTree(root, Str, count);
        
        //print postorder.
        root->postorderPrint(root);
        cout<<endl;
        count = 0;
  
        //count leftnode num.
        cout<<root->leftnodecount(root, count)<<endl;
        
        //transfer left and right child.
        root->transleftright(root);
        root->postorderPrint(root);
        cout<<endl;
        
        //gain the routes from every leaf node to the root
        char res[MAXSIZE];
        memset(res, '\0', MAXSIZE);
        char allRoute[MAXSIZE*2];
        memset(allRoute, '\0', MAXSIZE*2);
        int resCount = 0;
        int routeCount = 0;
        root->routeFromLeafToRoot(root, res, resCount,allRoute,routeCount);
        for (int i = 0; i < routeCount - 1;i++){
            cout << allRoute[i];
        }
        cout << endl;
    }
}
