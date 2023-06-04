#include<iostream>
using namespace std;

class node{
public:
	int data;
	node*right;
	node*left;
};

node* create_node(int a){
	node*Tree=new node();
	Tree->data=a;
	Tree->right=NULL;
	Tree->left=NULL;
	return Tree;
}

void search(node*root,int val){
	while(root!=NULL){
		if(root->data==val){
			cout<<"Key is Their";
			return;
			
		}
		else if(root->data<val){
			cout<<root->data<<endl;
			root=root->right;
		}
		else if(root->data>val){
			cout<<root->data<<endl;
			root=root->left;
		}
		
	}

	
}

void insert(node*root,int val){
	node*prev=new node();
	while(root!=NULL){
		prev=root;
		if(root->data==val){
			cout<<"Value already exsits inside BST";
			return;	
		}
		else if(root->data>val){
			root=root->left;
		}
		
		else if(root->data<val){
			root=root->right;
		}
	}
	node*in=create_node(val);
		if(prev->data>val){
			prev->left=in;
		}
		else{
			prev->right=in;
		}
	
}
int main(){
	node*n1=create_node(5);
	node*n2=create_node(3);
	//node*n3=create_node(2);
	node*n4=create_node(4);
	node*n5=create_node(1);
	node*n6=create_node(6);
	node*n7=create_node(9);
	
	n6->left=n4;
	n6->right=n7;
	
	n4->left=n2;
	n4->right=n1;
	
	
	insert(n6,2);
	insert(n6,1);
	insert(n6,7);
	
	cout<<(n7->left)->data;
	
	
}

