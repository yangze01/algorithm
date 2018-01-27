// ����������ʵ��ջ
#pragma once
#include<queue>
#include<exception>
#include<stdio.h>
#include<stdexcept>
#include<iostream>
using namespace std;

template<typename T> class CStack{
public:
  CStack(void);
  ~CStack(void);
  // �ڶ���ĩβ���һ���ڵ�
  void appendTail(const T& node);
  // ɾ�����е�ͷ�ڵ�
  T deleteTail();
  // ��ȡջ��Ԫ�ظ���
  int GetNum() const;
private:
  queue<T> q1;
  queue<T> q2;
  int nCount;
};

template <typename T> CStack<T>::CStack(void){}
template <typename T> CStack<T>::~CStack(void){}

template<typename T> CStack<T>::GetNum() const{
  return nCount;
}

template<typename T> void CStack<T>::appendTail(const T& data){
  if(q1.size() == 0 && q2.size() == 0){
    q1.push(data);
  }
  else if(q1.size() > 0){
    q1.push(data);
  }
  else if(q2.size() > 0){
    q2.push(data);
  }
}

template<typename T> T CStack<T>::deleteTail(){
  T ret;
  if(q2.size() == 0){
    while(q1.size() != 1){
      T& data = q1.front();
      q1.pop();
      q2.push(data);
    }
    ret = q1.front();
    q1.pop();
    cout<<ret<<endl;
  }
  else{
    while(q2.size() != 1){
      T& data = q2.front();
      q2.pop();
      q1.push(data);
    }
    ret = q2.front();
    q2.pop();
    cout<<ret<<endl;
  }
  --nCount;
  return ret;
}
