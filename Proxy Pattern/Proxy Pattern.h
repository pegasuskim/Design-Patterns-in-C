



/*
Proxy Pattern

 

객체로의 접근을 제어 하기 위해  중간에 대리인 역할을 하는 객체를 둔다. 

  각요소들의 역할
 
- Subject: Proxy와 RealSubject을 동일시 하기 위해서 위한 인터페이스를 제공한다. Real-Subject가 요청되는 곳에 Proxy을 사용 할 수 있게 한다.
- Proxy: Client로부터의 요구를 가능한 한 처리 하도록 하고, 만약 처리 할 수 없는 경우는 Real-Subject에게 일을 넘기게 된다.
- Real Subject: Proxy가 대신하는 실체 객체이다.

*/


// Proxy Pattern
#include <iostream.h>
namespace Proxy {
 
 // "Subject"
 class Subject {
  // Methods
  public:
   virtual void Request() = 0;
 };

 // "RealSubject"
 class RealSubject : public Subject {
  public:
   // Methods
   virtual void Request(){
    cout << "** Called RealSubject.Request() \n";
   }
 };

 // "Proxy"
 class Proxy : public Subject {
  // Fields
  private:
   RealSubject realSubject;
  public:
   // Methods
   virtual void Request(){
    realSubject.Request();
   }
 };
};
