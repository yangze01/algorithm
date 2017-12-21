/**
��Ŀ������
 ����N��ѧ������Ϣ��Ȼ����в�ѯ��
���룺
 ����ĵ�һ��ΪN����ѧ���ĸ���(N<=1000)
��������N�а���N��ѧ������Ϣ����Ϣ��ʽ���£�
01 � �� 21
02 ���� �� 23
03 �ž� �� 19
04 ���� Ů 19
Ȼ������һ��M(M<=10000),����������M�У�����M�β�ѯ��ÿ������һ��ѧ�ţ���ʽ���£�
02
03
01
04
�����
 ���M�У�ÿ�а���һ����Ӧ�ڲ�ѯ��ѧ������Ϣ��
 ���û�ж�Ӧ��ѧ����Ϣ���������No Answer!��
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
  bool operator < (const Student & A) const{//����С�������ʹ������ʹ��Sort��������
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
    scanf("%d", &t); //��t��ѯ��
    while(t--!=0){//whileѭ����֤��ѯ����Ϊt
      printf("the t is %d\n", t);
      int ans = -1;
      std::string x;
      scanf("%s",x);//�����ҵ�ѧ��3
      int top = n-1, base = 0;//��ʼʱ����ʼ�±�Ϊ0�������±�Ϊn-1��
      while(top>=base){//�������Ӽ���λ�ռ�ʱ�ظ����ֲ���
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
