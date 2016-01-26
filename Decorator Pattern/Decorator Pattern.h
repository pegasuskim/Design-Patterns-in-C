


/*
Decorateo pattern 설명 
중심이 되는 객체가 있고, 그곳에 장식(기능을) 덧붙여 나가면서 목적에 맞는 객체를 완성해 나가는 패턴을 말한다.  
즉 객체에 동적으로 새로운 기능이나 서비스를  추가할 수 있게 해준다.
(기능을 추가하기 위해서, 서브클래스를 생성하는 것 보다 융통성 있는 방법이다)
*/

 

 
/*
각요소들의 역할

- Component: 동적으로 추가될 서비스를 지니는 객체의 인터페이스를 나타내는 추상클래스
- Concrete Component: Component를 구현하며  추가적인 서비스가 실제적으로 구현되어 지는 클래스
- Decorator: Component의 레퍼런스를 관리하며 Component에 정의된 인터페이스를 구현해서 적절히 재정의
- Concrete Decorator: 구체적으로Decorator를 구현하는 역할
*/

// Decorator Pattern
#include <iostream.h>

namespace decorator {
 // "Component"
 class Component 
 {
 
 public:
   virtual void Operation() = 0;
 };

 // "ConcreteComponent"
 class ConcreteComponent : public Component 
 {

 public:
   virtual void Operation() 
   {
    cout << "ConcreteComponent.Operation \n";
   }
 };

 

 // "Decorator"
 class Decoratior : public Component 
 {
  protected:
	   Component* component;

  public:
	   // C++의 제약성때문, 원래 의도된 바는 Decoratior는 추상클래스
	   Decoratior()
	   {
		   component = NULL;
	   }

	   virtual ~Decoratior() 
	   {

	   }

	   void SetComponent(Component* component)
	   {
		   this->component = component;
	   }

	   virtual void Operation()
	   {
		   if(component != NULL)
			   component->Operation();
	   }
 };

 

 // "ConcreteDecorator1"
 class ConcreteDecorator1 : public Decoratior 
 {
 public:
   virtual void Operation()
   {
	   Decoratior::Operation();
	   cout << "+Decorated with ConcreteDecorator1.Operation \n";
   }

   void specialAct()
   {
   }
 };

 

 // "ConcreteDecorator1"
 class ConcreteDecorator2 : public Decoratior 
 {
 public:
   virtual void Operation()
   {
	   Decoratior::Operation();
	   cout << "+Decorated with ConcreteDecorator2.Operation \n";
   }
   
   void specialAct()
   {
   }

 };
}; //namespace


