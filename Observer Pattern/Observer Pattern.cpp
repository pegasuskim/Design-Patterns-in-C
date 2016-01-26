



#include <stdio.h>
#include "Observer Pattern.h"
int  main()
{

	Observer::ConcreteSubject s;  // subject �� ���� �Ѵ�.

	//subject ���� ��� ���� �ش� 
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
Observer ������ ����ϸ� ���ü (Subject )�� Observer( ������)��θ� ���������� �����ϱ� ����
�����ڸ� �纯�� ���� �ʰ� ����� ���� �Ҽ� �ְ�, ��� ����ġ �ʰ� �����ڸ� ���� �Ҽ� �ִ�.
���� ���� �����ڸ� �߰� ����.
Windows MFC �� Ÿť��Ʈ/ ���Ű���� �� MVC ���Ͽ� �����
*/