#include<iostream>
using namespace std;
class MyCircularQueue{
	public:
		int* queue;//standard
		int l;
		int r;
		int size;
		int limit;
		MyCircularQueue(int k){
			queue=new int[k];
			l=r=size=0;
			limit=k;
		}
		bool enQueue(int value){
			if(isFull()){
				return false;
			}else{
				queue[r]=value;
				r=r==limit-1? 0:r+1;
				size++;
				return true;
			}
		}
		bool deQueue(){
			if(isEmpty()){
				return false;
			}else{
				l=l==limit-1?0:l+1;
				size--;
				return true;
			}
		}
		int Front(){
			if(isEmpty()){
				return -1;
			}else{
				return queue[l];
			}
		}
		int Rear(){
			if(isEmpty()){
				return -1;
			}else{
				int last=r==0?(limit-1):r-1;
	            return queue[last];
			}
		}
		bool isEmpty(){
			return size==0;
		}
		bool isFull(){
			return size==limit;
		}
};