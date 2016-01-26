
/*

  Template Method

상위 클래스에서 처리의 흐름(인터페이스)와 이를 사용하는 템플릿 메소드를  
정의하고 하위 클래스에서 구체적인 내용을 결정하는 디자인 패턴이다. 


  - AbstractClass: 템플릿 메소드를 구현하고, 템플릿 메소드에서 사용되고 있는 추상 메소드를 선언하는 역할을 한다.
- ConcreteClass: AbstractClass 역할에서 정의되어 있는 추상 메소드를 구체적으로 구현한다.

*/

// "TemplateMethod Pattern"
#include <iostream.h>

namespace TemplateMethod {

 

//"AbstractClass"
 class AbstractClass {
  public:
   // Methods
   virtual void PrimitiveOperation1() = 0;
   virtual void PrimitiveOperation2() = 0;
   // Template Method
   void TemplateMethod(){
    cout << "--- Call PrimitiveOperation1() & PrimitiveOperation2() ---\n";
    PrimitiveOperation1();
    PrimitiveOperation2();
   }
 };

 

//"ConcreteClass"
 class ConcreteClass : public AbstractClass {
  public: 
   void PrimitiveOperation1() {
    cout << "--- PrimitiveOperation1() func --- \n";
   }
   void PrimitiveOperation2() {
    cout << "--- PrimitiveOperation2() func --- \n";
   }
 };
};

 

