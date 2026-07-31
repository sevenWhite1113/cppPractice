#include<iostream>
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
			this->val;
			this->next=next;
		}
};
class Solution{
	public:
	ListNode* detectCycle(ListNode* head){
		if(head==nullptr ||head->next==nullptr||(head->next)->next==nullptr){
			return nullptr;
		}
		ListNode* slow=head->next;
		ListNode* fast=(head->next)->next;
		while(slow!=fast){
			if(fast->next==nullptr ||(fast->next)->next==nullptr){
				return nullptr;
			}
			slow=slow->next;
			fast=(fast->next)->next;
		}
		fast=head;
		while(slow!=fast){
			slow=slow->next;
			fast=fast->next;
		}
		return slow;
	}
};