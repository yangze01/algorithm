/**
题目描述：
  给你n个整数，请按从大到小的顺序输出其中前m大的数
输入：
 每组测试数据有两行，第一行有两个数n,m(0<n, m<1000000)，第二行包含n个各不相同，且
 都处于区间【-500000, 500000】的整数
输出：
 对每组测试数据按从大到小的顺序输出前m大的数。

问题：
 由于待排序数字的数量十分庞大（1000000），即使使用时间复杂度为O（nlogn）的快排，
其时间复杂度也会达到千万数量级。
 利用一个数组分别统计每一种数字是否出现，其空间复杂度依旧在题目的限定范围内。
且统计出现数字当中较大的m个数字，也仅需要从尾至头遍历这个数组，其时间复杂度仍在百万数量级
**/
#include<stdio.h>
#include<iostream>
#define OFFSET 500000
int Hash[1000001]; // Hash数组，记录每个数字是否出现，不出现为0，出现后被标记为1

int main(){
  int n,m;
  while(scanf("%d%d", &n, &m)!=EOF){
    // printf("%d %d\n",n,m);
    for(int i = -500000; i <= 500000; i++){
      Hash[i+OFFSET] = 0;
    }
    // printf("%d %d\n",n,m);
    for(int i = 1; i <= n; i++){
      int x;
      scanf("%d", &x);
      Hash[x+OFFSET] = 1; //凡是出现过的数字，该数组元素均被设置成1
    }

    // printf("%d %d\n",n,m);
    printf("the output is beginning\n");
    for(int i = 500000;i>=-500000;i--){
      if(Hash[i+OFFSET] == 1){
        printf("%d",i);
        m--;
        if(m!=0){
          printf(" ");
        }
        else{
          printf("\n");
          break;
        }
      }
    }

  }
}
