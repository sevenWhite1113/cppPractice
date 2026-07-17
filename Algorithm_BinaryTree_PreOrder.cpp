#include<iostream>
#include<vector>
#include<algorithms>
using namespace std;
class TreeNode{
	public:
		int val;
		TreeNode* left;
		TreeNode* right;
		TreeNode(int val){
			this->val=val;
			this->left=nullptr;
			this->right=nullptr;
		}
		TreeNode(int val,TreeNode* left,TreeNode*right){
			this->val=val;
			this->left=left;
			this->right=right;
		}
		
		vector<int> inOrderTraversal(TreeNode* root){
			vector<int> res;
			inOrder(root,res);
			return res;
		}
		void inOrder(TreeNode* head,vector<int>&arr){
			if(head==nullptr) return;
			inOrder(head->left,arr);
			arr.push_back(head->val);
			inOrder(head->right,arr);
		}
};