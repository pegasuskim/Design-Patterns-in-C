// Observer_One.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Observer_One.h"


int _tmain(int argc, _TCHAR* argv[])
{
	ObserverManager Manager(1);
	Observer aa('a');
	Observer bb('b');
	Observer cc('c');
	Observer dd('d');
	Observer ee('e');
	Observer ff('f');
	Observer gg('g');

	Manager.AttachObservers(&aa);
	Manager.AttachObservers(&bb);
	Manager.AttachObservers(&cc);
	Manager.AttachObservers(&dd);
	Manager.AttachObservers(&ee);
	Manager.AttachObservers(&ff);
	Manager.AttachObservers(&gg);

	Manager.SetState(2);

	cout<<endl<<"bb Á¦°Å" << endl;

	Manager.DetachObservers(&bb);

	int c;

	scanf("%d", &cc);

	return 0;
}


