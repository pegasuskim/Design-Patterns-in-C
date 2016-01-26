

#include "Chain of Responsibility Pattern.h"

int main()
{
	Chain::ConcreteHandler1 h1;
	Chain::ConcreteHandler2 h2;
	Chain::ConcreteHandler3 h3;
	h1.SetSuccessor(&h2);
	h2.SetSuccessor(&h3);
	int nums[] = {2, 5, 15, 33, 7, 100, 27};
 
	for(int i=0; i<sizeof(nums)/sizeof(int); i++)
	{
		h1.HandleRequest(nums[i]);
	}
	return 0;
}

 

/*
객체들 간의 행위적 결합도가 낮아 지므로 써,  명령을 요청하는 측과 명령을 
처리하는 측 사이의 관계가 느슨하게 가지고 나갈 수 있고, 결국 객체 상호간의 상호작용이 단순화 된다. 
각 객체는 자신의 역할(책임)에만 집중할 수 있게 된다
*/ 