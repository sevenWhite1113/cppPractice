#include<iostream>
#include<cstdint>
using namespace std;
class Solution{
	public:
		int reverseBits(int n){
		    return reverseBits32(n);
		}
		uint32_t reverseBits32(uint32_t n){
			n=((n&0xaaaaaaaa)>>1) | ((n&0x55555555)<<1);
			n=((n&0xcccccccc)>>2) | ((n&0x33333333)<<2);
			n=((n&0xf0f0f0f0)>>4) | ((n&0x0f0f0f0f)<<4);
			n=((n&0xff00ff00)>>8) | ((n&0x00ff00ff)<<8);
			n=(n>>16)|(n<<16);
			return n;
		}
};
int main(){
	Solution solution;
	cout<<solution.reverseBits(2147483644)<<endl;
	return 0;
}