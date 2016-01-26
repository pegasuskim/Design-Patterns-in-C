


#include "Memento.h"
int main()
{

		// Originator ��ü �����ʱ�ȭ
	 Memento::Originator o;
	 o.setName("Peter");
	 o.setPhone("356-3322");
	 o.setBudget("30000");
	 o.PrintData();

	 // Caretaker ��ü ����, Memento ��ü����
	 Memento::Caretaker c;
	 Memento::Memento* m = o.CreateMemento();
	 c.setMemento(m);
 
	 o.setName("Jeff");
	 o.setPhone("433-3322");
	 o.setBudget("50000");
	 o.PrintData();

	 // Memento�� ����Ǿ� �ִ� ������ Originator ��ü�� ����
	 o.SetMemento(*c.getMemento());
	 o.PrintData();
	 delete m;

	 
	 return 0;
}



 

 
