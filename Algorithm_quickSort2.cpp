#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
using namespace std;
static int first;
static int last;
class Solution{
	public:
		vector<int> sortArray(vector<int>&nums){
			if(nums.empty()){
				return nums;
			}
			quickSort(nums,0,nums.size()-1);
			return nums;
		}
		void quickSort(vector<int>&nums,int l,int r){
			if(l>=r) return;
			srand((unsigned)time(nullptr));
			int x=nums[l+(int)rand()%(r-l+1)];
			partition(l,r,x);
			int left=first;
			int right=last;
			quickSort(l,left-1);
			quickSort(right+1,r);
		}
		void partition(vector<int>&nums,int l,int r,int x){
			first=l;
			last=r;
			int i=l;
			while(i<=last){
				if(nums[i]==x){
					i++;
				}else if(nums[i]<x){
					swap(first++,i++);
				}else{
					swap(i,last--);
				}
			}
		}
		void swap(int& i,int& j){
			int temp=i;
			i=j;
			j=temp;
		}
};