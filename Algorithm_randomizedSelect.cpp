#include<iostream>
#include<vector>
#include<ctime>
#include<cstdlib>
using namespace std;
static int first;
static int last;
class Solution{
	public:
		int findKthLargest(vector<int>&nums,int k){
			return randomizeSelect(nums,nums.size()-k);
		}
		int randomizeSelect(vector<int>&nums,int i){
			int ans=0;
			int r=nums.size()-1;
			for(int l=0;l<=r; ){
				srand((unsigned)time(nullptr));
				partition(nums,l,r,nums[l+(int)rand()%(r-l+1)]);
				if(i<first){
					r=first-1;
				}else if(i>last){
					l=last+1;
				}else{
					ans=nums[i];
					break;
				}
			}
			return ans;
		}
		void partition(vector<int>&nums,int l,int r,int x){
			first=l;
			last=r;
			int i=l;
			while(i<=last){
				if(nums[i]==x){
					i++;
				}else if(nums[i]<x){
					swap(nums[first],nums[i]);
					first++;
					i++;
				}else{
					swap(nums[i],nums[last]);
					last--;
				}
			}
		}
		void swap(int&i,int&j){
			int temp=i;
			i=j;
			j=temp;
		}
};