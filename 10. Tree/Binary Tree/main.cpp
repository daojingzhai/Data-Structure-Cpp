//
//  main.cpp
//  BinTreeNode
//
//  Created by Daojing Zhai on 2018/5/10.
//  Copyright © 2018 Daojing Zhai. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;


struct BinTreeNode{
    char data;
    BinTreeNode *leftchild, *rightchild;
    BinTreeNode() {
        leftchild = NULL;
        rightchild = NULL;
    }
//    BinTreeNode(T x, BinTreeNode<T> *l = NULL, BinTreeNode<T> *r = NULL){
 //       data = x;
  //      leftchild = l;
   //     rightchild = r;
    //}
};

class BinaryTree {
public:
    BinaryTree() {root = NULL;}
    void PreOrderBuild();
protected:
    BinTreeNode *root;
    char RefValue = '@'; // 数据输入停止标志
    void CreateBinTree (BinTreeNode*& subTree); //前序遍历建立二叉树
    void PostOrder (BinTreeNode* subTree); //后序遍历
    void visit (BinTreeNode *t){
        if (t->data != '@' ) cout<< t->data;
    }
};

void BinaryTree::PostOrder (BinTreeNode* subTree) {
    if (subTree != NULL ) {
        PostOrder (subTree->leftchild);  //遍历左子树
        PostOrder (subTree->rightchild); //遍历右子树
        visit (subTree);    //访问根结点
    }
};

void BinaryTree::CreateBinTree (BinTreeNode*& subTree) { //以递归方式建立二叉树。
    char item;
    if ((item=getchar())!=0) { //未读完, 读入并建树
        if (item != RefValue) {
            subTree = new BinTreeNode(item); //建立根结点
            CreateBinTree (subTree->leftchild); //递归建立左子树
            CreateBinTree (subTree->rightchild); //递归建立右子树
        }
        else subTree = NULL;    //封闭指向空子树的指针
    }
};

int main() {
    BinaryTree binarytree;
    while(){
        
    }
}
