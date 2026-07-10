#include<iostream>
using namespace std;
void swap(int arr[],int i,int j){
	int temp=arr[i];
	arr[i]=arr[j];
	arr[j]=temp;
}
void selectionSort(int arr[],int length)
{
	if(arr==nullptr ||length<2) return;
	int minIndex;
	for(int i=0;i<length-1;i++){
		minIndex=i;
		for(int j=i+1;j<length;j++){
			if(arr[j]<arr[minIndex]) minIndex=j;
		}
		swap(arr,i,minIndex);
	}
}
void printArray(int arr[],int length){
	for(int i=0;i<length;i++){
		cout<<arr[i]<<" ";
	}
}
int main(){
	int arr[]={1,3,4,2,6};
	int len=sizeof(arr)/sizeof(arr[0]); //cpp中要用计算来求得长度
	printArray(arr,len);
	cout<<endl;
	selectionSort(arr,len);
	printArray(arr,len);
	return 0;
}