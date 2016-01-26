



/*
Facade pattern 설명 
서브 시스템 내에 복잡하게 얽혀 있는 것을 객체의 상호 연관관계를 정리해서 
높은 레벨(higher-level) 의 인터페이스를 제공하는 역할을 한다. 

- 각요소들의 역할

- Facade: 시스템을 구성하고 있는 많은 역할의 ‘간단한 창구’ 구실을 한다. 
높은 레벨에서의  간단한 인터페이스를 시스템 외부에 제공한다.
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
