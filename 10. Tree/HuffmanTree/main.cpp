//
//  main.cpp
//  HuffmanTree
//
//  Created by Daojing Zhai on 2018/5/16.
//  Copyright © 2018 Daojing Zhai. All rights reserved.
//


#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <queue>

using namespace std;
#define MAXSIZE 512

int input(string str,int *num){
    stringstream conv(str);
    int ip;
    int curr=0;
    while (conv >> ip) {
        num[curr]=ip;
        curr++;
    }
    return curr;
}

class HuffmanNode{
public:
    HuffmanNode(int wght){
        weight = wght;
        leftchild=rightchild=NULL;
        distance = 0;
    };
    ~HuffmanNode();
    void insert_child(HuffmanNode *left_node,HuffmanNode *right_node);
    int read_weight();
    int distance;
    void print_tree(HuffmanNode *p);
    HuffmanNode *leftchild;
    HuffmanNode *rightchild;
    int weight;
};

class HuffmanTree{
public:
    HuffmanTree(){
        head=NULL;
        wpl=0;
    }
    ~HuffmanTree(){
        delete head;
    }
    void Create_Tree(int *numlist,int length);
    int return_head_weight();
    int countWPL();
    HuffmanNode *head;
    
private:
    int wpl;
};

int HuffmanTree::return_head_weight(){
    return head->read_weight();
}

void HuffmanNode::print_tree(HuffmanNode *p){
    HuffmanNode *current = p;
    if (current->leftchild!=0 ||current->rightchild!=0) {
        cout<<current->weight<<endl;
        print_tree(current->leftchild);
        print_tree(current->rightchild);
    }
    else{
        cout<<current->weight<<endl;
        return;
    }
    return;
}



int HuffmanNode::read_weight(){
    return this->weight;
}

void HuffmanTree::Create_Tree(int *numlist, int length){
    vector<HuffmanNode*>nde;
    for(int i=0;i<length;i++){
        HuffmanNode *tnode=new HuffmanNode(numlist[i]);
        nde.push_back(tnode);
    }
    while(nde.size()!=1){
        HuffmanNode *min1_node=nde[0];
        HuffmanNode *min2_node=nde[1];
        int min1=nde[0]->read_weight();
        int min2=nde[1]->read_weight();
        int min1_loc=0;
        int min2_loc=1;
        for(int i=2;i<nde.size();i++){
            int curr_w=nde[i]->read_weight();
            if(curr_w>=min2);
            else if(curr_w>=min1){
                min2_node=nde[i];
                min2=curr_w;
                min2_loc=i;
            }
            else{
                min2_node=min1_node;
                min2=min1;
                min2_loc=min1_loc;
                min1_node=nde[i];
                min1=curr_w;
                min1_loc=i;
            }
        }
        HuffmanNode *tnode=new HuffmanNode(min1_node->read_weight()+min2_node->read_weight());
        tnode->insert_child(min1_node,min2_node);
        nde[min1_loc]=tnode;
        nde.erase(nde.begin()+min2_loc);
    }
    this->head=nde[0];
}


int HuffmanTree::countWPL(){
    int WPL = 0;
    if (head == NULL) {
        return WPL;
    }
    queue<HuffmanNode*> Q;
    Q.push(head);

    while (!Q.empty()) {
        HuffmanNode *current = Q.front();
        if (current->leftchild!=NULL || current->rightchild!=NULL) {
            current->leftchild->distance = current->distance+1;
            current->rightchild->distance = current->distance+1;
            Q.push(current->leftchild);
            Q.push(current->rightchild);
            Q.pop();
        }
        else{
            WPL += current->distance * current->weight;
            Q.pop();
        }
    }
    return WPL;
    
}

void HuffmanNode::insert_child(HuffmanNode *left_node,HuffmanNode *right_node){
    this->leftchild=left_node;
    this->rightchild=right_node;
}


int main(){
    string Str;
    while(getline(cin,Str)){
        int *num=new int[MAXSIZE];
        int length = input(Str,num);
        HuffmanTree *mytree=new HuffmanTree;
        mytree->Create_Tree(num,length);
        //cout<<mytree->return_head_weight()<<endl;
        cout<<mytree->countWPL()<<endl;
        //mytree->head->print_tree(mytree->head);
    }
}
