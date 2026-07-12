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
ListNode* listReverse (ListNode* head){
	ListNode* pre=nullptr;
	ListNode* next=nullptr;
	while(head!=nullptr){
		next=head->next;
		head->next=pre;
		pre=head;
		head=next;
		
	}
	return pre;
}
void printList(ListNode* head){
	ListNode* cur=head;
	while(cur!=nullptr){
		cout<<cur->val<<" ";
		cur=cur->next;
	}
	cout<<endl;
}
int main(){
	// 尾插构造 1 2 3 4 5
ListNode* n5 = new ListNode(5);
ListNode* n4 = new ListNode(4, n5);
ListNode* n3 = new ListNode(3, n4);
ListNode* n2 = new ListNode(2, n3);
ListNode* head = new ListNode(1, n2);
printList(head);
ListNode* rev=listReverse(head);
printList(rev);
return 0;
}