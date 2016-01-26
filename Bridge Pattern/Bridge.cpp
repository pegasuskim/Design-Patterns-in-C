

#include "Bridge.h"



int main(){

	 Abstraction * abs = new RefinedAbstraction();
	 abs->setImplementor(new ConcreteImplementor1());
	 abs->Operation();
	 
	 abs->setImplementor(new ConcreteImplementor2());
	 abs->Operation();

	 delete abs;

	 return 0;
}

/*
Bridge Pattern패턴은 언제 사용하나?
Bridge 패턴의 특징은 ‘기능 클래스 계층’과 ‘구현 클래스 계층’을 분리시켜서 
각각의 클래스 계층을 독립적으로 확장가능 하도록 하였다. 
예를 들어, 구현 클래스 계층이 OS에 의존적이어서, Windows, Macintosh, Unix로 분리되어야 한다면 
각 OS의 공통 인터페이스를 취하는 부분을 Implementor로 하고 
ConcreteImplementor로,  Windows용, Macintosh용, Unix용으로 구현 할 수 있을 것이다.
*/

 