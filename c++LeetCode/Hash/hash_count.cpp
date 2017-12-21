/**
  统计同成绩的学生人数
  题目描述：
  读入N名学生的成绩，将获得某一给定分数的学生人数输出
  输入：
  测试输入包含若干测试用例，每个测试用例的格式为
  第1行：N
  第2行：N名学生的成绩，相邻两数字用一个空格间隔
  第3行：给定分数
  当读到N=0时输入结束。其中N不超过1000，成绩分数为0到100之间的一个整数
**/
#include<iostream>
#include<stdio.h>

int main(){
  int n;
  while(scanf("%d",&n) !=EOF &&n!=0){//输入判断增加对n是否等于0的判断
    int Hash[101] = {0};
    for(int i = 0; i <= n; i++){
      int x;
      scanf("%d", &x);
      Hash[x]++;
    }
    int x;
    scanf("%d", &x);
    std::cout<<Hash[x]<<std::endl;
  }
  return 0;
}
