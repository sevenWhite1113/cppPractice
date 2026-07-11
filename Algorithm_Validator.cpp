#include<iostream>
using namespace std;
int* randomArray(int n){
	int *arr=new int[n];
	for(int i=0;i<n;i++){
		arr[i]=rand()*10;
		
	}
	return arr;
}
int* copyArray(int arr[]){
	int len=sizeof(arr)/sizeof(arr[0]);
	int* array=new int[len];
	for(int i=0;i<len;i++){
		array[i]=arr[i];
	}
	return array;
	
}
bool sameArray(int arr1[],int arr2[]){
	int len=sizeof(arr1)/sizeof(arr1[0]);
	for(int i=0;i<len;i++){
		if(arr1[i]!=arr2[i]){
			return false;
		}
	}
	return true;
}
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
void insertionSort(int arr[],int len){
	if(arr==nullptr||len<2) return;
	for(int i=1;i<len;i++){
		for(int j=i-1;j>=0&&arr[j]>arr[j+1];j--){
			swap(arr,j,j+1);
		}
	} 
	
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
int main(){
	int n=100;
	int testTimes=500;
	cout<<"测试开始"<<endl;
	for(int i=0;i<testTimes;i++){
		int arr[]=randomArray(n);
		int arr1[]=copyArray(arr);
		int arr2[]=copyArray(arr);
		int arr3[]=copyArray(arr);
		selectionSort(arr1,n);
		insertionSort(arr2,n);
		bubbleSort(arr3,n);
		if(!sameArray(arr1,arr2)||!sameArray(arr1,arr3)){
			cout<<"Wrong"<<endl;
		}
		
	}
	cout<<"end"<<endl;
}