

#include <stdio.h>
#include "Builder Pattern.h"

int main()
{

	starDeco Id;
	Director dir(&Id);

	dir.Build();

	return 0;
}

/*
Builder Pattern ������ ���� ��� �ϳ�?

  �ռ��� ��ü���� ǥ���� �ٸ����� ���� ������ ���� ������ �����ϰ� ������ ����Ѵ� 
*/