#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution{
	public:
		vector<int> sortArray(vector<int>&nums){
			if(nums.empty()) return nums;
			vector<int> help(nums.size());
			mergeSort(nums,help);
			return nums;
		}
		void mergeSort(vector<int>&nums,vector<int>&help){
			int n=nums.size();
			for(int step=1;step<n;step*=2){
				int l=0;
				int m;
				int r;
				while(l<n){
					m=l+step-1;
					if(m+1>=n) break;
					r=min(l+(step*2)-1,n-1);
					merge(nums,help,l,m,r);
					l=r+1;
				}
			}
		}
		void merge(vector<int>&nums,vector<int>&help,int l,int m,int r){
			int i=l;
			int a=l;
			int b=m+1;
			while(a<=m&&b<=r){
				help[i++]= nums[a]<=nums[b] ? nums[a++]:nums[b++];
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
		}
};