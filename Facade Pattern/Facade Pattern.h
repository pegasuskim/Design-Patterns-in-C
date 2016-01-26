



/*
Facade pattern ���� 
���� �ý��� ���� �����ϰ� ���� �ִ� ���� ��ü�� ��ȣ �������踦 �����ؼ� 
���� ����(higher-level) �� �������̽��� �����ϴ� ������ �Ѵ�. 

- ����ҵ��� ����

- Facade: �ý����� �����ϰ� �ִ� ���� ������ �������� â���� ������ �Ѵ�. 
���� ����������  ������ �������̽��� �ý��� �ܺο� �����Ѵ�.
*/


// Facade Pattern
#include <iostream.h>
namespace Facade {
 // "SubSystem"
 class SusSystem1 {
  // Methods
  public:
   void Method1(){
    cout << " SusSystem1 Method1 \n";
   }
 };


 class SusSystem2 {
  // Methods
  public:
   void Method2(){
    cout << " SusSystem2 Method2 \n";
   }
 };
 class SusSystem3 {
  // Methods
  public:
   void Method3(){
    cout << " SusSystem3 Method3 \n";
   }
 };
 class SusSystem4 {
  // Methods
  public:
   void Method4(){
    cout << " SusSystem4 Method4 \n";
   }
 };
 
 // "Facade"
 class Facade {
  // Fields
  private:
   SusSystem1 one;
   SusSystem2 two;
   SusSystem3 three;
   SusSystem4 four;
  // Methods
  public:
   void MethodA() {
    cout << "--------- MethodA ------- \n";
    one.Method1();
    two.Method2();
   }
   void MethodB() {
    cout << "--------- MethodB ------- \n";
    three.Method3();
    four.Method4();
   }
 };
};
