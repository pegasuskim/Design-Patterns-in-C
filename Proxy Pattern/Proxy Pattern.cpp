

#include "Proxy Pattern.h"


int main()
{
	 Proxy::Proxy p;
	 p.Request();

	 return 0;
}
 
/*
Proxy Pattern패턴은 언제 사용할까요?


Proxy을 사용해서 시간이 많이 걸리는 처리(인스턴스 생성)을  지연시킬 수 있다.
 Proxy역할과, Real Subject 역할을 분리함으로써 프로그램의 부품화 진전 가능 하다.
(HTTP Proxy, Proxy Server)
*/

 