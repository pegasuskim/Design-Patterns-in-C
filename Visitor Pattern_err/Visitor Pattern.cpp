

#include "Visitor Pattern.h"

int main()
{

	 Visitor::ObjectStructure o;
	 Visitor::ConcreteElementA a;
	 Visitor::ConcreteElementB b;
	 o.Attach(&a);
	 o.Attach(&b);

	 Visitor::ConcreteVisitor1 v1;
	 Visitor::ConcreteVisitor2 v2;

	 o.Accept(&v1);
	 o.Accept(&v2);

	 return 0;
}