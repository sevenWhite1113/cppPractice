#include<iostream>
#include<unordered_set>
#include<algorithm>
#include<ctime>
#include<cstdlib>
using namespace std;
class Bitset{
	public:
		int* set;
		Bitset(int n){
			int size=(n+31)/32;
			set=new int[size]();//
		}
		void add(int num){
			set[num/32]=set[num/32] | 1<<(num%32);
		}
		void remove(int num){
			set[num/32]&=~(1<<(num%32));
		}
		void reverse(int num){
			set[num/32]^=1<<(num%32);
		}
		bool contains(int num){
			return ((set[num/32]>>(num%32))&1)==1;
		}
		~Bitset(){
			delete[] set;
		}
};
int main(){
	int n=1000;
	int testTimes=10000;
	cout<<" test begin"<<endl;
	Bitset bitset(n);
	unordered_set<int> hashset;
	cout<<" diaoyong begin "<<endl;
	srand((unsigned int)time(nullptr));
	for(int i=0;i<testTimes;i++){
		double decide=1.0*rand()/RAND_MAX;
		int number=(int)(rand()%n);
		if(decide<0.333){
			bitset.add(number);
			hashset.insert(number);
		}else if(decide<0.666){
			bitset.remove(number);
			hashset.erase(number);
		}else{
			bitset.reverse(number);
			if(hashset.count(number)==1){
				hashset.erase(number);
			}else{
				hashset.insert(number);
			}
		}
	}
	cout<<"diaoyong over"<<endl;
	cout<<"check begin"<<endl;
	for(int i=0;i<n;i++){
		bool decision;
		if(hashset.count(i)==0) decision=false;
		else decision=true;
		if(bitset.contains(i)!=decision){
			cout<<"it is wrong!"<<endl;
		}
	}
	cout<<" check over"<<endl;
	cout<<"test over"<<endl;
	return 0;
}