/**
��Ŀ������
  ����һ����n��Ȼ������n����ֵ������ͬ��������һ��ֵx,������ֵ����������е��±ꡣ
����0��ʼ�������������������-1��
���룺
  ���������ж��飬����n��1<=n<=200������������n������Ȼ������x��
�����
  ����ÿ�����룬��������
**/

#include<stdio.h>
#include<iostream>
int main(){
  int buf[200];
  int n;
  while(scanf("%d", &n)!=EOF){
    for(int i = 0; i<n;i++){
      scanf("%d", &buf[i]);
    }
    int x,ans = -1;
    for(int i = 0; i < n; i++){
      if(x==buf[i]){
        ans = i;
        break;
      }
    }
    printf("%d\n",ans);
  }
  return 0;
}
