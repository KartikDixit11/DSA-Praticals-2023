#include<iostream>
#include<string>

	
	int Subs[10];
	int Subsect[10];
using namespace std;

class subsections{
	public:
		string subname;
};

class sections{
	public:
		string secname;
		int subc;
		subsections*subs;
};
class Chapters{
	public:
		string chname;
		int secc;
		sections*sec;
}; 
class Tree{
	
	public:
		string bname;
		Chapters*ch;
		int c1;
		void create();
		void show();
		
};

void Tree::create(){
	cout<<"Enter the name of book:";
	getline(cin,bname);
	cout<<endl<<endl;
	int subs,data;
	
	int Subs[10];
	int Subsect[10];
	
	cout<<"Enter the no.of Chapters:";
	cin>>c1;
	
	cout<<endl<<endl;
	
	ch=new Chapters[c1];
	
	for(int i=0;i<c1;i++){
		
		cout<<"Chapter no."<<i+1<<":";
		cin>>ch[i].chname;
		cout<<endl<<endl;
		
		cout<<"Enter the no.Sections in "<<ch[i].chname<<":";
		cin>>subs;	
		ch[i].sec=new sections [subs];
		cout<<endl;
		
		for(int j=0;j<subs;j++){
			cout<<"		Section"<<j+1<<":";
			cin>>ch[i].sec[j].secname;
			
			cout<<"		No. of Subsections in "<<ch[i].sec[j].secname<<":";
			cin>>data;
			cout<<endl;
			
			
			(ch[i].sec[j]).subs=new subsections[data];
			for(int k=0;k<data;k++){
				cout<<"			Subsection "<<k+1<<":";
				cin>>((ch[i].sec[j]).subs[k]).subname;
			}
		}		
	}
	
	
}


void Tree::show(){
			cout<<"Book:"<<bname<<endl;
			
			for(int i=0;i<c1;i++){
				cout<<"	  Chapter "<<i+1<<ch[i].chname<<endl<<endl;
				cout<<" 		Sections:-";
				for(int j=0;j<;j++){
					cout<<ch[i].sec[j].secname;
				}
			}
}


int main(){
	Tree T1;
	T1.create();
	T1.show();
	
	return 0;
}
