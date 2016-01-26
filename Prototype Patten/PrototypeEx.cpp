

#include "PrototypeEX.h"


int main()
{

	// ���� 1 ���

	ConcretePrototypeI  p1("typeI");
	ConcretePrototypeII p2("typeII");


	ConcretePrototypeI* c1 = (ConcretePrototypeI*)p1.Clone();

	c1 ->printMessage();

	ConcretePrototypeII* c2 = (ConcretePrototypeII*)p2.Clone();
	c2 ->printMessage();


// ���� 2 ���

	ConcretePrototypeI *  p1 = new ConcretePrototypeI("TYPEI");
	ConcretePrototypeII * p2 = new ConcretePrototypeI("TYPEII");

	Manager manager;

	manager.registers("TYPEI",p1);
	manager.registers("TYPEII",p2);

	//create
	Prototype * p = manager.create("TYPEII");
	p->printMessage();

	return 0;
}