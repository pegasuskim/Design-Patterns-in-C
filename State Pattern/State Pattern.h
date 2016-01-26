


/*
State Pattern 

흔히, 객체지향 프로그래밍에서는 프로그래밍 대상을 클래스로 본다. 
사물의 상태조차 클래스로  표현함으로써, 객체의 내부상태가 변할 때, 객체의 행위 역시 바뀌어지도록 하는 패턴이다. 
(객체의 개개의 구체적인 상태를 각각의 클래스로 표현함으로, 복잡한 상태 문제를 작은 문제로 나눠서 풀어 갈수 있다.)

  각요소들의 역할

- State: 클래스의 상태를 나타내면서, 각 상태에 따라 객체가 다른 행동을 하도록 하는 인터페이스를 결정한다.
- ConcreteState: State에서 결정한 인터페이스를 구현함으로써, 개개의 구체적인 상태를 표현한다.
- Context: 사용자가 State패턴을 이용할 수 있도록 인터페이스를 제공한다.현재의 객체의 상태를 나타내는ConcreteState 객체를 관리한다.
 */


// "State Pattern"

#include <string>
#include <list>
#include <iostream.h>

namespace State {
 class Context;
 class ConcreteStateB;
 class ConcreteStateA;
 // "State"
 class State {
  public:
   // Methods
   // Behavior
   virtual void Handle(Context* c) = 0;
   virtual std::string toString() = 0;

 };
 
 // "Context"
 class Context {
  private:
   // Fields
   State* state;
  public:
   // Constructors
   Context(State* state){
    this->state = state;
   }
   // Properties
   State* getState(){
    return state;
   }
   void setState(State* state){
    this->state = state;
   }
   // Methods
   void Request(){
    state->Handle(this);
   }
   void Show(){
    std::string str = state->toString();
    cout << "State: " << state->toString().c_str() << "\n";
   } 

 };


 // "ConcreteState"
 class ConcreteStateB : public State {
  private:
   static ConcreteStateB* instB;
   // Constructor
   std::string name;
   ConcreteStateB(){}
  public:
   // Methods
   static ConcreteStateB* getInstance(){
    if(instB == NULL) {
     instB = new ConcreteStateB();
    }
    return instB;
   }
   void Handle(Context* c);
  
   std::string toString(){
    name = "ConcreteStateB";
    return name;
   }

 };

 

 // "ConcreteState"
 class ConcreteStateA : public State {
  private:
   std::string name;
   static ConcreteStateA* inst;
   // Constructor
   ConcreteStateA(){}
  public:
   // Methods
   
   static ConcreteStateA* getInstance(){
    if(inst == NULL) {
     inst = new ConcreteStateA();
    }
    return inst;
   }
   void Handle(Context* c);
   
   std::string toString(){
    name = "ConcreteStateA";
    return name;
   }
 };


};
