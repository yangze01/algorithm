#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<string>
// #include<string>
struct E{
  std::string name;
  int age;
  int score;
  bool operator < (const E &b) const{//����c++���������ֱ�Ӷ���С�������
    // �����ͨ����Ҫ�϶�Ĵ洢�ռ䣬�����ֵ���ݣ���Ȼ��ϴ����ġ�ջ���ռ䣬
    // Ҳ��Ҫ�϶��ʱ��ʵʩ���ƹ��̡���Ϊconst���� const��Ա���������޸Ĳ���������
    // const���� ���������޸�
    // const��Ա�����У������޸��κ����Ա����
    // const��Ա�������ܵ��÷�const��Ա��������Ϊ��const��Ա�������Ի��޸ĳ�Ա����
    if(score!=b.score) return score < b.score;
    int tmp = name.compare(b.name);
    if(tmp!=0) return tmp < 0;
    else return age < b.age;
  }
}buf[1000];
// using namespace std;
int main(){
  std::string a = "asd";
  std::cout<<"hello world!"<<std::endl;
  int n;
  while(std::cin>>n){
    for(int i = 0; i < n; i++){
      std::cin>>buf[i].name>>buf[i].age>>buf[i].score;
    }
    std::sort(buf, buf + n);
    for(int i = 0; i < n; i++){
      std::cout<<"the output of data is: "<<std::endl;
      std::cout<<buf[i].name<<" "<<buf[i].age<<" "<<buf[i].score<<std::endl;
    }
  }
  return 0;
}
