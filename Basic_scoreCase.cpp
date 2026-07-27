#include<iostream>
#include<vector>
#include<string>
#include<cstdlib>
#include<ctime>
#include<deque>
#include<algorithm>
using namespace std;
class Person{
	public:
		string m_Name;
		int m_Score;
		Person(string name,int score){
			this->m_Name=name;
			this->m_Score=score;
		}
};
void createPerson(vector<Person>&v){
	string nameSeed="ABCDE";
	for(int i=0;i<5;i++){
		string name="member";
		name+=nameSeed[i];
		int score=0;
		Person p(name,score);
		v.push_back(p);
	}
}
void showScore(std::vector<Person>&v){
	for(std::vector<Person>::iterator it=v.begin();it!=v.end();it++)
	{
		cout<<(*it).m_Name<<" "<<(*it).m_Score<<endl;
	}
}
void setScore(std::vector<Person>&v){
	srand((unsigned)time(nullptr));
	for(std::vector<Person>::iterator it=v.begin();it!=v.end();it++){
		deque<int>d;
		for(int i=0;i<10;i++){
			int score=rand()%41+60;
			d.push_back(score);
		}
		sort(d.begin(),d.end());
		d.pop_back();
		d.pop_front();
		int sum=0;
		for(std::deque<int>::iterator dit=d.begin();dit!=d.end();dit++){
			sum+=(*dit);
		}
		int avg=sum/d.size();
		it->m_Score=avg;
	}
}
int main(){
	vector<Person>v;
	createPerson(v);
	showScore(v);
	setScore(v);
	cout<<"----------------------------------------"<<endl;
	showScore(v);
	
	return 0;
}