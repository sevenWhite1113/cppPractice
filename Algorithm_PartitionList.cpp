#include<iostream>
using namespace std;
class ListNode{
	public:
		int val;
		ListNode* next;
		ListNode(int val){
			this->val=val;
		}
		ListNode(int val,ListNode*next){
			this->val=val;
			this->next=next;
		}
};
ListNode* partitionList(ListNode* head,int x){
	ListNode* ans1=nullptr;
	ListNode* cur1=nullptr;
	ListNode* ans2=nullptr;
	ListNode* cur2=nullptr;
	ListNode* next=nullptr;
	while(head!=nullptr){
		next=head->next;
		head->next=nullptr;
		if(head->val<x){
			if(ans1==nullptr){
				ans1=head;
			}else{
			    cur1->next=head;
			}
			cur1=head;
		}else{
			if(ans2==nullptr){
				ans2=head;
			}else{
				cur2->next=head;
			}
			cur2=head;
		}
		head=next;
	}
	if(ans1==nullptr){
		return ans2;
	}
	cur1->next=ans2;
	return ans1;
}