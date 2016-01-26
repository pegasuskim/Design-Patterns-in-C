


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
소스처럼, d1, d2을 모두 c에 적용할수도 있지만, 원하는 경우 둘중 하나만 적용 할 수도있는데, 
바로 이게 Decorator 패턴의 특징입니다.
*/
 
 return 0;

}

/*
Decorator패턴은 언제 사용 하나?

Decorator패턴은 단순히 상속을 사용하는 것 보다  설계의 융통성을 증대 시키므로, 
내용물을 변경하지 않고도 기능을 추가할 수 있다. 
(즉Component를 다른 Decorator로 감싸므로 서, 기능을 추가 변경 할 수 있다)
또한, 단순한 여러 Decorator를 사용해서 다양한 기능을 추가 해낼 수 있다
*/
