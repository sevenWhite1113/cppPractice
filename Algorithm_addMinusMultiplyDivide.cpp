#include<iostream>
#include<climits>
static int min=INT_MIN;
using namespace std;
class Solution{
	public:
		int divide(int a,int b){
			if(a==min&&b==min){
				return 1;
			}
			if(a!=min&&b!=min){
				return div(a,b);
			}
			if(b==min){
				return 0;
			}
			if(b==neg(1)){
				return INT_MAX;
			}
			a=add(a,b>0? b:neg(b));
			int ans=div(a,b);
			int offset=b>0?neg(1):1;
			return add(ans,offset);
		}
		int add(int a,int b){
			int ans=a;
			while(b!=0){
				ans=a^b;
				b=(a&b)<<1;
				a=ans;
			}
			return ans;
		}
		int neg(int n){
			return add(~n,1);
		}
		int minus(int a,int b){
			return add(a,neg(b));
		}
		int multiply(int a,int b){
			int ans=0;
			while(b!=0){
				if((b&1)!=0){
					ans=add(ans,a);
				}
				a<<=1;
				b=(int)((unsigned int)b>>1);
			}
			return ans;
		}
		int div(int a,int b){
			int x= a<0 ? neg(a):a;
			int y=b<0? neg(b):b;
			int ans=0;
			for(int i=30;i>=0;i=minus(i,1)){
				if((x>>1)>=y){
					ans |=(i<<i);
					x=minus(x,y<<i);
				}
			}
			return (a<0^b<0) ? neg(ans):ans;
		}
};