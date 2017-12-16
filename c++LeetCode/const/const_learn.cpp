#include<iostream>
using namespace std;

void testModifyConst(const int _x){
  // 2. const修饰函数参数
  // _x = 5; // 传递过来的参数不可改变
  cout<<_x<<endl;
}

class Point{
  //3. const修饰成员函数
public:
  Point(int _x):x(_x){}

  void testConstFunction(int _x) const{
    cout<<"in the const member function"<<endl;
    cout<<"the x and _x is "<<x<<" "<<_x<<endl;
    //错误，在const成员函数中，不能修改任何类成员变量
    // x = _x;

    //错误，const成员函数不能调用非const成员函数，因为非const成员函数可能会修改成员变量
    // modify_x(_x);
  }

  void modify_x(int _x){
    x = _x;
    // return x;
  }

  int x;
};

//4. const 修饰函数返回值
//(1) 指针传递
const int * mallocA(){//const data, non-const pointer
// 如果返回const data, non-const pointer, 返回值也必须赋给const data,
// non-const pointer. 因为指针指向的数据是常量不能修改
  int *a = new int(2);
  return a;
}
//(2) 值传递
// 如果函数返回值采用“值传递方式”，
// 由于函数会把返回值复制到外部临时的存储单元中，加const修饰没有任何价值。
// 不要把函数int GetInt(void) 携程const int GetInt(void)
// 不要把函数A GetA(void) 写成 const A GetA(void)，其中A为用户自定义的数据类型

int main(){
  // 1. const 修饰成员变量
  int a1 = 3;
  const int a2 = a1;

  int * a3 = &a1; // non-const data, non-const pointer
  const int * a4 = &a1; // const data, non-const pointer
  int * const a5 = &a1; // non-const data, const pointer
  int const * const a6 = &a1; // const data, const pointer
  const int * const a7 = &a1; // const data, const pointer
  // *a4 = 6;
  *a5 = 6;
  // *a6 = 5;
  cout<<*a3<<" "<<*a4<<" "<<*a5<<" "<<*a6<<endl;

  // 2. const 修饰函数参数
  testModifyConst(5);

  // 3. const修饰成员函数
  Point a(5);
  // *a = new Point(5);
  a.testConstFunction(8);
  a.modify_x(3);
  cout<<a.x<<endl;

  //4. const修饰函数返回值
  const int *a = mallocA();
  // int *b = mallocA();

  return 0;
}
