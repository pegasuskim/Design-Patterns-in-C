


#include "Decorator Pattern.h"
using namespace decorator;
int main()
{

	
	ConcreteComponent* c   = new ConcreteComponent();
	ConcreteDecorator1* d1 = new ConcreteDecorator1();
	ConcreteDecorator2* d2 = new ConcreteDecorator2(); 

	d1->SetComponent(c);
	d1->Operation();

	d2->SetComponent(c);
	d2->Operation();

	delete d1;
	delete d2;
	delete c;
 
/*
�ҽ�ó��, d1, d2�� ��� c�� �����Ҽ��� ������, ���ϴ� ��� ���� �ϳ��� ���� �� �����ִµ�, 
�ٷ� �̰� Decorator ������ Ư¡�Դϴ�.
*/
 
 return 0;

}

/*
Decorator������ ���� ��� �ϳ�?

Decorator������ �ܼ��� ����� ����ϴ� �� ����  ������ ���뼺�� ���� ��Ű�Ƿ�, 
���빰�� �������� �ʰ� ����� �߰��� �� �ִ�. 
(��Component�� �ٸ� Decorator�� ���ιǷ� ��, ����� �߰� ���� �� �� �ִ�)
����, �ܼ��� ���� Decorator�� ����ؼ� �پ��� ����� �߰� �س� �� �ִ�
*/
