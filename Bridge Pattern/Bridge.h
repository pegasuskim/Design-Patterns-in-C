
/*
Bridge Pattern

 
Ŭ���� ������ ������� Ŭ���� �������� �������� Ŭ���� �������� ������ Ŭ���� �������� 
�и��� �� �� ���� ���̸� �̾��ִ� �ٸ��� �����ϴ�. �̷� �ٸ� ������ �ϴ� ���� Bridge�����̴�. 
����ҵ��� ���� ������ �Ѵ�.


- Abstraction(�߻�ȭ) : ���Ŭ������ �ֻ����� �ִ� Ŭ���� �̴�. ��ü ������(Implementor) ������ �޼ҵ带 
                        ����ؼ� �⺻���� ��ɸ� ����ϴ� Ŭ�����̴�.
- RefinedAbstraction:  Abstraction ���ҿ��� ����� �߰��ϴ�  ������ �Ѵ�.
- Implementor: ���� Ŭ���� ������ �ֻ����� �ִ� Ŭ������, ����Ŭ������ ���� �������̽��� �����Ѵ�.
- ConcreteImplementor: Implementor ������ �������̽��� ��ü������ ����ȭ�� 
*/



// Bridge pattern
#include <iostream.h>


// "Implementor"
class Implementor {
 public:
  virtual void Operation() = 0;
};

 

// "Abstraction"
class Abstraction {
 // Fields
 protected:
  Implementor* implementor;
 // Methods
 public:
  Abstraction() {
   implementor = NULL;
  }
  virtual ~Abstraction(){
   if(implementor != NULL)
    delete implementor;
  }  
  virtual void Operation() {
   implementor->Operation();
  }

  // Properties
  void setImplementor(Implementor* implementor){
   if(implementor != NULL)
    delete this->implementor;
   this->implementor = implementor;
  }
  Implementor* getImplementor(){
   return implementor;
  }
};

 

// "RefinedAbstraction"
class RefinedAbstraction : public Abstraction {
 // Methods
 public:
  virtual void Operation() {
   implementor->Operation();
  }
};

 

// "ConcreteImplementor1"
class ConcreteImplementor1: public Implementor {
 // Methods
 public:
  virtual void Operation() {
   cout << " ConcreteImplementor1 Operation \n";   
  }
};

 

// "ConcreteImplementor2"
class ConcreteImplementor2: public Implementor {
 // Methods
 public:
  virtual void Operation() {
   cout << " ConcreteImplementor2 Operation \n";   
  }
};