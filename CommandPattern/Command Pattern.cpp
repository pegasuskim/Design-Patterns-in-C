



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
���� ��ɾ���� �̷��� �����ϰų�, �߰����� ������ ������ �ִ� ��ɾ� ��ü ����� �ʿ� �� ��쿡 �ַ� ����մϴ�.
*/