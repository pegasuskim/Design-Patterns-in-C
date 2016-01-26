


#include "Facade Pattern.h"

int main()
{
	Facade::Facade fac;
	fac.MethodA();
	fac.MethodB();


	return 0;
}

/*

FacadePattern패턴은 언제 사용하나 ?

복잡한 서브시스템에 대해서 단순한 인터페이스를 제공하고 싶을 때,
클라이언트와 다른 서브 시스템간의 결합도를 줄이고 싶을 때 
(즉 서브 시스템의 사용된 모든 인터페이스가 공개될 경우 많은 메소드 호출이 일어나므로 단순한 형태로 
통합해서 나머지는 내부에서 처리함) 

 */