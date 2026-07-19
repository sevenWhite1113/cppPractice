#include<iostream>
#include<vector>
using namespace std;
static int MAXN=50001;
static int arr[]=new int[MAXN];
static int help[]=new int[MAXN];
class Solution{
	public:
		long smallSum(int l,int r){
			if(l==r) return 0;
			int m=(l+r)/2;
			return smallSum(l,m)+smallSum(m+1,r)+merge(l,m,r);
		}
		
		long merge(int l,int m,int r){
			long ans=0;
			for(int j=m+1;j<=r;j++){
				int i=l;
				int sum=0;
				while(i<=m&&arr[i]<=arr[j]){
					sum+=arr[i++];
				}
				ans+=sum;
			}
			int i=l;
			int a=l;
			int b=m+1;
			while(a<=m&&b<=r){
				help[i++]=arr[a]<=arr[b]? arr[a++]:arr[b++];
			}
			while(a<=m){
				help[i++]=arr[a++];
			}
			while(b<=r){
				help[i++]=arr[b++];
			}
			for(i=l;i<=r;i++){
				arr[i]=help[i];
			}
			return ans;
		}
};