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
		vector<int> preorderTraversal(TreeNode* root){
			vector<int> res;
			vector<TreeNode*> stk;
			if(root!=nullptr){
				stk.push_back(root);
				while(!stk.empty()){
					root=stk.back();
					stk.pop_back();
					res.push_back(root->val);
					if(root->right!=nullptr){
						stk.push_back(root->right);
					}
					if(root->left!=nullptr){
						stk.push_back(root->left);
					}
					
				}
			}
			return res;
		}
		
		
};