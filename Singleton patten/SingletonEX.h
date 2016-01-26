




/* 시스템 에서 단 하나 밖에 존재 하지 않는 것을 프로그램 으로 표현 할때
   쓰이는 패턴으로 인스천스를 단지 하나 만 만든다 는 의미이다
   즉, 커퓨터 자체를 나타 내는 클래스 표현이나 현재의 시스템 설정, 도는 윈도우 시스템을 표현 하는 클래스 객체 
   를 만들어 내는 패턴이다

*/


#include <iostream.h>

class Singleton
{
protected:
	Singleton(){}

public:
	virtual ~ Singleton(){}

	static Singleton& getInstance()
	{
		static Singleton st;
		return st;
	}

	void printMsg()
	{
		cout<<"print Singleton \r\n";
	}
};

/*
Singleton 패턴 에는 인스턴스의 수에 대해서 제한을 두고 있다. 제한을 둔다는 것은 전제가 되는 조건이 증가 한다는 의미이다 
만약 인스턴스가 다수개 존재하면 인스턴스를 상화간의 영향을 주어 생각치도 못한 에러가 발생 하게 된다 
그러나 만약 인스턴스 가 하나 밖에 존재 하지 않는 다면 인스 턴스에 대한 접근을 보다 쉽게 제어 하룻 있는 장점을 가진다 
*/