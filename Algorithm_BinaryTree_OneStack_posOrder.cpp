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
		TreeNode(int val,TreeNode* left,TreeNode* right){
			this->val=val;
			this->left=left;
			this->right=right;
		}
		vector<int>postorderTraversal(TreeNode* root){
			vector<int> res;
			if(root!=nullptr){
				vector<TreeNode*> stk;
				stk.push_back(root);
				while(!stk.empty()){
					TreeNode* cur=stk.back();
					if(cur->left!=nullptr&&root!=cur->left&&root!=cur->right){
						stk.push_back(cur->left);
					}else if(cur->right!=nullptr&&root!=cur->right){
						stk.push_back(cur->right);
					}else{
						res.push_back(root->val);
						root=stk.back();
					}
				} 
			}
			return res;
		}
};