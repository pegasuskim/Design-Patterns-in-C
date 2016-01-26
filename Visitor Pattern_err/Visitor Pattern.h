
/*
Visitor Pattern

 

������ ������ ������ó���� �и��ϴ� �����̴�. ������ ������ ���ƴٴϴ� ��ü�� 
VisitorŬ������ ���ؼ� ������ ó���� �ϰ� �ȴ�. 
���� ���ο� ó���� �߰� �ϰ� �ʹٸ�, ���ο� Visitor Ŭ������ �߰� ��Ű�� �ȴ�. 

����ҵ��� ���� 

	Visitor: ConcreteElement�� �� Ŭ������ ����� Visit(..)�޼ҵ带 �����Ѵ�.
	Concretevisitor: Visitor ������ �������̽��� �����Ѵ�.
	Element: ���ڷν�, visitor��ü�� �޾Ƶ��̸鼭 Visitor�� �湮�� ���� ��Ÿ���� ������ �Ѵ�. 
			 (Accept��� �޼ҵ带 ���ؼ�, �湮�ڸ� �޾Ƶ��δ�.)
	ConcreteElement: Accept�� �������̽��� �����Ѵ�.
	ObjectStructure: Concretevisitor�� Element�� ����� �� �ִ� �޼ҵ带 ������ �ִ�. 

	[ó���� ������ ���(ConcreteElement) ���� ������ ������, Accept �޼ҵ�(���ڷ� ConcreteVisitor�� ����)�� ����ؼ�, ������ ó���� �Ѵ�]
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

 



