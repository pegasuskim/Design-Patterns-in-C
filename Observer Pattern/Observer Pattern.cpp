



#include <stdio.h>
#include "Observer Pattern.h"
int  main()
{

	Observer::ConcreteSubject s;  // subject 를 생성 한다.

	//subject 들을 등록 시켜 준다 
	Observer::ConcreteObserver o1(&s,"A");
	Observer::ConcreteObserver o2(&s,"B"); 
	Observer::ConcreteObserver o3(&s,"C");

	s.Attach(&o1);
	s.Attach(&o2);
	s.Attach(&o3);
	s.Setstate("ABC");
	s.Notify();


	return 0;
}

/* 
Observer 패턴을 사용하면 대상체 (Subject )와 Observer( 관찰자)모두를 독립적으로 변형하기 쉽다
관찰자를 재변형 하지 않고도 대상을 재사용 할수 있고, 대상에 개의치 않고 관찰자를 재사용 할수 있다.
또한 여러 관찰자를 추가 쉽다.
Windows MFC 의 타큐멘트/ 뷰아키텍터 에 MVC 패턴에 적용됨
*/