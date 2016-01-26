


/*
Chain of Responsibility Pattern

명령을 보내는 객체와 명령을 처리하는 객체사이의 결합력을 없애서, 
요청된 명령의 처리에 대해서 한 객체에서 맡아서 하지  않고 여러 객체가 처리할 수 있는 기회를 가지게 하는 패턴이다. 
즉 명령을 처리하는 객체들 사이를 하나의 연결고리(chain)로 만들고 요청된 명령을 처리 할 수 있는 객체를 만날 때 까지 계속해서, 옆으로 명령을 전달하는 방식이다.

각요소들의 역할 

- Handler:  요청된 명령을 처리하는 인터페이스를 정의한다. 연결고리(chain)을 따라 다음 객체로 명령을 내보낸다.
- Concrete Handle:  요청된 명령을 구체적으로 처리하는 역할을 한다.
- Client: Concrete Handle 로 처리할 명령을 보낸다. 
*/
// Chain Of Responsibility Pattern

#include <iostream.h>

namespace Chain {
	// "Handler"
 class Handler {
  protected:
   // Fields
   Handler* successor;
  public:
   // Methods
   void SetSuccessor(Handler* successor) {
    this->successor = successor;
   }
   virtual void HandleRequest(int request) = 0;
 };


 // "Con11creteHandler1"
 class ConcreteHandler1 : public Handler {
  public:
   ConcreteHandler1(){
    Handler::successor = NULL;
   }
   virtual void HandleRequest(int request) {
    if(request >= 0 && request < 10){
     cout << " handled request " << request << "\n";
    }else if(successor != NULL){
     successor->HandleRequest(request);
    }
   }
 };


 // "Con11creteHandler2"
 class ConcreteHandler2 : public Handler {
  public:
   ConcreteHandler2(){
    Handler::successor = NULL;
   }
   virtual void HandleRequest(int request) {
    if(request >= 10 && request < 20){
     cout << " handled request " << request << "\n";
    }else if(successor != NULL){
     successor->HandleRequest(request);
    }
   }
 };
 
 // "Con11creteHandler3"
 class ConcreteHandler3 : public Handler {
  public:
   ConcreteHandler3(){
    Handler::successor = NULL;
   }
   virtual void HandleRequest(int request) {
    if(request >= 20 && request < 30){
     cout <<  " handled request " << request << "\n";
    }else if(successor != NULL){
     successor->HandleRequest(request);
    }
   }
 };

};