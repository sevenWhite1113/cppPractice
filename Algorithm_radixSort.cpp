#include<iostream>
#include<vector>
using namespace std;
static int BASE=10;
class Solution{
	public:
		vector<int> sortArray(vector<int>&nums){
			vector<int> cnts(BASE,0);
			vector<int> help;
			if(nums.size()>1){
				int n=nums.size();
				int min=nums[0];
				for(int i=1;i<n;i++){
					if(min>nums[i]){
						min=nums[i];
					}
				}
				int max=0;
				for(int i=0;i<n;i++){
					nums[i]-=min;
				    if(max<nums[i]){
				    	max=nums[i];
					}
				}
				radixSort(nums,cnts,help,n,bits(max));
				for(int i=0;i<n;i++){
					nums[i]+=min;
				}
				
			}
		}
		int bits(int number){
			int ans=0;
			while(number>0){
				ans++;
				number/=BASE;
			}
			return ans;
		}
		void radixSort(vector<int>&nums,vector<int>&cnts,vector<int>&help,int n,int bits){
			for(int offset=1;bits>0;offset*=BASE,bits--){
				for(int i=0;i<n;i++){
					cnts[(nums[i]/offset)%BASE]++;
				}
				for(int i=1;i<BASE;i++){
					cnts[i]=cnts[i]+cnts[i-1];
				}
				for(int i=n-1;i>=0;i--){
					help[--cnts[(nums[i]/offset)%BASE]]=nums[i];
				}
				for(int i=0;i<n;i++){
					nums[i]=help[i];
				}
			}
		}
};