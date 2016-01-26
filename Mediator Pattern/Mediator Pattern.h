

/*
Mediator Pattern


객체들 간의 상호 작용을 캡슐화 하여 각 객체가 관련성을 갖는 다른 객체에 대한  참조 관계를 직접 정의 하기 보다는 이를 독립된 객체(즉 Mediator)에 위임 시켜서 관리 하도록 한다.

각요소들의 역할

- Mediator: Colleague 객체들과  교류하는 데 필요한 인터페이스 제공한다.
- Concrete Mediator: Mediator 역할의 인터페이스를 구현하고 실제의 조정을 수행하는 역할을 한다.
- Colleague: Colleague 객체들은 Mediator와의 인터페이스를 알고, 다른 객체와의 교류시 Mediator을 통해  이루어 진다.
 */



// Mediator Pattern

#include <iostream.h>
#include <string>

using namespace std;


namespace Mediator {
 class Colleague;
 class Mediator;

 

 // "Mediator"
 class Mediaotr {
  public:
   // Methods
   virtual void SendMsg(string msg,Colleague* colleague)=0;
    
 };

 

 // "Colleague"
 class Colleague {
  protected:
   // Fields
   Mediaotr* mediator;
  public:
   // Constructos
   Colleague(){}
   Colleague(Mediaotr* mediator){
    this->mediator = mediator;
   }
   virtual void setMediator(Mediaotr* mediator) = 0;

 };

 

  // " ConcreateColleague1"
 class ConcreateColleague1 : Colleague {
  public:
   // Constructors
   ConcreateColleague1(){}
   ConcreateColleague1(Mediaotr* mediator) : Colleague(mediator){
   }
   // Methods
   void setMediator(Mediaotr* mediator){
    Colleague::mediator = mediator;
   }
   void Send(string message){
    mediator->SendMsg(message, this);
   }
   void Notify(string message){
    cout << " ConcreateColleague1 received message => " <<
     message.c_str();
   }

 };

 

 // "ConcreateColleague2"
 class ConcreateColleague2 : Colleague {
  public:
   // Constructors
   ConcreateColleague2(){}
   ConcreateColleague2(Mediaotr* mediator) : Colleague(mediator){
   }
   // Methods
   void setMediator(Mediaotr* mediator){
    Colleague::mediator = mediator;
   }
   void Send(string message){
    mediator->SendMsg(message, this);
   }
   void Notify(string message){
    cout << " ConcreateColleague2 received message => " <<
     message.c_str();
   }

 };

 

 // "ConcreteMediator"
 class ConcreteMediator : public Mediaotr {
  private:
   // Fields
   ConcreateColleague1* colleague1;
   ConcreateColleague2* colleague2;
  public:
   // Methods
   // Properties
   void SetConcreateColleague1(ConcreateColleague1* colleague1){
    this->colleague1 = colleague1;
   }
   ConcreateColleague1* GetConcreateColleague1(){
    return colleague1;
   }
   void SetConcreateColleague2(ConcreateColleague2* colleague2){
    this->colleague2 = colleague2;
   }
   ConcreateColleague2* GetConcreateColleague2(){
    return colleague2;
   }

   virtual void SendMsg(string msg,Colleague* colleague) {
    
    if(colleague1 == (ConcreateColleague1*) colleague){
     colleague1->Notify(msg);

    }
    else if(colleague2 == (ConcreateColleague2*) colleague){
     colleague2->Notify(msg);
    }else {
     cout << "Error \n";
    }
   }
 };

};






