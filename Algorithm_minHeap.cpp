#include<iostream>
#include<vector>
using namespace std;
class Solution{
	public:
		vector<int> sortArray(vector<int>&nums){
			if(nums.empty()) return nums;
			for(int i=0;i<nums.size();i++){
				heapInsert(nums,i);
				heapify(nums,i,nums.size());
			}
			return nums;
			
		}
		void heapInsert(vector<int>&nums,int i){
			while(arr[i]<arr[(i-1)/2]){
				swap(nums,i,(i-1)/2);
				i=(i-1)/2;
			}
		}
		void heapify(vector<int>&nums,int i,int size){
			int l=i*2+1;
			while(l<size){
				int best= l+1<size&&nums[l+1]<nums[l]? l+1:l;
				best=nums[best]<nums[i]? best:i;
				if(best==i) break;
				swap(nums,best,i);
				i=best;
				l=i*2+1;
			}
		}
		void swap(vector<int>&nums,int i,int j){
			int temp=nums[i];
			nums[i]=nums[j];
			nums[j]=temp;
		}
};