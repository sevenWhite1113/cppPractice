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
			this->val=val;
			this->next=next;
		}
};
class Solution{
	public:
		bool isPalindrome(ListNode* head){
			if(head==nullptr||head->next==nullptr){
				return true;
			}
			ListNode* slow=head;
			ListNode* fast=head;
			while(fast->next!=nullptr&&(fast->next)->next!=nullptr){
				slow=slow->next;
				fast=(fast->next)->next;
			}
			ListNode* pre=slow;
			ListNode* cur=pre->next;
			ListNode* next=nullptr;
			pre->next=nullptr;
			while(cur!=nullptr){
				next=cur->next;
				cur->next=pre;
				pre=cur;
				cur=next;
			}
			bool ans=true;
			ListNode* left=head;
			ListNode* right=pre;
			while(left!=nullptr&&right!=nullptr){
				if(left->val!=right->val){
					ans=false;
					break;
				}
				left=left->next;
				right=right->next;
			}
			cur=pre->next;
			pre->next=nullptr;
			next=nullptr;
			while(cur!=nullptr){
				next=cur->next;
				cur->next=pre;
				pre=cur;
				cur=next;
			}
			return ans;
		}
};