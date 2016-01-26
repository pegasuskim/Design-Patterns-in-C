
/*
Bridge Pattern

 
클래스 계층을 ‘기능의 클래스 계층’과 ‘구현의 클래스 계층’의 독립된 클래스 계층으로 
분리한 후 두 계층 사이를 이어주는 다리를 놓습니다. 이런 다리 구실을 하는 것이 Bridge패턴이다. 
각요소들의 역할 역할을 한다.


- Abstraction(추상화) : 기능클래스의 최상위에 있는 클래스 이다. 객체 구현자(Implementor) 역할의 메소드를 
                        사용해서 기본적인 기능만 기술하는 클래스이다.
- RefinedAbstraction:  Abstraction 역할에다 기능을 추가하는  역할을 한다.
- Implementor: 구현 클래스 계층의 최상위에 있는 클래스로, 구현클래스에 대한 인터페이스를 제공한다.
- ConcreteImplementor: Implementor 역할의 인터페이스를 구체적으로 구현화는 
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