


#include "Memento.h"
int main()
{

		// Originator 객체 생성초기화
	 Memento::Originator o;
	 o.setName("Peter");
	 o.setPhone("356-3322");
	 o.setBudget("30000");
	 o.PrintData();

	 // Caretaker 객체 생성, Memento 객체생성
	 Memento::Caretaker c;
	 Memento::Memento* m = o.CreateMemento();
	 c.setMemento(m);
 
	 o.setName("Jeff");
	 o.setPhone("433-3322");
	 o.setBudget("50000");
	 o.PrintData();

	 // Memento에 저장되어 있는 값으로 Originator 객체값 변경
	 o.SetMemento(*c.getMemento());
	 o.PrintData();
	 delete m;

	 
	 return 0;
}



 

 
