#include<iostream>
using namespace std;
int findRight(int arr[],int length,int num){
	int l=0;
	int r=length-1;
	int m=0;
	int ans=-1;
	while(l<=r){
		m=(l+r)/2;
		if(arr[m]<=num){
			ans=m;
			l=m+1;
		}else{
			r=m-1;
		}
	}
	return ans;
}
int main(){
	int arr[]={1,2,3,4,5,6,7,8,9};
	int length=sizeof(arr)/sizeof(arr[0]);
	cout<<findRight(arr,length,7);
	return 0;
}