

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
Builder Pattern 패턴은 언제 사용 하나?

  합성할 객체들의 표현이 다르더라도 서로 동일한 구축 공정을 지원하고 싶을때 사용한다 
*/