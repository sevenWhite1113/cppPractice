#include<iostream>
using namespace std;
void printArray(int arr[],int len){
	for(int i=0;i<len;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
void swap(int arr[],int i,int j){
	int temp=arr[i];
	arr[i]=arr[j];
	arr[j]=temp;
}
void insertionSort(int arr[],int len){
	if(arr==nullptr||len<2) return;
	for(int i=1;i<len;i++){
		for(int j=i-1;j>=0&&arr[j]>arr[j+1];j--){
			swap(arr,j,j+1);
		}
	} 
	
}
int main(){
	int arr[]={1,4,2,3,6,8,9};
	int length=sizeof(arr)/sizeof(arr[0]);
	printArray(arr,length);
	insertionSort(arr,length);
	printArray(arr,length);
}