



#include "Mediator Pattern.h"


int main()
{

	Mediator::ConcreteMediator m;
	Mediator::ConcreateColleague1 c1;
	Mediator::ConcreateColleague2 c2;

	c1.setMediator(&m);
	c2.setMediator(&m);
	m.SetConcreateColleague1(&c1);
	m.SetConcreateColleague2(&c2);

	c1.Send("Let's study \n");
	c2.Send("About Mediator Pattern \n");

	return 0;
}


/*

통신경로의 증가( A와 B의 2개의 인스턴스가 있고 서로 통신한다면, A->B, A<-B의 관계를 맺을거고, A,B,C라면 6개, A,B,C,D라면 12개 가 필요하다 즉 같은 입장의 인스턴스의 개수가 증가하면 그만큼 서로 통신하는 부분이 복잡해지고 어려워진다.)

 */

