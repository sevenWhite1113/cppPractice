#include<iostream>
#include<vector>
using namespace std;
static int size;
class Solution{
	public:
		int halveArray(vector<int>&nums){
			vector<long>heap(nums.size());//
			return halfArray(nums,heap);
		}
		int halfArray(vector<int>&nums,vector<long>&heap){
			size=nums.size();
			long sum=0;
			for(int i=size-1;i>=0;i--){
				heap[i]=(long)nums[i]<<20;
				sum+=heap[i];
				heapify(heap,i);
			}
			sum/=2;
			int ans=0;
			for(long minus=0;minus<sum;ans++){
				heap[0]/=2;
				minus+=heap[0];
				heapify(heap,0);
			}
			return ans;
		}
		void heapify(vector<long>&arr,int i){
			int n=arr.size();
			int l=2*i+1;
			while(l<n){
				int best= l+1<n&&arr[l+1]>arr[l]? l+1:l;
				best=arr[best]>arr[i]?best:i;
				if(best==i){
					break;
				}
				swap(arr,best,i);
				i=best;
				l=2*i+1;
			}
		}
		void swap(vector<long>&heap,int i,int j){
			long temp=heap[i];
			heap[i]=heap[j];
			heap[j]=temp;
		}
		
};