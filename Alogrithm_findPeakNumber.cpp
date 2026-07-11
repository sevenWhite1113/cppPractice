#include<iostream>
using namespace std;
int findPeakElement(int arr[],int length){
	int n=length;
	if(n==1){
		return 0;
	}
	if(arr[0]>arr[1]){
		return 0;
	}
	if(arr[n-1]>arr[n-2]){
		return n-1;
	}
	int l=1;
	int r=n-2;
	int m=0;
	int ans=-1;
	while(l<=r){
		m=(l+r)/2;
		if(arr[m-1]>arr[m]){
			r=m-1;
		}else if(arr[m+1]>arr[m]){
			l=m+1;
		}else{
			ans=m;
			break;
		}
	}
	return ans;
}
int main(){
	int arr[]={4,2,1,6,9,8,0};
	int length=sizeof(arr)/sizeof(arr[0]);
	cout<<findPeakElement(arr,length);
	return 0;
}