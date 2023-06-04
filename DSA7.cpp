#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Vertex;

class Edges{
	private:
		Vertex*source;
		Vertex*destination;
		int distance;
	public:
		Edges(Vertex*s,Vertex*dst,int d){
			source=s;
			destination=dst;
			distance=d;
		}
		Vertex* getsource(){
			return source;
		}
		
		Vertex* getdst(){
			return destination;
		}
		
		int getdistance(){
			return distance;
		}
};	


class Vertex{
	private:
		string city;
		vector<Edges>edge;
	public:
		Vertex(string name){
			city=name;
		}
		void addedge(Vertex*v,int dist){
			Edges newedge(this,v,dist);
			edge.push_back(newedge);			
		}
		
		string getcity(){
			return city;
		}
		void  show(){
			for(int i=0;i<(int)edge.size();i++){
				Edges e=edge[i];
				cout<<"Time to reach "<<(e.getdst())->getcity()<<" from "<<city<<" is "<<e.getdistance()<<" hrs"<<endl;
			}
			
			
		}
		
};


class graph{
	private:
		vector<Vertex*>v;
	public:
		void insert(Vertex*ptr){
			v.push_back(ptr);
		}
	
		void display(){
			for(int i=0;i<(int)v.size();i++){
				v[i]->show();
			}
			
		}
};

int main(){
	graph g;
	Vertex v1("Mumbai");
	Vertex v2("Nashik");
	Vertex v3("Pune");
	Vertex v4("Nagpur");
	Vertex v5("Aurangabad");
	
	Vertex*vptr1=&v1;	
	Vertex*vptr2=&v2;	
	Vertex*vptr3=&v3;
	Vertex*vptr4=&v4;
	Vertex*vptr5=&v5;
	
	v1.addedge(vptr2,10);
	v2.addedge(vptr4,20);
	v3.addedge(vptr4,12);
	v4.addedge(vptr3,6);
	v5.addedge(vptr1,7);
	v1.addedge(vptr3,7);
	
	g.insert(vptr1);
	g.insert(vptr2);
	g.insert(vptr3);
	g.insert(vptr4);
	g.insert(vptr5);
	
	g.display();
	
	
}
