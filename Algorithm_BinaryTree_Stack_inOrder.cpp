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
		vector<int> inorderTraversal(TreeNode* root){
			vector<int> res;
			vector<TreeNode*> stk;
		    while(!stk.empty()||root!=nullptr){
		    	if(root!=nullptr){
		    		stk.push_back(root);
		    		root=root->left;
				}else{
					root=stk.back();
					stk.pop_back();
					res.push_back(root->val);
					root=root->right;
				}
			}
			return res;
		}
};