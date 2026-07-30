#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Solution{
	public:
		vector<int>twoSum(vector<int>&nums,int target){
			vector<int> ans;
			map<int,int> help;
			for(int i=0;i<nums.size();i++){
				if(help.count(target-nums[i])>0){
					ans.push_back(help[target-nums[i]]);
					ans.push_back(i);
				}
				help[nums[i]]=i;
			}
			return ans;
		}
};