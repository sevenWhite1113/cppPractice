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
void bubbleSort(int arr[],int len){
	for(int i=0;i<len;i++){
		for(int j=i+1;j<len;j++){
			if(arr[j]<arr[i]){
				swap(arr,i,j);
			}
		}
	}
}
int main(){
	int arr[]={1,4,3,6,8,2,5};
	int length=sizeof(arr)/sizeof(arr[0]);
	printArray(arr,length);
	bubbleSort(arr,length);
	printArray(arr,length);
}