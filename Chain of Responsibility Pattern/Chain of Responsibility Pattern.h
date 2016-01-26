


/*
Chain of Responsibility Pattern

����� ������ ��ü�� ����� ó���ϴ� ��ü������ ���շ��� ���ּ�, 
��û�� ����� ó���� ���ؼ� �� ��ü���� �þƼ� ����  �ʰ� ���� ��ü�� ó���� �� �ִ� ��ȸ�� ������ �ϴ� �����̴�. 
�� ����� ó���ϴ� ��ü�� ���̸� �ϳ��� �����(chain)�� ����� ��û�� ����� ó�� �� �� �ִ� ��ü�� ���� �� ���� ����ؼ�, ������ ����� �����ϴ� ����̴�.

����ҵ��� ���� 

- Handler:  ��û�� ����� ó���ϴ� �������̽��� �����Ѵ�. �����(chain)�� ���� ���� ��ü�� ����� ��������.
- Concrete Handle:  ��û�� ����� ��ü������ ó���ϴ� ������ �Ѵ�.
- Client: Concrete Handle �� ó���� ����� ������. 
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