



//Composite pattern 설명 
/*
  그릇과 내용물을 동일시해서 재귀적인 구조를 만드는 패턴이다.  
  컴퓨터 파일 시스템에는 디렉터리가 있습니다. 위 디렉터리 안에는 파일이 있고 
  또한 다른 (하위) 디렉터리를 포함하고   있을 수 있습니다. 
  그리고 그 포함된 디렉터리는 다시 다른 파일이나 하위 디렉터리를 포함할 수 있습니다. 
  결국 디렉터리는 재귀적인 구조를 하고 있습니다.  그런데, 만약 디렉터리 안에 무언가를 찾으려고 한다면 
  디렉터리와 파일을 합해서 즉 그릇과 내용물을 같은 종류로서 취급한 후 재귀적으로 호출한다면 편리할 것 이다.
 */

/*
각요소들의 역할
- Leaf: 내용물을 나타내는 역할을 하고 다른 내용물을 포함할 수는 없다.
- Composite: 그릇을 나타내는 역할을 하고 Leaf와 Composite을 담을 수 있다.
- Component: Leaf와 Composite의 역할을 동일시 하는 추상클래스로Leaf와Composite의 상위클래스이며, 공통의 인터페이스 정의와 행위를 구현한다.
- Client: Composite 패턴의 이용자이다.
*/

#include <iostream.h>
#include <string>
#include <list>

using namespace std;


// "Component"
class Component 
{
 // Fields
protected:
	 string name; 

 public:
  // Constructors
  Component(string name)
  {	  
	  this->name = name;
  }

  // Methods
  virtual void Add(Component* c) = 0;
  virtual void Remove(Component* c) = 0;
  virtual void Display() = 0;
};

 

// "Composite"
class Composite : public Component 
{
 // Fields
 private:
	list<Component*> children;

 public:
  // Constructors
	Composite(string name) : Component(name) { }

  // Destructor
  virtual ~Composite()
  {
	 list<Component*>::iterator li;

	for(li = children.begin(); li != children.end() ; li++)
	{
	  if(*li)
		  delete *li;
	}

    children.clear();
  }

  virtual void Add(Component* c)
  {
    children.push_back(c);
  }

  virtual void Remove(Component* c)
  {
    children.remove(c);
  }

  virtual void Display()
  {
    cout << "--" << name.c_str() << "\n";

    list<Component*>::iterator li;

    for (li = children.begin(); li != children.end() ; li++)
    {
      (*li)->Display();
    }
  }
};


// "Leaf"
class Leaf : public Component
{
 public:
  // Constructors
  Leaf(string name) : Component(name)
  {
  }
  // Methods
  virtual void Add(Component* c)
  {
    cout << "Cannot add to Leaf \n";
  }
  virtual void Remove(Component* c)
  {
    cout << "Cannot remove to Leaf \n";
  }
  virtual void Display()
  {
    cout << "--" << name.c_str() << "\n";
  }

};