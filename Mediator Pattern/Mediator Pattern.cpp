



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

��Ű���� ����( A�� B�� 2���� �ν��Ͻ��� �ְ� ���� ����Ѵٸ�, A->B, A<-B�� ���踦 �����Ű�, A,B,C��� 6��, A,B,C,D��� 12�� �� �ʿ��ϴ� �� ���� ������ �ν��Ͻ��� ������ �����ϸ� �׸�ŭ ���� ����ϴ� �κ��� ���������� ���������.)

 */

