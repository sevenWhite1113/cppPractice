#include<iostream>
#include<vector>
using namespace std;
class Solution{
	public:
		int singleNumber(vector<int>& nums){
			return find(nums,3);
		}
		int find(vector<int>&nums,int m){
			int *cnts=new int[32];
			for(int i=0;i<nums.size();i++){
				for(int j=0;j<32;j++){
					cnts[j]+=(nums[i]>>j)&1;
				}
			}
			int ans=0;
			for(int k=0;k<32;k++){
				if(cnts[k]%m!=0){
					ans |=1<<k;
				}
			}
			return ans;
		}
};