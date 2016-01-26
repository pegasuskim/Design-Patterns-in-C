

/*
Memento


어떤 시점에서의 인스턴스의 상태를 기록해서 저장해 두었다가 나중에 인스턴스를 그 시점으로 되돌리고져 할 때 사용하는 패턴이다.\


  각요소들의 역할

- Originator (작성자)
Memento를 만들어서 자신의 현재 상태를 보존하는 역할을 한다.
- Memento
크 게 두개의 인터페이스로 구성되어 있는데, 하나는 객체(Originator)의 상태를 원래대로 복귀시키기 위해서 필요로 하는 인터페이스 이고, 다른 하나는 외부의 Caretaker에게 자신의 대한 최소한의 인터페이스 만을 제공한다 (즉, Originator가 아닌 다른 객체에 의한 접근을 막기 위해서 이다.)
- Caretaker(돌보는 사람) 
Memento 을 보관하는 역할을 할뿐이며, 절대, Memento의 내부 상태를 변화시키거나 하지는 않는다. 

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