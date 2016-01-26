

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
��ü�� ���� ������ ���յ��� ���� ���Ƿ� ��,  ����� ��û�ϴ� ���� ����� 
ó���ϴ� �� ������ ���谡 �����ϰ� ������ ���� �� �ְ�, �ᱹ ��ü ��ȣ���� ��ȣ�ۿ��� �ܼ�ȭ �ȴ�. 
�� ��ü�� �ڽ��� ����(å��)���� ������ �� �ְ� �ȴ�
*/ 