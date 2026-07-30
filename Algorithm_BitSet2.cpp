#include<iostream>
#include<string>
using namespace std;
class Bitset{
	public:
		int s;
		int zeros;
		int ones;
		int* set;
		bool reverse;
		Bitset(int n){
			s=n;
			zeros=n;
			ones=0;
			int size=(n+31)/32;
			set=new int[size]();
			reverse=false;
		}
		void fix(int i){
			int index=i/32;
			int bit=i%32;
			if(!reverse){
				if((set[index]&(1<<bit))==0){
					zeros--;
					ones++;
					set[index]|=(1<<bit);
				}
			}else{
				if((set[index]&(1<<bit))!=0){
					zeros--;
					ones++;
					set[index]^=(1<<bit);
				}
			}
		}
		void unfix(int i){
			int index=i/32;
			int bit=i%32;
			if(!reverse){
				if((set[index]&(1<<bit))!=0){
					zeros++;
					ones--;
					set[index]&=~(1<<bit);
				}
			}else{
				if((set[index]&(1<<bit))==0){
					zeros++;
					ones--;
					set[index]^=(1<<bit);
				}
			}
		}
		void flip(){
			reverse=!reverse;
			int temp=zeros;
			zeros=ones;
			ones=temp;
		}
		bool all(){
			return ones==s;
		}
		bool one(){
			return ones>0;
		}
		int count(){
			return ones;
		}
		string toString(){
			string s1;
			int k=0;int number;int status;
			for(int i=0;i<s;k++){
				number=set[k];
				for(int j=0;j<32&&i<s;j++,i++){
					status=(number>>j)&1;
					status^=reverse ?1:0;
					s1.push_back(status? '1':'0');
				}
			}
			return s1;
		}
};