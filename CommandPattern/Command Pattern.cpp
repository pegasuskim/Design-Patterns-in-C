



#include "Command Pattern.h"

int main()
{

	Command::Receiver receiver;
	Command::Invoker i(&receiver);
	i.ExecuteCommand(1);
	i.ExecuteCommand(2);
	i.ExecuteCommand(3);
	cout << " ** Redo Action ** \n";
	i.Redo(1);


	return 0;
}

/*
내린 명령어들의 이력을 보존하거나, 추가적인 정보를 가지고 있는 명령어 객체 사용이 필요 한 경우에 주로 사용합니다.
*/