#include<iostream>
using namespace std;
class ListNode{
   public:
   	int val;
   	ListNode* next;
   	ListNode(int val){
   		this->val=val;
	   }
	ListNode(int val,ListNode* next){
		this->val=val;
		this->next=next;
	}
};
ListNode* addTwoNumbers(ListNode* h1,ListNode* h2){
	ListNode* ans=nullptr;
	ListNode* cur=nullptr;
	int carry=0;
	for(int sum=0;h1!=nullptr||h2!=nullptr;h1=(h1==nullptr)? nullptr:h1->next,h2=(h2==nullptr)?nullptr:h2->next){
		int val=0;
		sum=(h1==nullptr?0:h1->val)+(h2==nullptr?0:h2->val)+carry;
		val=sum%10;
		carry=sum/10;
		if(ans==nullptr){
			ans=new ListNode(val);
			cur=ans;
		}else{
			cur->next=new ListNode(val);
			cur=cur->next;
		}
	}
	if(carry==1){
		cur->next=new ListNode(1);
	}
	return ans;
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
	ListNode* p3= new ListNode(9);
	ListNode* p2=new ListNode(8,p3);
	ListNode* p1=new ListNode(4,p2);
	
	ListNode* n4=new ListNode(9);
	ListNode* n3=new ListNode(7,n4);
	ListNode* n2=new ListNode(6,n3);
	ListNode* n1=new ListNode(2,n2);
	
	ListNode* head=addTwoNumbers(n1,p1);
	printList(head);
	return 0;
}