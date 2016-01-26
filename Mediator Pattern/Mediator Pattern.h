

/*
Mediator Pattern


��ü�� ���� ��ȣ �ۿ��� ĸ��ȭ �Ͽ� �� ��ü�� ���ü��� ���� �ٸ� ��ü�� ����  ���� ���踦 ���� ���� �ϱ� ���ٴ� �̸� ������ ��ü(�� Mediator)�� ���� ���Ѽ� ���� �ϵ��� �Ѵ�.

����ҵ��� ����

- Mediator: Colleague ��ü���  �����ϴ� �� �ʿ��� �������̽� �����Ѵ�.
- Concrete Mediator: Mediator ������ �������̽��� �����ϰ� ������ ������ �����ϴ� ������ �Ѵ�.
- Colleague: Colleague ��ü���� Mediator���� �������̽��� �˰�, �ٸ� ��ü���� ������ Mediator�� ����  �̷�� ����.
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






