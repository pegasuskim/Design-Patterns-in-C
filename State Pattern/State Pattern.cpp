

#include "State Pattern.h"

int main()
{
	 State::Context c(State::ConcreteStateB::getInstance());
	 c.Show();
	 c.Request();
	 c.Show();

	 return 0;
}