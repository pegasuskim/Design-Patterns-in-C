

#include "Factory EX.h"


int main()
{

	StandardCreator<OneProdect> C1;

	Creator * CC = & C1;

	Product * p1 = CC->FactoryMethod();

	p1->printMessage();

	delete p1;

	return 0;
}