

/*
Memento


� ���������� �ν��Ͻ��� ���¸� ����ؼ� ������ �ξ��ٰ� ���߿� �ν��Ͻ��� �� �������� �ǵ������� �� �� ����ϴ� �����̴�.\


  ����ҵ��� ����

- Originator (�ۼ���)
Memento�� ���� �ڽ��� ���� ���¸� �����ϴ� ������ �Ѵ�.
- Memento
ũ �� �ΰ��� �������̽��� �����Ǿ� �ִµ�, �ϳ��� ��ü(Originator)�� ���¸� ������� ���ͽ�Ű�� ���ؼ� �ʿ�� �ϴ� �������̽� �̰�, �ٸ� �ϳ��� �ܺ��� Caretaker���� �ڽ��� ���� �ּ����� �������̽� ���� �����Ѵ� (��, Originator�� �ƴ� �ٸ� ��ü�� ���� ������ ���� ���ؼ� �̴�.)
- Caretaker(������ ���) 
Memento �� �����ϴ� ������ �һ��̸�, ����, Memento�� ���� ���¸� ��ȭ��Ű�ų� ������ �ʴ´�. 

*/

 

// "Memento Pattern"

#include <iostream.h>
#include <string>


namespace Memento {
 // "Memento"
 class Memento {
  private:
   // Fields
   std::string name;
   std::string phone;
   std::string budget;
  public:
   // Constructors
   Memento(std::string name, std::string phone, std::string budget){
    this->name  = name;
    this->phone = phone;
    this->budget = budget;   
   }
   // Properties, Name
   void setName(std::string name){
    this->name = name;
   }
   std::string getName(){
    return name;
   }
   // Properties, Phone
   void setPhone(std::string phone){
    this->phone = phone;
   }
   std::string getPhone(){
    return phone;
   }
   // Properties, Budget
   void setBudget(){
    this->budget = budget;
   }
   std::string getBudget(){
    return budget;
   }

 };

 

 // "Caretaker"
 class Caretaker {
  private:
   // Fields
   Memento* memento;
  public:
   // Properties
   void setMemento(Memento* memento){
    this->memento = memento;
   }
   Memento* getMemento(){
    return memento;
   }
 };

 

 // "Originator"
 class Originator {
  private:
   // Fields
   std::string name;
   std::string phone;
   std::string budget;
   
  public:
   // Properties, Name
   void setName(std::string name){
    this->name = name;
   }
   std::string getName(){
    return name;
   }
   // Properties, Phone
   void setPhone(std::string phone){
    this->phone = phone;
   }
   std::string getPhone(){
    return phone;
   }
   // Properties, Budget
   void setBudget(std::string budget){
    this->budget = budget;
   }
   std::string getBudget(){
    return budget;
   }

   // Methods
   Memento* CreateMemento(){
    return (new Memento(name,phone,budget));
   }
   void SetMemento(Memento& m){
    this->name = m.getName();
    this->phone = m.getPhone();
    this->budget = m.getBudget();
   }
   void PrintData(){
    cout << "------------------- \n";
    cout << "Name:  " << this->name.c_str() << "\n";
    cout << "Phone: " << this->phone.c_str()<< "\n";
    cout << "Budget:" << this->budget.c_str()<<"\n";
    cout << "------------------- \n";

   }
 };
};