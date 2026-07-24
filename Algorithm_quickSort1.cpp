#include<iostream>
#include<vector>
#include<algorithm>
#include<ctime>
#include<cstdlib>
using namespace std;
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
			srand((unsigned)time(nullptr));
			if(l>=r) return;
			int x=nums[l+(int)rand()%(r-l+1)];
			int mid=partition(nums,l,r,x);
			quickSort(l,mid-1);
			quickSort(mid+1,r);
		}
		int partition(vector<int>&nums,int l,int r,int x){
			int a=l;
			int xi=0;
			for(int i=l;i<=r;i++){
				if(nums[i]<=x){
					swap(a,i);
					if(nums[a]==x){
						xi=a;
					}
					a++;
				}
			}
			swap(xi,a-1);
			return a-1;
		}
		void swap(int& i,int& j){
			int temp=i;
			i=j;
			j=temp;
		}
};