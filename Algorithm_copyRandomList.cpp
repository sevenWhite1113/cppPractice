#include<iostream>
using namespace std;
class ListNode{
	public:
		int val;
		ListNode* next;
		ListNode* random;
		ListNode(int val){
			this->val=val;
			this->next=nullptr;
			this->random=nullptr;
		}
		ListNode(int val,ListNode* next,ListNode* random){
			this->val=val;
			this->next=next;
			this->random=random;
		}
};
class Solution{
	public:
		ListNode* copyRandomList(ListNode* head){
			if(head==nullptr) return nullptr;
			ListNode* cur=head;
			ListNode* next=nullptr;
			while(cur!=nullptr){
				next=cur->next;
				cur->next=new ListNode(cur->val);
				(cur->next)->next=next;
				cur=next;
			}
			cur=head;
			ListNode* copy=nullptr;
			while(cur!=nullptr){
				next=(cur->next)->next;
				copy=cur->next;
				copy->random=cur->random!=nullptr ? (cur->random)->next : nullptr;
				cur=next;
			}
			ListNode* ans=head->next;
			cur=head;
			while(cur!=nullptr){
				next=(cur->next)->next;
				copy=cur->next;
				cur->next=next;
				copy->next = next!=nullptr? next->next :nullptr;
				cur=next;
			}
			return ans;
		}
};