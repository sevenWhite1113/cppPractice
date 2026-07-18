#include<iostream>
#include<vector>
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
		TreeNode (int val,TreeNode* left,TreeNode* right){
			this->val=val;
			this->left=left;
			this->right=right;
		}
		vector<int> posOrderTwoStack(TreeNode* root){
			vector<int> res;
			if(root!=nullptr){
				vector<TreeNode*> stk;
				vector<TreeNode*> coolect;
				stk.push_back(root);
				while(!stk.empty()){
					root=stk.back();
					collect.push_back(root);
					stk.pop_back();
					if(root->left!=nullptr){
						stk.push_back(root->left);
					}
					if(root->right!=nullptr){
						stk.push_back(root->right);
					}
				}
				while(!collect.empty()){
					root=collect.back();
					res.push_back(root->val);
					collect.pop_back();
				}
			}
			return res;
		}
};