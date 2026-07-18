#include<iosteam>
#include<vector>
using namespace std;
class Solution{
	public:
		vector<int> sortArray(vector<int>& nums){
			if(nums.empty()) return nums;
			vector<int> help(nums.size());
			mergeSort(nums,help,0,nums.size()-1);
			return nums;
			
		}
		void mergeSort(vector<int>&nums,vector<int>&help,int l,int r){
			if(l==r) return;
			int m=(l+r)/2;
			mergeSort(nums,help,l,m);
			mergeSort(nums,help,m+1,r);
			merge(nums,help,l,m,r);
		}
		void merge(vector<int>& nums,vector<int>&help,int l,int m,int r){
			int i=l;
			int a=l;
			int b=m+1;
			while(a<=m&&b<=r){
				help[i++]=nums[a] <=nums[b] ? nums[a++]:nums[b++];
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