#include<cstdio>
#include<cstring>

class CMyString{
public:
  CMyString(char* pData = nullptr);
  CMyString(const CMyString& str);
  ~CMyString(void);

  CMyString& operator = (const CMyString& str);
  void Print();
private:
  char* m_pData;
};

CMyString::CMyString(char *pData){
  if(pData == nullptr){
    m_pData = new char[1];
    m_pData[0] = '\0';
  }
  else{
    int length = strlen(pData);
    m_pData = new char[length + 1];
    strcpy(m_pData, pData);
  }
}

CMyString::CMyString(const CMyString &str){
  int length = strlen(str.m_pData);
  m_pData = new char[length + 1];
  strcpy(m_pData, str.m_pData);
}

CMyString::~CMyString(){
  delete[] m_pData;
}

//初级解法，不考虑安全性的解法，高级程序员必备
// CMyString& CMyString::operator = (const CMyString& str){
//   if(this == &str){
//     return *this;
//   }
//   delete []m_pData;
//   m_pData = nullptr;
//   m_pData = new char[strlen(str.m_pData) + 1];
//   strcpy(m_pData, str.m_pData);
//   return *this;
// }

//高级解法，考虑安全性的解法
CMyString& CMyString::operator = (const CMyString& str){
  if(this != &str){
    // 创建临时变量,作用域在if范围内，如果申请不到资源，不会改变变量值
    CMyString strTemp(str);
    char* pTemp = strTemp.m_pData;
    strTemp.m_pData = m_pData;
    m_pData = pTemp;
  }
  return *this;
}
//===================  测试代码   ====================
void CMyString::Print(){
  printf("%s", m_pData);
}

void Test1(){
  printf("Test1 begins:\n");

  char* text = "Hello world";

  CMyString str1(text);
  CMyString str2;
  str2 = str1;
  printf("The expected result is: %s.\n", text);

  printf("The actual result is: ");
  str2.Print();
  printf(".\n");
}

//赋值给自己
void Test2(){
  printf("Test2 begins:\n");
  char* text = "Hello World";

  CMyString str1(text);
  str1 = str1;

  printf("The expected result is: %s.\n", text);
  printf("The acutal result is: ");
  str1.Print();
  printf(".\n");
}
//连续赋值
void Test3(){
  printf("Test3 begins:\n");
  char* text = "Hello World";

  CMyString str1(text);
  CMyString str2, str3;
  str3 = str2 = str1;
  printf("the expected result is: %s.\n", text);

  printf("the actual result is: ");
  str2.Print();
  printf(".\n");
}

int main(int argc, char* argv[]){
  Test1();
  Test2();
  Test3();
  return 0;
}
