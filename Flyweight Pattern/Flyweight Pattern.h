

/*
Flyweight Pattern
���� �̼��� ��ü(fine-grained objects)���� ȿ�������� ����ϱ� ���ؼ� ���������� �����Ų �����̴�.

����ҵ��� ����

 - Flyweight: ������Ĵ�� ����ϸ� ���α׷��� ���ſ� ���� ������ ����(Flyweight ȭ)�ص� ���� �� ���� ��Ÿ���� �������̽�
- Concrete Flyweight: Flyweight�� �����ϰ� ���������� ������ ���¿� ���� ����Ҹ�  �����Ѵ�.Concrete Flyweight�� ������ �� �ִ�.
- Flyweight Factory: Flyweight��ü�� �����ϰ� �����ϴ� ������ �Ѵ�.
- Client: Flyweight Factory�� ����ؼ� Flyweight ������ ����� ���� �̿��ϴ� ������ �Ѵ�.
*/ 

// Flyweight Pattern
#include <string>
#include <iostream.h>
#include <map>

namespace Flyweight {
 
 // "Flyweight"
 class Flyweight {
  public:
   virtual void Operation(int count) =0;
 };
 
 // "ConcreteFlyweight "
 class ConcreteFlyweight : public Flyweight {
  public:
   virtual void Operation(int count){
    cout << "ConcreteFlyweight: " << count <<"\n";
   }
 };

 

 // "UnsharedConcreteFlyweight"
 class UnsharedConcreteFlyweight : public Flyweight {
  public:
   virtual void Operation(int count){
    cout << "UnsharedConcreteFlyweight: " << count <<"\n";
   }
 };
 
 // "FlyweightFactory"
 class FlyweightFactory {
  // Fields
  private:
	  std::map<std::string,Flyweight *> flyweights;
  public:
   // Constructors
   FlyweightFactory(){
    flyweights["A"]= new ConcreteFlyweight();
    flyweights["B"]= new ConcreteFlyweight();
    flyweights["C"]= new ConcreteFlyweight();
   }
   // Destructor
   virtual ~ FlyweightFactory(){
    std::map<std::string,Flyweight *>::iterator li;
    for(li = flyweights.begin(); li != flyweights.end(); li++){
     delete li->second;
    }
    //int i = flyweights.size();
    flyweights.clear();
   }
   // Methods
   Flyweight* GetFlyWeight(std::string key){
    std::map<std::string,Flyweight *>::iterator it;
    it = flyweights.find(key);
    if(it == flyweights.end())
     return NULL;
    return (*it).second;
   }

 };

};