#include<iostream>
#include<map>
using namespace std;
class LRUCache{
	class DoubleNode{
		public:
			int key;
			int val;
			DoubleNode* last;
			DoubleNode* next;
			DoubleNode(int k,int v){
				this->key=k;
				this->val=v;
				this->last=nullptr;
				this->next=nullptr;
			}
			DoubleNode(int k,int v,DoubleNode* last,DoubleNode* next){
				this->key=k;
				this->val=v;
				this->last=last;
				this->next=next;
			}
	};
	class DoubleList{
		private:
			DoubleNode* head;
			DoubleNode* tail;
		public:
			DoubleList(){
				head=nullptr;
				tail=nullptr;
			}
			void addNode(DoubleNode* newNode){
				if(newNode==nullptr){
					return;
				}
				if(head==nullptr){
					head=newNode;
					tail=newNode;
				}else{
					tail->next=newNode;
					newNode->last=tail;
					tail=newNode;
				}
			}
			void moveNodeToTail(DoubleNode* node){
				if(tail==node){
					return;
				}
				if(head==node){
					head=node->next;
					head->last=nullptr;
				}else{
					(node->last)->next=node->next;
					(node->next)->last=node->last;
				}
				node->last=tail;
				node->next=nullptr;
				tail->next=node;
				tail=node;
			}
			DoubleNode* removeHead(){
				if(head==nullptr){
					return nullptr;
				}
				DoubleNode* ans=head;
				if(head==tail){
					head=nullptr;
					tail=nullptr;
				}else{
					head=ans->next;
					ans->next=nullptr;
					head->last=nullptr;
				}
				return ans;
			}
	};
	private:
		map<int,DoubleNode*>keyNodeMap;
		DoubleList nodeList;
		int capacity;
	public:
		LRUCache(int cap){
			capacity=cap;
		}
	
		int get(int key){
			if(keyNodeMap.count(key)>0){
				map<int,DoubleNode*>::iterator pos=keyNodeMap.find(key);
				DoubleNode* ans=pos->second;
				nodeList.moveNodeToTail(ans);
				return ans->val;
			}
			return -1;
		}
		void put(int key,int value){
			if(keyNodeMap.count(key)>0){
				map<int,DoubleNode*>::iterator pos=keyNodeMap.find(key);
				DoubleNode* node=pos->second;
				node->val=value;
				nodeList.moveNodeToTail(node);
			}else{
				if(keyNodeMap.size()==capacity){
					keyNodeMap.erase((nodeList.removeHead())->key);
					
				}
				DoubleNode* newNode=new DoubleNode(key,value);
				keyNodeMap[key]=value;;
				nodeList.addNode(newNode);
				
			}
		}
	
};