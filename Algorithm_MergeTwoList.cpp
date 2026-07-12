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
void printList(ListNode* head){
	ListNode* cur=head;
	while(cur!=nullptr){
		cout<<cur->val<<" ";
		cur=cur->next;
	}
	cout<<endl;
}
ListNode* mergeTwoLists(ListNode*head1,ListNode*head2){
	if(head1==nullptr||head2==nullptr){
		return head1==nullptr? head2:head1;
	}
	ListNode* head=head1->val<=head2->val? head1:head2;
	ListNode* cur1=head->next;
	ListNode* cur2=head==head1? head2:head1;
	ListNode* pre=head;
	while(cur1!=nullptr&&cur2!=nullptr){
		if(cur1->val<=cur2->val){
			pre->next=cur1;
			cur1=cur1->next;
		}else{
			pre->next=cur2;
			cur2=cur2->next;
		}
		pre=pre->next;
	}
	pre->next=cur1!=nullptr? cur1:cur2;
	return head;
}
int main(){
	ListNode* n1_3 = new ListNode(5);
    ListNode* n1_2 = new ListNode(3, n1_3);
    ListNode* h1 = new ListNode(1, n1_2);

    ListNode* n2_3 = new ListNode(6);
    ListNode* n2_2 = new ListNode(4, n2_3);
    ListNode* h2 = new ListNode(2, n2_2);
    printList(h1);
    printList(h2);
    ListNode* head=mergeTwoLists(h1,h2);
    printList(head);
    return 0;
}