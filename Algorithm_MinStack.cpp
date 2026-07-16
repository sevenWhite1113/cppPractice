#include<iostream>
using namespace std;
class MinStack{
	public:
		int MAX=8001;
		int* data;
		int* min;
		int size;
		MinStack(){
			data= new int[MAX];
			min= new int[MAX];
			size=0;
		}
		void push(int val){
			data[size]=val;
			if(size==0||val<=min[size-1]){
				min[size]=val;
			}else{
				min[size]=min[size-1];
			}
			size++;
		}
		void pop(){
			size--;
		}
		int top(){
			return data[size-1];
		}
		int getMin(){
			return min[size-1];
		}
};