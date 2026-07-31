#inlcude<iostream>
#include<cstdlib>
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
};
class Solution{
	public:
		ListNode* getIntersectionNode(ListNode* h1,ListNode* h2){
			if(h1==nullptr||h2==nullptr){
				return nullptr;
			}
			ListNode* a=h1;
			ListNode* b=h2;
			int diff=0;
			while(a->next!=nullptr){
				a=a->next;
				diff++;
			}
			while(b->next!=nullptr){
				b=b->next;
				diff--;
			}
			if(a!=b){
				return nullptr;
			}
			if(diff>=0){
				a=h1;
				b=h2;
			}else{
				a=h2;
				b=h1;
			}
			diff=abs(diff);
			while(diff!=0){
				a=a->next;
				diff--;
			}
			while(a!=b){
				a=a->next;
				b=b->next;
			}
			return a;
		}
};