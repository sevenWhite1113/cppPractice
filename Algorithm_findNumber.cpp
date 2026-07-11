#include<iostream>
using namespace std;
bool findNumber(int arr[],int num){
	int length=sizeof(arr)/sizeof(arr[0]);
	if(arr==nullptr||length==0){
		return false;
	}
	int l=0;
	int r=length-1;
	int m=0;
	while(l<=r){
		m=(l+r)/2;
		if(arr[m]==num){
			return true;
		}else if(arr[m]>num){
			r=m-1;
		}else{
			l=m+1;
		}
	}
	return false;
}
int main(){
	int arr[]={1,2,3,4,5,6,7,8,9};
	findNumber(arr,4);
	return 0;
}