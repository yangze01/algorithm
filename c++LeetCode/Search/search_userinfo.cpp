/**
题目描述：
 输入N个学生的信息，然后进行查询。
输入：
 输入的第一行为N，即学生的个数(N<=1000)
接下来的N行包括N个学生的信息，信息格式如下：
01 李江 男 21
02 刘唐 男 23
03 张军 男 19
04 王娜 女 19
然后输入一个M(M<=10000),接下来会有M行，代表M次查询，每行输入一个学号，格式如下：
02
03
01
04
输出：
 输出M行，每行包括一个对应于查询的学生的信息。
 如果没有对应的学生信息，则输出“No Answer!”
**/
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<string>
struct Student{
  std::string no;
  std::string name;
  int age;
  std::string sex;
  bool operator < (const Student & A) const{//重载小于运算符使得其能使用Sort函数排序
    return no.compare(A.no) < 0;
  }
}buf[1000];

int main(){
  int n;
  while(scanf("%d", &n)!=EOF){
    printf("%d\n", n);
    for(int i = 0; i<n; i++){
      scanf("%s%s%s%d", buf[i].no, buf[i].name, buf[i].sex, &buf[i].age);
    }
    std::sort(buf, buf+n);
    int t;
    scanf("%d", &t); //有t组询问
    while(t--!=0){//while循环保证查询次数为t
      printf("the t is %d\n", t);
      int ans = -1;
      std::string x;
      scanf("%s",x);//待查找的学号3
      int top = n-1, base = 0;//初始时，开始下标为0，结束下标为n-1，
      while(top>=base){//当查找子集部位空集时重复二分查找
        int mid = (top+base)/2;
        int tmp = buf[mid].no.compare(x);
        if(tmp == 0){
          ans = mid;
          break;
        }
        else if(tmp > 0){
          top = mid-1;
        }
        else{
          base = mid+1;
        }
        if(ans == -1){
          printf("No Answer!\n");
        }
        else{
          printf("%s %s %s %d\n", buf[ans].no, buf[ans].name, buf[ans].sex, buf[ans].age);
        }
      }
    }
  }
}
