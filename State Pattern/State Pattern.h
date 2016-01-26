


/*
State Pattern 

����, ��ü���� ���α׷��ֿ����� ���α׷��� ����� Ŭ������ ����. 
�繰�� �������� Ŭ������  ǥ�������ν�, ��ü�� ���λ��°� ���� ��, ��ü�� ���� ���� �ٲ�������� �ϴ� �����̴�. 
(��ü�� ������ ��ü���� ���¸� ������ Ŭ������ ǥ��������, ������ ���� ������ ���� ������ ������ Ǯ�� ���� �ִ�.)

  ����ҵ��� ����

- State: Ŭ������ ���¸� ��Ÿ���鼭, �� ���¿� ���� ��ü�� �ٸ� �ൿ�� �ϵ��� �ϴ� �������̽��� �����Ѵ�.
- ConcreteState: State���� ������ �������̽��� ���������ν�, ������ ��ü���� ���¸� ǥ���Ѵ�.
- Context: ����ڰ� State������ �̿��� �� �ֵ��� �������̽��� �����Ѵ�.������ ��ü�� ���¸� ��Ÿ����ConcreteState ��ü�� �����Ѵ�.
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
