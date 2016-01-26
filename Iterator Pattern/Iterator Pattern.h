


/*
Iterator Pattern

무언가 많이 모여 있는 것(복합객체) 중에서 하나씩 끄집어 내서 열거하면서 전체를 검색해 나가는 처리를 말한다. 

각요소들의 역할

- Iterator: 요소에 순차적으로 접근 하는데 필요한 인터페이스
- Concrete Iterator: Iterator 인터페이스를 구현한 클래스로, 현재 검색하고 있는 복합객체 내의 현 위치를 기억한다.
- Aggregate: Iterator 객체를 생성해 내는 인터페이스 (Iterator를 사용해서 복합객체를 검색하는 주체)
- Concrete Aggregate: Aggregate의 인터페이스를 실제로 구현하는 부분이며, Concrete Iterator 객체를 만들어 낸다. 
*/



// Iteraotr Pattern
#include <iostream.h>
#include <list>
#include <string>
#include <vector>
using namespace std;
namespace Iterator{
 template <class kind>
 class ConcreteIterator;


 // "Iterator"
 template <class kind>
 class Iterator {
  public:
   // Constructors
   Iterator(void){}
   // Methods
   virtual kind Next() = 0;
   virtual bool IsDone() = 0;
   virtual kind CurrentItem() = 0;
   virtual kind End() = 0;

 };


 // "Aggregate"
 class Aggregate {
  //public:
  
 };

 

 // "ConcreteAggregate"
 template <class kind>
 class ConcreteAggregate : public Aggregate{
  private:
   // Fields
   std::vector<kind> items;
   ConcreteIterator<kind>* iter;
  public:
   // Methods
   int getCount(){
    return items.size();
   }
   ConcreteAggregate(){
    iter = NULL;
   }
   virtual ~ConcreteAggregate(){
    if(iter != NULL)
     delete iter;
   }
   // Indexers
   kind operator[](const int n){
    if(n >= getCount())
     return NULL;
    else
     return items[n];
   }
   void add(kind v){
    items.push_back(v);
   }
   
   ConcreteIterator<kind>* CreateIterator() {
    if(iter == NULL)
     iter = new ConcreteIterator<kind> (this);
    return iter;
   }
   
 };


 // "ConcreteIterator"
 template <class kind>
 class ConcreteIterator : public Iterator<kind> {
  private:
   // Fields
   ConcreteAggregate<kind>* aggegate;
   int current;
  public:
   // Constructors
   ConcreteIterator() {
    
   }
   ConcreteIterator(ConcreteAggregate<kind>* aggegate){
    this->aggegate = aggegate;
    current = 0;
   }
   // Methods
   
   virtual kind Next(){
    if(current < (*aggegate).getCount()){
     return (*aggegate)[current++];
    }else{
     return NULL;
    }
   }
   virtual kind CurrentItem() {
    return (*aggegate)[current];
   }
   virtual bool IsDone(){
    return current >= (*aggegate).getCount()? true: false;
   }
   virtual kind End(){
    return NULL;
   }

 };
 

};

 
