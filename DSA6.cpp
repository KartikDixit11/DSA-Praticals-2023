#include<iostream>
using namespace std;



int visited[]={0,0,0,0,0,0,0};
	int arr[7][7]={
		{0,1,1,1,0,0,0 },
		{1,0,0,1,0,0,0 },
		{1,0,0,1,1,0,0 },
		{1,1,0,1,1,0,0 },
		{0,0,1,1,0,1,1 },
		{0,0,0,1,0,0,0 },
		{0,0,0,1,0,0,0 }
	};


class Queue{
	private:
		int front,rear;
		int*arr;
		int size;
	public:\
		int Maxsize;
	Queue(){
		cout<<"Enter the Number the No.of Nodes in Graph:";
		cin>>Maxsize;
		arr=new int [Maxsize];
		size=front=rear=0;
	}
	
	int isempty(){
		if(front==rear){
			return 1;
		}
		else{
			return 0;
		}
	}
	
	int isfull(){
		if(size==Maxsize){
			return 1;
		}
		else{
			return 0;
		}
	}
	
	void enqueue(int data){
		if(!isfull()){
			size++;
			arr[rear]=data;
			rear++;
		}
		else{
			cout<<"Queue is Full";
		}
a	}
	
	int dequeue(){
		if(!isempty()){
			int ele=arr[front];
			front++;
			return ele;
		}
		else{
			cout<<"Queue is Empty";
		}
	}	
	
};
Queue*Q1=new Queue();

void BFS(int i){
	int s1=3;
	cout<<s1;
	Q1->enqueue(s1);
	visited[s1]=1;
	
	while(!(Q1->isempty())){
		int node=Q1->dequeue();
		for(int j=0;j<7;j++){
			if(arr[node][j]==1 && visited[j]==0){
				cout<<j<<endl;
				visited[j]=1;
				Q1->enqueue(j);
				
			}
		}
	}
}

void DFS(int i){
	cout<<i<<' ';
	visited[i]=1;
	for(int j=0;j<7;j++){
		if(arr[i][j]==1 && !visited[j]){
			visited[j]=1;
			DFS(j);
		}
	}
}

int main(){

	
	//	
	DFS(0);
	return 0;
}

