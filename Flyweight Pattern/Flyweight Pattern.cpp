


#include "Flyweight Pattern.h"

int main()
{

	int count = 10;

	Flyweight::FlyweightFactory fac;


	Flyweight::Flyweight* fa = fac.GetFlyWeight("A"); 

	if(fa != NULL)
		fa->Operation(--count);

	Flyweight::Flyweight* fb = fac.GetFlyWeight("B");

	if(fb != NULL)
		fb->Operation(--count);

	Flyweight::UnsharedConcreteFlyweight fu;
	fu.Operation(--count);

	return 0;

}

/*
Flyweight Pattern패턴은 언제 사용할까요?

Flyweight? 가볍다? 객체는 컴퓨터 안에 가상적으로 존재하므로 무게가 무겁다, 가볍다 라는 표현은 적합하지 않다.  
단지, 여기서 말하는 무게란 컴퓨터 메모리 사용량을 나타내는 의미이다. 만약 우리가 메모리를 사용하기 위해서 
new 을 많이 사용한다면 메모리 사용량은 커지게 될 것이다. 인스턴스를 사용 할 때마다 new 을 사용하는 것이 아니라 
이미 만들어져 있는 인스턴스가 있다면 그것을 공유해서 사용하자 라는 것이 Flyweight 패턴의 핵심이다. 
*/