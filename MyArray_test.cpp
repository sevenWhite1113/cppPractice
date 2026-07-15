#include<iostream>
#include<string>
using namespace std;
class Person
{
	public:
		string m_Name;
		int m_Age;
		Person(){	}//
		Person(string name,int age){
			this->m_Age=age;
			this->m_Name=name;
		}
		friend ostream& operator<<(ostream& os, const Person& p);
};
#include"MyArray.hpp"
void printIntArray(MyArray<int>&arr){
	for(int i=0;i<arr.getSize();i++){
		cout<<arr[i]<<endl;
	}
}

ostream& operator<<(ostream& os, const Person& p)
{
    os << p.m_Name << "," << p.m_Age;
    return os;
}
void printPersonArray(MyArray<Person>&arr){
	for(int i=0;i<arr.getSize();i++){
		cout<<arr[i]<<endl;
	}
}
int main()
{
	MyArray<int>arr1(5);
	MyArray<int>arr2(arr1);
	MyArray<int>arr3(100);
	arr3=arr1;
	for(int i=0;i<5;i++){
		arr1.Push_Back(i);
	}
	printIntArray(arr1);
	MyArray<Person>arr(10);
	Person p1("xiaom",10);
	Person p2("xiaoh",9);
	arr.Push_Back(p1);
	arr.Push_Back(p2);
	printPersonArray(arr);
	return 0;
}