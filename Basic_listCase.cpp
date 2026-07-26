#include<iostream>
#include<list>
#include<string>
using namespace std;
class Person{
	public:
		string m_Name;
		int m_Age;
		int m_Height;
		Person(string name,int age,int height){
			this->m_Name=name;
			this->m_Age=age;
			this->m_Height=height;
		}
};
void printList(std::list<Person>& l){
	for(std::list<Person>::iterator it=l.begin();it!=l.end();it++){
		cout<<"name: "<<(*it).m_Name<<" age: "<<(*it).m_Age<<" height: "<<(*it).m_Height<<endl;
	}
}
bool comparePerson(Person &p1,Person &p2){
	if(p1.m_Age==p2.m_Age){
		return p1.m_Height >p2.m_Height;
	}else{
		return p1.m_Age < p2.m_Age;
	}
}
void test(){
	list<Person>L;
	Person p1("jack",18,160);
	Person p2("sam",19,170);
	Person p3("nancy",18,168);
	Person p4("bob",20,188);
	Person p5("lihua",18,155);
	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	L.push_back(p5);
	cout<<"before sort"<<endl;
	printList(L);
	cout<<"-----------------------------------------"<<endl;
	L.sort(comparePerson);
	cout<<"after sort"<<endl;
	printList(L);
	
}
int main(){
	test();
	return 0;
}