

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
Bridge Pattern������ ���� ����ϳ�?
Bridge ������ Ư¡�� ����� Ŭ���� �������� ������ Ŭ���� �������� �и����Ѽ� 
������ Ŭ���� ������ ���������� Ȯ�尡�� �ϵ��� �Ͽ���. 
���� ���, ���� Ŭ���� ������ OS�� �������̾, Windows, Macintosh, Unix�� �и��Ǿ�� �Ѵٸ� 
�� OS�� ���� �������̽��� ���ϴ� �κ��� Implementor�� �ϰ� 
ConcreteImplementor��,  Windows��, Macintosh��, Unix������ ���� �� �� ���� ���̴�.
*/

 