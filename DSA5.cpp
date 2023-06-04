#include<iostream>
#include<queue>
using namespace std;

class Node{
	public:
		int data;
		
		Node*right;
		
		Node*left;
		
		int ist;
};

Node* create_node(int val){
		Node*n=new Node();
		n->data=val;
		n->right=NULL;
		n->left=NULL;
		n->ist=0;
}


void create_ino_queue(Node*root,queue<Node*>*q){
			if(root==NULL){
				return;
			}
			if(root->left!=NULL){
				create_ino_queue(root->left,q);
			}
			q->push(root);
			if(root->right!=NULL){
				create_ino_queue(root->right,q);
			}	
}


void create_thread(Node*root,queue<Node*>*q){
	if(root==NULL){
	return;
	}
	if(root->left!=NULL){
		create_thread(root->left,q);
	}	
	q->pop();
	if(root->right!=NULL){
		create_thread(root->right,q);
	}
	
	else{
		root->right=q->front();
		root->ist=1;
		
	}

}
void BTtoTBT(Node*root){
	queue<Node*>data;
	create_ino_queue(root,&data);
	
	create_thread(root,&data);
				
}

int main(){
	Node*r=create_node(1);
	Node*l1=create_node(2);
	Node*r1=create_node(3);
	Node*l11=create_node(4);
	Node*l12=create_node(5);
	Node*r11=create_node(6);
	Node*r12=create_node(7);
	
	queue<Node*>q;	
	
	r->left=l1;
	r->right=r1;
	
	l1->left=l11;
	l1->right=l12;
	
	r1->left=r11;
	r1->right=r12;
	
	create_ino_queue(r,&q);
	
	BTtoTBT(r);
		
	
	
	return 0;
}


