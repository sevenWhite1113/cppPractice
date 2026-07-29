#include<iostream>
#include<cstdint>
using namespace std;
class Solution{
	public:
		int hammingDistance(int x,int y){
			return cutOnes(x^y);
		}
		uint32_t cutOnes(uint32_t n){
			n=(n&0x55555555)+((n>>1)&0x55555555);
			n=(n&0x33333333)+((n>>2)&0x33333333);
			n=(n&0x0f0f0f0f)+((n>>4)&0x0f0f0f0f);
			n=(n&0x0000ffff)+((n>>16)&0x0000ffff);
			return n;
		}
};