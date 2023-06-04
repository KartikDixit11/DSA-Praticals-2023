#include<iostream>
using namespace std;
#include<string>

class Dict{
	public:
		int length;
		int maxsize;
		int *vtable;
		int *ktable;
		
		Dict(){
			length=0;
			cout<<"Enter the maximum size of table:";
			cin>>maxsize;
			
			vtable=new int [maxsize];
			ktable=new int [maxsize];
			for(int j=0;j<maxsize;j++){
				vtable[j]=-1;
				ktable[j]=-1;
			}
		}
		
		void Insert_without(int k,int v){
			int i=k%maxsize;
		if(length!=maxsize){
		
			if((vtable[i]==-1)){
					vtable[i]=v;
					ktable[i]=k;
					length++;
			}
			else{
				while(vtable[i]!=-1){
					i=(i+1)%maxsize;
				}
				vtable[i]=v;
				ktable[i]=k;
				length++;
			}
		}
		else{
			cout<<"Dictionary is full";
		}
	}
		
		void insert(int k,int v){
			int i=k%maxsize;
			if(length!=maxsize){
					
					if((ktable[i]==-1)){
						vtable[i]=v;
						ktable[i]=k;
						length++;
					}
					
					else{
						if(ktable[i]%maxsize==i){
								while(ktable[i]!=-1){
									i=(i+1)%maxsize;
								}
								vtable[i]=v;
								ktable[i]=k;
								length++;
							}
						else{
							int vt=vtable[i];
							int kt=ktable[i];
							vtable[i]=v;
							ktable[i]=k;
						
							while(ktable[i]!=-1){
								i=(i+1)%maxsize;
								    }

							vtable[i]=vt;
							ktable[i]=kt;
							length++;
					}
				}
				
			}
			else{
				cout<<"Table is full";
			}
		}
		
		void Delete(int key){
			int p=0;
			for(int i=0;i<maxsize;i++){
				if(key==ktable[i]){
					ktable[i]=-1;
					vtable[i]=-1;
					p=1;
					break;
				}	
			}
			
			if(p==0){
				cout<<"Key was not present"<<endl;
			}
			else{
				cout<<"Key has been deleted"<<endl;
			}
			length--;			
	}
		
		int find(int key){
			int i=key%maxsize;
			if(ktable[i]==key){
				return vtable[i];
			}
			else{
				for(int j=i+1;j<i+10;j=j%maxsize){
						if(ktable[j]==key){
								return vtable[j];
						}				
				}
			}
			return -1;
		}
		
		int size(){
			return length;
			}
		
		void list(){
			cout<<"___________HASH TABLE___________"<<endl<<endl;
			for(int i=0;i<maxsize;i++){
				cout<<"Sr.no("<<i<<")"<<"---> key="<<ktable[i]<<"---> value="<<vtable[i]<<endl;
			}
		}
};


int main(){
	Dict d1;
	cout<<"1.Insert with replacement"<<endl<<"2.Insert without replacement"<<endl<<"3.Delete"<<endl<<"4.find"<<endl<<"5.Display"<<endl<<"-1.Exit"<<endl<<endl;
	int ask,key,value;
	char a;
	do{
		cout<<"Enter the ask:";
		cin>>ask;
		switch(ask){
			case 1:{
				cout<<"Insert key and value:";
				cin>>key>>value;
				d1.insert(key,value);
				break;
			}
			case 2:{
				cout<<"Insert key and value:";
				cin>>key>>value;
				d1.Insert_without(key,value);
				break;
			}
			case 3:{
				cout<<"Enter key:";
				cin>>key;
				d1.Delete(key);
				break;
			}
			case 4:{\
				cout<<"Enter key:";
				cin>>key;
				cout<<"(-1 means key is prosent)    Value at key:"<<d1.find(key)<<endl;
				
				
				break;
			}
			case 5:{
				d1.list();
				break;
			}
				
		}
		
	}while(ask!=-1);
	cout<<endl<<endl;
	cout<<"Thanks";
	return 0;
	
}

