#include<iostream>
using namespace std;
template<typename T>
void mySwap(T &a,T &b){
	T temp=a;
	a=b;
	b=temp;
}

template<typename T>
void printArray(T arr,int len){
	for(int i=0;i<len;i++){
		cout<<arr[i]<<" ";
	}
}
template<typename T>
void mySort(T arr[],int len){
	for(int i=0;i<len;i++){
		int max=i;
	    for(int j=i+1;j<len;j++){
	    	if(arr[max]<arr[j]){
	    		max=j;
			}
		}
		if(max!=i) mySwap(arr[max],arr[i]);
	}
	
}

int main(){
	char charArray[]="abekfnu";
	int len1=sizeof(charArray)/sizeof(charArray[0]);
	int arr[]={1,3,4,8,5,9};
	int len2=sizeof(arr)/sizeof(arr[0]);
	mySort(charArray,len1);
	mySort(arr,len2);
	printArray(charArray,len1);
	cout<<endl;
	printArray(arr,len2);
	return 0;
}