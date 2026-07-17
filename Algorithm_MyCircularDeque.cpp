#include<iostream>
using namespace std;
class MyCircularDeque{
	public:
		int* deque;
		int l;
		int r;
		int size;
		int limit;
		MyCircularDeque(int k){
			deque =new int[k];
			l=r=size=0;
			limit=k;
		}
		bool insertFront(int value) {
			if(isFull()){
				return false;
			}else{
				if(isEmpty()){
					deque[0]=value;
				}else{
					l= l==0? limit-1:l-1;
					deque[l]=value;
				}
				size++;
				return true;
			}
        
        }
    
        bool insertLast(int value) {
              if(isFull()){
              	return false;
			  }else{
			  	if(isEmpty()){
			  		deque[limit-1]=value;
				  }else{
				  	r= r==limit-1? 0:r+1;
				  	deque[r]=value;
				  }
				  size++;
				  return true;
			  }
         }
    
        bool deleteFront() {
            if(isEmpty()){
            	return false;
			}else{
				l= l==limit-1? 0:l+1;
				size--;
				return true;
			}
        }
    
        bool deleteLast() {
            if(isEmpty()){
            	return false;
			}else{
				r=r==0? limit-1:r-1;
				size--;
				return true;
			}
       }
    
         int getFront() {
         	if(isEmpty()){
         		return -1;
			 }else{
			 	return deque[l];
			 }
        
        }
    
          int getRear() {
            if(isEmpty()){
            	return -1;
			}else{
				return deque[r];
			}
        }
    
        bool isEmpty() {
        	return size==0;
         }
    
        bool isFull() {
           return size==limit;
        }
};