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

    void preorder(Node* node){
        if(node==NULL){
            return;
        }
        cout<<"["<<node->i.low<<" , "<<node->i.high<<"]"<<", Max : "<<node->max<<" ";
        preorder(node->left);
        preorder(node->right);
    }

    Node* isOverlapping(Node* node,int l,int h){
        if(node==NULL){
            return NULL;
        }
        if(node->i.low<=h && node->i.high>=l){
            return node;
        }
        if(node->left!=NULL && node->left->max>=l){
            return isOverlapping(node->left,l,h);
        }

        return isOverlapping(node->right,l,h);
    }

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

    void insert(int l,int h){
        root=insert(root,l,h);
    }

    void preorder(){
        preorder(root);
    }

    void searchOverlap(int l,int h){
        Node *res=isOverlapping(root,l,h);
        if(res!=NULL){
            cout<<"Overlaps with ["<<res->i.low<<" , "<<res->i.high<<"]"<<endl;
        }else{
            cout<<"No overlapping interval found"<<endl;
        }
    }
};

int main(){
    IntervalTree it(15,20);
    it.insert(10,30);
    it.insert(17,19);
    it.insert(5,20);
    it.insert(12,15);
    it.preorder();
    cout<<endl;
    it.searchOverlap(14,16);
}