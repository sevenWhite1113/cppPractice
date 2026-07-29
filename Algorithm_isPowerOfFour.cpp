#include<iostream>
using namespace std;
class Solution{
	public:
		bool isPowerOfFour(int n){
			if(n>0&&n==(n&(-n))){
				if(n%3==1){
					return true;
				}
			}
			return false;
		}
};