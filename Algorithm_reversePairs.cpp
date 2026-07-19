#include<iostream>
#include<vector>
using namespace std;
class Solution{
	public:
		int reversePairs(vector<int>&nums){
			vector<int> help(nums.size());
			return counts(nums,help,0,nums.size()-1);
		}
		int counts(vector<int>&nums,vector<int>&help,int l,int r){
			if(l==r) return 0;
			int m=(l+r)/2;
			return counts(nums,help,l,m)+counts(nums,help,m+1,r)+merge(nums,help,l,m,r);
		}
		int merge(vector<int>&nums,vector<int>&help,int l,int m,int r){
			int ans=0;
			int j=m+1;
			for(int i=l;i<=m;i++){
				while(j<=r&&(long)nums[i]>(long)nums[j]*2){
					j++;
				}
				ans+=j-m-1;
			}
			int i=l;
			int a=l;
			int b=m+1;
			while(a<=m&&b<=r){
				help[i++]= nums[a]<=nums[b]? nums[a++]:nums[b++];
			}
			while(a<=m){
				help[i++]=nums[a++];
			}
			while(b<=r){
				help[i++]=nums[b++];
			}
			for(i=l;i<=r;i++){
				nums[i]=help[i];
			}
			return ans;
		}
};