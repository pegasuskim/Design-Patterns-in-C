

#include "Adapter Patten.h"

int main()
{
	//사용 에제 1
	Target* t = new Adapter();
	t->Request();
	delete t;

	// 사용예제 2

	FruitA fA("apple");

	fA.Show()();

	return 0;
}

/* 

  Adapter pattern 은 언제 사용 하나?


  메소드 가 필요 하면 그것을 프로그래밍 하면 되지??
  우리는 처음 부터 프로그램밍 한다고 할수 없다. 이미 존재 하는 클래스를 재사용 하는
  경우도 자주 있는데 , 특히 그 클래스가 충분한 테스트 와 검증을 갖추어 왔고 
  지금것 사용해 왔다면 어떻게 든지 그 클래스를 부품으로서 재사용 하고 싶은 법이다
  Adapter 는 기존의 클래스를 수정 해서 필료한 클래스를 만드 는 데 Adapter 를 사용 함으로써 
  피료한 매소드 를 빨리 만들수 있고 발생시 Adapter부분만 중점적으로 보면 된다는 장점이 있다.





*/