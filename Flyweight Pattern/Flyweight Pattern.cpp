


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
Flyweight Pattern������ ���� ����ұ��?

Flyweight? ������? ��ü�� ��ǻ�� �ȿ� ���������� �����ϹǷ� ���԰� ���̴�, ������ ��� ǥ���� �������� �ʴ�.  
����, ���⼭ ���ϴ� ���Զ� ��ǻ�� �޸� ��뷮�� ��Ÿ���� �ǹ��̴�. ���� �츮�� �޸𸮸� ����ϱ� ���ؼ� 
new �� ���� ����Ѵٸ� �޸� ��뷮�� Ŀ���� �� ���̴�. �ν��Ͻ��� ��� �� ������ new �� ����ϴ� ���� �ƴ϶� 
�̹� ������� �ִ� �ν��Ͻ��� �ִٸ� �װ��� �����ؼ� ������� ��� ���� Flyweight ������ �ٽ��̴�. 
*/