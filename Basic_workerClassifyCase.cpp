#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<map>
using namespace std;
class Worker{
	public:
		string m_Name;
		int m_Salary;
};
void createWorker(vector<Worker>&v){
	srand((unsigned)time(nullptr));
	string nameSeed="ABCDEFGHIJ";
	for(int i=0;i<10;i++){
		Worker worker;
		worker.m_Name="worker";
		worker.m_Name+=nameSeed[i];
		worker.m_Salary=rand()%10001+10000;
		v.push_back(worker);
	}
}
void showWorker(std::vector<Worker>&v){
	for(std::vector<Worker>::iterator it=v.begin();it!=v.end();it++){
		cout<<(*it).m_Name<<" "<<(*it).m_Salary<<endl;
	}
}
void setGroup(std::vector<Worker>&v,std::multimap<int,Worker>&m){
	for(std::vector<Worker>::iterator it=v.begin();it!=v.end();it++){
		int deptId=rand()%3;
		m.insert(make_pair(deptId,*it));
	}
}
void showWorkerByGroup(multimap<int,Worker>&m){
	cout<<"departmentA"<<endl;
	multimap<int,Worker>::iterator pos=m.find(0);
	int count=m.count(0);
	for(int index=0;pos!=m.end()&&index<count;pos++,index++){
		cout<<pos->second.m_Name<<" "<<pos->second.m_Salary<<endl;
	}
	cout<<"departmentB"<<endl;
	pos=m.find(1);
	int count2=m.count(1);
	for(int i=0;pos!=m.end()&&i<count2;pos++,i++){
		cout<<pos->second.m_Name<<" "<<pos->second.m_Salary<<endl;
	}
	cout<<"departmentC"<<endl;
	pos=m.find(2);
	int count3=m.count(2);
	for(int j=0;pos!=m.end()&&j<count3;pos++,j++){
		cout<<pos->second.m_Name<<" "<<pos->second.m_Salary<<endl;
	}
}
int main(){
	vector<Worker>vWorker;
	createWorker(vWorker);
	showWorker(vWorker);
	cout<<"-----------------------------------------------------"<<endl;
	multimap<int,Worker>mWorker;
	setGroup(vWorker,mWorker);
	showWorkerByGroup(mWorker);
	return 0;
}