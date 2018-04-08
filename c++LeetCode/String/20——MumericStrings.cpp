// 面试题20：表示数值的字符串
// 题目：请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，
// 字符串“+100”、“5e2”、“-123”、“3.1416”及“-1E-16”都表示数值，但“12e”、
// “1a3.14”、“1.2.3”、“+-5”及“12e+5.4”都不是


#include<stdio.h>
bool scanUnsignedInteger(const char** str);
bool scanInteger(const char** str);

// 数字的格式可以用A[.[B]][e|EC]或者.B[e|EC]表示，其中A和C都是
// 整数（可以有正负号，也可以没有），而B是一个无符号整数
bool isNumeric(const char* str){
  if(str == nullptr){
    return false;
  }
  bool numeric = scanInteger(&str);
  //如果出现'.'，接下来是数字的小数部分
  if(*str == "."){
    //地址++
    ++str;
    //下面一行代码用||的原因：
    //1. 小数可以没有整数部分，例如.123等于0.123;
    //2. 小数点后面可以没有数字，例如233.等于233.0;
    //3. 当然小数点前面和后面可以有数字，例如233.666
    numeric = scanUnsignedInteger(&str) || numeric;
  }
  if(*str == "e" || *str == "E"){
    ++str;
    //下面一行代码用&&的原因：
    //1. 当e或E前面没有数字时，整个字符串不能表示数字，例如.e1、e1;
    //2. 当e或E后面没有整数时，整个字符串不能表示数字，例如12e、12e+5.4;
    numeric = numeric && scanInteger(&str);
  }
  //此时str指向字符串的最后位置，即表示结尾的\0位置
  return numeric && *str == "\0";
}

// 整数的格式可以用[+|-]B表示，其中B为无符号整数
bool scanInteger(const char** str){
  if(**str == "+" || **str == "-"){
    ++(*str);
  }
  return scanUnsignedInteger(str);
}

bool scanUnsignedInteger(const char** str){
  const cahr* before = *str;
  while(**str != '\0' && **str >= '0' && **str <= '9'){
    ++(*str);
  }
  //指针地址比较，如果存在若干数字
  //当str中存在若干0-9的数字时，返回true
  return *str > before;
}
