#include<iostream>
using namespace std;
class Solution{
	public:
		int flip(int n){
			return n^1;
		}
		int sign(int n){
			return flip(n>>>31);
		}
		int getMax(int a,int b){
			int c=a-b;
			int sa=sign(a);
			int sb=sign(b);
			int sc=sign(c);
			int diffAB=sa^sb;
			int sameAB=flip(diffAB);
			int returnA=diffAB*sa+sameAB*sc;
			int returnB=flip(returnA);
			return a*returnA+b*returnB;
		}
};