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
  bool operator < (const E &b) const{//利用c++运算符重载直接定义小于运算符
    // 类对象通常需要较多的存储空间，如果按值传递，必然会较大消耗“栈”空间，
    // 也需要较多的时间实施复制过程。因为const参数 const成员函数不会修改参数的内容
    // const参数 参数不可修改
    // const成员函数中，不能修改任何类成员变量
    // const成员函数不能调用非const成员函数，因为非const成员函数可以会修改成员变量
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
