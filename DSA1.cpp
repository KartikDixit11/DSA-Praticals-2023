#include<iostream>
#include<string>
#include<sstream>
#include<map>
#include<vector>

using namespace std;

int main(){
	int c;
	string name,id,phone;
	map<int,vector<string> >m1;
	map<int,vector<string> >::iterator itr;
	vector<string>v;
	vector<string>v1;
	v1.push_back("Na");v1.push_back("Na");v1.push_back("Na");
	cout<<"Enter the total number of users:";
	cin>>c;
	
	for (int i=0;i<c;i++){
		m1[i]=v1;
	}
	for(int i=0;i<c;i++){
		cout<<"Enter the id:";
		cin>>id;
		v.push_back(id);
		
		cout<<"Enter the name:";
		cin>>name;
		v.push_back(name);
		
		cout<<"Enter the phone:";
		cin>>phone;
		v.push_back(phone);
		
		stringstream ss;
		ss<<v.at(0);
		int x=0;
		ss>>x;
		int p=x%10;
		if (m1[p]==v1){
		
			m1[p]=v;
	}
		else if (m1[p]!=v1){
		
			while (m1[p]!=v1){
			
				p=(p+1)%10;
		}
			m1[p]=v;
	}
		v.resize(0);
		
	}
	cout<<"______TELEPHONE____DIRECTORY______"<<endl<<endl;
	cout<<"Sr.No"<<"  "<<"ID"<<"  "<<"Name"<<"    "<<"Telephone"<<endl;
	for(itr=m1.begin();itr!=m1.end();itr++){
		cout<<(itr->first)<<"      "<<(itr->second).at(0)<<"  "<<(itr->second).at(1)<<"      "<<(itr->second).at(2)<<"    "<<endl;
	}
}
