


#include "Abstract Factory EX.h"

int main()
{
	AbstractFactory * factoty1 = new ConcreteFactory2();

	Building build(factoty1);
	build.Run();


	return 0;
}

