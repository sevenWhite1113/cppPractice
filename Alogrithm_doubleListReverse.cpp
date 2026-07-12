#include<iostream>
using namespace std;
class doubleListNode{
	public:
		int val;
		doubleListNode* last;
		doubleListNode* next;
		doubleListNode(int val){
			this->val=val;
			this->last=nullptr;
			this->next=nullptr;
		}
		//single+completed
		doubleListNode(int val,doubleListNode* last,doubleListNode* next){
			this->val=val;
			this->last=last;
			this->next=next;
		}
};
void printDoubleListNode(doubleListNode* head)
{
	doubleListNode* cur=head;
	while(cur!=nullptr){
	  cout<<cur->val<<" ";
	  cur->last=cur;
	  cur=cur->next;
  }
  cout<<endl;
}
doubleListNode* doubleListReverse(doubleListNode* head){
	doubleListNode* pre=nullptr;
	doubleListNode* next=nullptr;
	while(head!=nullptr){
		next=head->next;
		head->next=pre;
		head->last=next;
		pre=head;
		head=next;
	}
	return pre;
}

int main(){
	return 0;
}