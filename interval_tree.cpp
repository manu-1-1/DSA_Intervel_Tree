#include<iostream>
using namespace std;

struct Interval{
    int low;
    int high;
};

struct Node{
    Interval i;
    int max;
    Node* left;
    Node* right;
};

class IntervalTree{
private:
    Node* root;
public:
    IntervalTree(int l,int h){
        root=createNode(l,h);
    }

    Node* createNode(int low,int high){
        Node* newnode=new Node();
        newnode->i.low=low;
        newnode->i.high=high;
        newnode->right=NULL;
        newnode->left=NULL;
        newnode->max=high;
        return newnode;
    }

    Node* insert(Node* node,int l,int h){
        if(node==NULL){
            return createNode(l,h);
        }
        if(l<node->i.low){
            node->left=insert(node->left,l,h);
        }else{
            node->right=insert(node->right,l,h);
        }
        if(node->max<h){
            node->max=h;
        }
        return node;
    }

};




int main(){

}