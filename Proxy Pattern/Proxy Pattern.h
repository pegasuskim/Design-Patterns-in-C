



/*
Proxy Pattern

 

��ü���� ������ ���� �ϱ� ����  �߰��� �븮�� ������ �ϴ� ��ü�� �д�. 

  ����ҵ��� ����
 
- Subject: Proxy�� RealSubject�� ���Ͻ� �ϱ� ���ؼ� ���� �������̽��� �����Ѵ�. Real-Subject�� ��û�Ǵ� ���� Proxy�� ��� �� �� �ְ� �Ѵ�.
- Proxy: Client�κ����� �䱸�� ������ �� ó�� �ϵ��� �ϰ�, ���� ó�� �� �� ���� ���� Real-Subject���� ���� �ѱ�� �ȴ�.
- Real Subject: Proxy�� ����ϴ� ��ü ��ü�̴�.

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
