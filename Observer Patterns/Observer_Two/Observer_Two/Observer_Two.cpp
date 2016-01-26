// Observer_Two.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Observer_Two.h"

int _tmain(int argc, _TCHAR* argv[])
{
	EventSrc *pES    = new EventSrc();

	Observable *pO_A = new Observable_A();
	Observable *pO_B = new Observable_B();

	pES->RegisterObserver(pO_A);
	pES->RegisterObserver(pO_B);

	pES->Fire(99);

	pES->UnRegisterObserver(pO_B);
	pES->UnRegisterObserver(pO_A);

	delete pO_B;
	delete pO_A;
	delete pES;

	int a;
	scanf("%d",&a);
	return 0;
}