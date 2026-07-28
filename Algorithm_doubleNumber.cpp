#include<iostream>
#include<vector>
using namespace std;
class Solution{
	public:
		vector<int> singleNumber(vector<int>& nums){
			vector<int> ans;
			int eor1=0;
			for(int i=0;i<nums.size();i++){
				eor1^=nums[i];
			}
			int eor2=0;
			unsigned int temp=(unsigned int)eor1;
			unsigned int rightOne=temp&(-temp);
			for(int j=0;j<nums.size();j++){
				if(((unsigned int)nums[j]&rightOne)==0){
					eor2^=nums[j];
				}
			}
			ans.push_back(eor2);
			ans.push_back(eor2^eor1);
			return ans;
		}
};