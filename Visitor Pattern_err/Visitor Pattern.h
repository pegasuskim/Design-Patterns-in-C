
/*
Visitor Pattern

 

데이터 구조와 데이터처리를 분리하는 패턴이다. 데이터 구조를 돌아다니는 주체인 
Visitor클래스를 통해서 데이터 처리를 하게 된다. 
만약 새로운 처리를 추가 하고 싶다면, 새로운 Visitor 클래스를 추가 시키면 된다. 

각요소들의 역할 

	Visitor: ConcreteElement의 각 클래스에 적용될 Visit(..)메소드를 선언한다.
	Concretevisitor: Visitor 역할의 인터페이스를 구현한다.
	Element: 인자로써, visitor객체를 받아들이면서 Visitor가 방문할 곳을 나타내는 역할을 한다. 
			 (Accept라는 메소드를 통해서, 방문자를 받아들인다.)
	ConcreteElement: Accept의 인터페이스를 구현한다.
	ObjectStructure: Concretevisitor가 Element를 취급할 수 있는 메소드를 가지고 있다. 

	[처리할 데이터 요소(ConcreteElement) 들을 가지고 있으며, Accept 메소드(인자로 ConcreteVisitor를 취함)를 사용해서, 데이터 처리를 한다]
*/

// "Visitor Pattern"

#include <iostream>
#include <iostream.h>
#include <list>


namespace Visitor {
 class ConcreteElementA;
 class ConcreteElementB;


 // "Visitor"
 class Visitor {
  public:
   // Methods
   virtual void VisitConcreteElementA(ConcreteElementA* concreteElementA ) =0;
   virtual void VisitConcreteElementB(ConcreteElementB* concreteElementB ) =0;
 };


 // "Element"
 class Element{
  public:
   // Methods
   virtual void Accept(Visitor* visitor) = 0;
 };
 
 // "ConcreteElement"
 class ConcreteElementA : public Element {
  public:
   // Methods
   void Accept(Visitor* visitor){
    visitor->VisitConcreteElementA(this);
   }
   void OperationA(){

   }
 };


 // "ConcreteElement"
 class ConcreteElementB : public Element {
  public:
   // Methods
   void Accept(Visitor* visitor){
    visitor->VisitConcreteElementB(this);
   }
   void OperationB(){

   }
 };

 

 // "ConcreteVisitor"
 class ConcreteVisitor1 : public Visitor {
  public:
   // Methods
   void VisitConcreteElementA(ConcreteElementA* concreteElementA ) {
    cout << typeid(concreteElementA) << " is visited by " << typeid(this) << "\n";
   }
   void VisitConcreteElementB(ConcreteElementB* concreteElementB ){
    cout << typeid(ConcreteElementB) << " is visited by " << typeid(this) << "\n";
   }
 };
 
 // "ConcreteVisitor"
 class ConcreteVisitor2 : public Visitor {
  public:
   // Methods
   void VisitConcreteElementA(ConcreteElementA* concreteElementA ) {
   cout << typeid(concreteElementA) << " is visited by " << typeid(this) << "\n";
   }
   void VisitConcreteElementB(ConcreteElementB* concreteElementB ){
    cout << typeid(ConcreteElementB) << " is visited by " << typeid(this) << "\n";
   }
 };

 

 // "ObjectStructrue"
 class ObjectStructure {
  private:
   // Fields
   std::list<Element*> elements;
  public:
   // Destructor
   ~ObjectStructure(){
    /*std::list<Element*>::iterator li;
    int len = elements.size();
    for(li = elements.begin(); li != elements.end() ; li++)
    {
     delete (*li);
    }*/
    elements.clear();
   }
   // Methods
   void Attach(Element* element){
    elements.push_back(element);
   }
   void Detach(Element* element){
    elements.remove(element);
   }
   void Accept(Visitor* visitor){
    std::list<Element*>::iterator li;
    int len = elements.size();
    cout <<  "---------------------------------------------------------------- \n";

    for(li = elements.begin(); li != elements.end() ; li++)
    {
     (*li)->Accept(visitor);
    }
   }

 };

};

 



