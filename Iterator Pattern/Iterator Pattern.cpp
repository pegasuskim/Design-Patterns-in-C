


#include "Iterator Pattern.h"



int main()
{
	 Iterator::ConcreteAggregate<std::string> a;
	 std::string s1 = "s1";
	 a.add(s1);
	 std::string s2 = "s2";
	 a.add(s2);

	 Iterator::ConcreteIterator<std::string>* b = a.CreateIterator();
	 std::string t;
	 while(!b->IsDone()){
	  t = b->Next();
	  cout << t.c_str() << "\n";
	 }
	
	 
	 
	 return 0; 
}
