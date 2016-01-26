
/*

  Template Method

���� Ŭ�������� ó���� �帧(�������̽�)�� �̸� ����ϴ� ���ø� �޼ҵ带  
�����ϰ� ���� Ŭ�������� ��ü���� ������ �����ϴ� ������ �����̴�. 


  - AbstractClass: ���ø� �޼ҵ带 �����ϰ�, ���ø� �޼ҵ忡�� ���ǰ� �ִ� �߻� �޼ҵ带 �����ϴ� ������ �Ѵ�.
- ConcreteClass: AbstractClass ���ҿ��� ���ǵǾ� �ִ� �߻� �޼ҵ带 ��ü������ �����Ѵ�.

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

 

