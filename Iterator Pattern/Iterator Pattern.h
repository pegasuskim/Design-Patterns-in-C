


/*
Iterator Pattern

���� ���� �� �ִ� ��(���հ�ü) �߿��� �ϳ��� ������ ���� �����ϸ鼭 ��ü�� �˻��� ������ ó���� ���Ѵ�. 

����ҵ��� ����

- Iterator: ��ҿ� ���������� ���� �ϴµ� �ʿ��� �������̽�
- Concrete Iterator: Iterator �������̽��� ������ Ŭ������, ���� �˻��ϰ� �ִ� ���հ�ü ���� �� ��ġ�� ����Ѵ�.
- Aggregate: Iterator ��ü�� ������ ���� �������̽� (Iterator�� ����ؼ� ���հ�ü�� �˻��ϴ� ��ü)
- Concrete Aggregate: Aggregate�� �������̽��� ������ �����ϴ� �κ��̸�, Concrete Iterator ��ü�� ����� ����. 
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

 
