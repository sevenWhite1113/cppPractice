#include<iostream>
#include<vector>
using namespace std;
class Solution{
	public:
		vector<int> sortArray(vector<int>&nums){
			if(nums.empty()){
				return nums;
			}
			heapSort2(nums);
			return nums;
			
		}
		void heapSort1(vector<int>&nums){
			int n=nums.size();
			for(int i=0;i<n;i++){
				heapInsert(nums,i);
			}
			int size=n;
			while(size>1){
				swap(nums,0,--size);
				heapify(nums,0,size);
			}
		}
		void heapSort2(vector<int>&nums){
			int n=nums.size();
			for(int i=n-1;i>=0;i++){
				heapify(nums,i,n);
			}
			int size=n;
			while(size>1){
				swap(nums,0,--size);
				heapify(nums,0,size);
			}
		}
		
		void heapInsert(vector<int>&arr,int i){
			while(arr[i]>arr[(i-1)/2]){
				swap(arr,i,(i-1)/2);
				i=(i-1)/2;
			}
		}
		
		void heapify(vector<int>&nums,int i,int size){
			int l=i*2+1;
			while(l<size){
				int best =l+1<size&&nums[l+1]>nums[l] ? l+1:l ;
				best=nums[best]>nums[i]? best:i;
				if(best==i){
					break;
				}
				swap(nums,best,i);
				i=i*2+1;
			}
		}
		void swap(vector<int>&nums,int i,int j){
			int temp=nums[i];
			nums[i]=nums[j];
			nums[j]=temp;
		}
		
};