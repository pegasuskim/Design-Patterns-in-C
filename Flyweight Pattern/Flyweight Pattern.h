

/*
Flyweight Pattern
많은 미세한 객체(fine-grained objects)들을 효과적으로 사용하기 위해서 공유개념을 적용시킨 패턴이다.

각요소들의 역할

 - Flyweight: 기존방식대로 취급하면 프로그램이 무거워 지기 때문에 공유(Flyweight 화)해도 좋은 것 들을 나타내는 인터페이스
- Concrete Flyweight: Flyweight를 구현하고 내부적으로 본질적 상태에 대한 저장소를  정의한다.Concrete Flyweight는 공유될 수 있다.
- Flyweight Factory: Flyweight객체를 생성하고 관리하는 역할을 한다.
- Client: Flyweight Factory를 사용해서 Flyweight 역할을 만들어 내서 이용하는 역할을 한다.
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