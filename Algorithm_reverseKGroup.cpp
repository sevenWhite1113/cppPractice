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
		ListNode* reverseKGroup(ListNode*head,int k){
			ListNode* start=head;
			ListNode* end=teamEnd(start,k);
			if(end==nullptr){
				return head;
			}
			head=end;
			reverse(start,end);
			ListNode* lastTeamEnd=start;
			while(lastTeamEnd->next!=nullptr){
				start=lastTeamEnd->next;
				end=teamEnd(start,k);
				if(end==nullptr){
					return head;
				}
				reverse(start,end);
				lastTeamEnd->next=end;
				lastTeamEnd=start;
			}
			return head;
		}
		ListNode* teamEnd(ListNode* s,int k){
			while(--k!=0&&s!=nullptr){
				s=s->next;
			}
			return s;
		}
		void reverse(ListNode* start,ListNode* e){
			e=e->next;
			ListNode* next=nullptr;
			ListNode* pre=nullptr;
			ListNode* cur=start;
			while(cur!=e){
				next=cur->next;
				cur->next=pre;
				pre=cur;
				cur=next;
			}
			start->next=e;
			
		}
};