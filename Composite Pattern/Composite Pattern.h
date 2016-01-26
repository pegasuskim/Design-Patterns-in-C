



//Composite pattern ���� 
/*
  �׸��� ���빰�� ���Ͻ��ؼ� ������� ������ ����� �����̴�.  
  ��ǻ�� ���� �ý��ۿ��� ���͸��� �ֽ��ϴ�. �� ���͸� �ȿ��� ������ �ְ� 
  ���� �ٸ� (����) ���͸��� �����ϰ�   ���� �� �ֽ��ϴ�. 
  �׸��� �� ���Ե� ���͸��� �ٽ� �ٸ� �����̳� ���� ���͸��� ������ �� �ֽ��ϴ�. 
  �ᱹ ���͸��� ������� ������ �ϰ� �ֽ��ϴ�.  �׷���, ���� ���͸� �ȿ� ���𰡸� ã������ �Ѵٸ� 
  ���͸��� ������ ���ؼ� �� �׸��� ���빰�� ���� �����μ� ����� �� ��������� ȣ���Ѵٸ� ���� �� �̴�.
 */

/*
����ҵ��� ����
- Leaf: ���빰�� ��Ÿ���� ������ �ϰ� �ٸ� ���빰�� ������ ���� ����.
- Composite: �׸��� ��Ÿ���� ������ �ϰ� Leaf�� Composite�� ���� �� �ִ�.
- Component: Leaf�� Composite�� ������ ���Ͻ� �ϴ� �߻�Ŭ������Leaf��Composite�� ����Ŭ�����̸�, ������ �������̽� ���ǿ� ������ �����Ѵ�.
- Client: Composite ������ �̿����̴�.
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