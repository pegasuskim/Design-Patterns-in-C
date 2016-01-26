


/*
Decorateo pattern ���� 
�߽��� �Ǵ� ��ü�� �ְ�, �װ��� ���(�����) ���ٿ� �����鼭 ������ �´� ��ü�� �ϼ��� ������ ������ ���Ѵ�.  
�� ��ü�� �������� ���ο� ����̳� ���񽺸�  �߰��� �� �ְ� ���ش�.
(����� �߰��ϱ� ���ؼ�, ����Ŭ������ �����ϴ� �� ���� ���뼺 �ִ� ����̴�)
*/

 

 
/*
����ҵ��� ����

- Component: �������� �߰��� ���񽺸� ���ϴ� ��ü�� �������̽��� ��Ÿ���� �߻�Ŭ����
- Concrete Component: Component�� �����ϸ�  �߰����� ���񽺰� ���������� �����Ǿ� ���� Ŭ����
- Decorator: Component�� ���۷����� �����ϸ� Component�� ���ǵ� �������̽��� �����ؼ� ������ ������
- Concrete Decorator: ��ü������Decorator�� �����ϴ� ����
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
	   // C++�� ���༺����, ���� �ǵ��� �ٴ� Decoratior�� �߻�Ŭ����
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


