#include<iostream>
#include<vector>
using namespace std;
class ListNode{
	public:
		int val;
		ListNode* next;
		ListNode(int val){
			this->val=val;
			this->next=nullptr;
		}
		ListNode(int val,ListNode* next){
			this->val=val;
			this->next=next;
		}
}
class Solution{
	public:
		ListNode* mergeKLists(vector<ListNode*>&lists){
			vector<ListNode*>heap;
			for(ListNode*h:lists){
				if(h!=nullptr){
					heap.push_back(h);
				}
			}
			int n = heap.size();
            for(int i = n/2 - 1; i >= 0; i--){
                 heapify(heap, i, n);
            }//
            
			if(heap.empty()){
				return nullptr;
			}
			ListNode* h=heap[0];
			heap[0]=heap.back();
			heap.pop_back();
			heapify(heap,0,heap.size());
			ListNode* pre=h;
			
			if(pre->next!=nullptr){
				heap.push_back(pre->next);
				heapInsert(heap,heap.size()-1);
			}
			while(!heap.empty()){
				ListNode* cur=heap[0];
				heap[0]=heap.back();
				heap.pop_back();
				heapify(heap,0,heap.size());
				pre->next=cur;
				pre=cur;
				if(cur->next!=nullptr){
					heap.push_back(cur->next);
					heapInsert(heap,heap.size()-1);
				}
			}
			return h;
			
		}
		void heapify(vector<ListNode*>&heap,int i,int size){
			int l=i*2+1;
			while(l<size){
				int best=l;
				if(l+1<size){
					if(heap[l+1]->val <heap[best]->val){
						best=l+1;
					}
				}
				if(heap[best]->val >=heap[i]->val){
					break;
				}
				swap(heap,best,i);
				i=best;
				l=i*2+1;
			}
		}
		void heapInsert(vector<ListNode*>&heap,int i){
			while(i>0&& heap[i]->val<heap[(i-1)/2]->val){
				swap(heap,i,(i-1)/2);
				i=(i-1)/2;
			}
		}
		void heapSort(vector<ListNode*>&heap){
			int n=heap.size();
			for(int i=n-1;i>=0;i--){
				heapify(heap,i,n);
			}
			int size=n;
			while(size>1){
				swap(heap,0,--size);
				heapify(heap,0,size);
			}
		}
		void swap(vector<ListNode*>&heap,int i,int j){
			ListNode* temp=heap[i];
			heap[i]=heap[j];
			heap[j]=temp;
		}
};