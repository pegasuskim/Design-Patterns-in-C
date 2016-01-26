

/*
���� ��ü�� ���� ���� ���� �Ҷ� new �� Ŭ���� �̸��� �����ؼ� �ν� �Ͻ� �� ���� �Ѵ�.
�׷��� Ŭ���� �̸� �� new �� ����ؼ� �ν� �Ͻ� �� ����� ���� �ƴ϶� �ν��Ͻ� �� 
�����ؼ� ���ο� �ν��Ͻ� �� ����� ���� �����̴�. */

/*  

Prototype : �ν� �Ͻ��� ���� �ؼ� ����� ���� �޼ҵ带 ���� �Ѵ� 
Concrete  : Prototype : Prototype �� ���� ���� ���� �ؼ� , �ν� �Ͻ� �� ����� ���� ��Ȱ�� �Ѵ� 
Client    : �ν��Ͻ��� ���� �ϴ� �޼ҵ带 �̿� �ؼ� ���ο� �ν��Ͻ��� ����� ���� 

*/


#include <iostream.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <map>


using namespace std;

// Prototype Patten ��� ù��° ����


// Protorype
class Prototype
{

protected:
	string  id;
public:
	Prototype(){}

	Prototype(string id)
	{
		this->id = id;
	}

	string getID()
	{
		return id;
	}

	virtual void setID(string id)
	{
		this->id = id;
	}

	virtual void printMessage()
	{
		cout<<"Protorype Message::"<<id.c_str()<<"\r\n";
	}

	virtual Prototype * Clone() const =0;
};


// ConcretePrototype1
class ConcretePrototypeI : public Prototype
{
public:
	// ������
	ConcretePrototypeI(string id):Prototype(id){}
	// ���� ������ 
	ConcretePrototypeI(const ConcretePrototypeI & other)
	{
		id = other.id;
	}

	virtual void setId(string id)
	{
		this->setID(id);
	}

	//clone

	virtual Prototype * Clone() const
	{
		return new ConcretePrototypeI(*this);
	}

	virtual void printMessage()
	{
		cout<<"ConcretePrototypeI Message : "<< id.c_str()<<"\r\n";
	}
};


// ConcretePrototype2
class ConcretePrototypeII : public Prototype
{
public:
	// ������
	ConcretePrototypeII(string id):Prototype(id){}
	// ���� ������ 
	ConcretePrototypeII(const ConcretePrototypeII & other)
	{
		id = other.id;
	}

	virtual void setId(string id)
	{
		this->setID(id);
	}
	//clone
	virtual Prototype * Clone() const
	{
		return new ConcretePrototypeII(*this);
	}

	virtual void printMessage()
	{
		cout<<"ConcretePrototypeII Message : "<< id.c_str()<<"\r\n";
	}
};



//Prototype Patten ��� �ι�° ����
class Manager
{
public: 
	Manager();
	~Manager()
	{
		map<string, Prototype* >::iterator li;

		for(li = showcase.begin(); li != showcase.end(); li++)
		{
			delete li ->second;
		}
		showcase.clear();
	}

	void registers( std::string name, Prototype* proto)
	{
		showcase[name] = proto;
	}

	Prototype * create(string name)
	{
		std::map<std::string, Prototype *> ::iterator it;
		it = showcase.find(name);

		if(it == showcase.end())
		{
			return NULL;
		}
	}

private: 
	std::map<std::string, Prototype *> showcase;
};


  


// Prototype Patten ���� ��� �ϳ�?
/* ��� �ϴ� ��ü�� ������ �ʹ� ���Ƽ� �ϳ��� �ٸ� Ŭ������ ����� �ټ��� �ҽ� ������ �ۼ� �ؾ� �ϴ� �δ��� �ִ� ���.
   �����Ϸ��� �ν��Ͻ��� ������ ������ ���ļ� ��������� ���������� Ŭ������ ���� �ν��Ͻ��� ����� ���� ���� ����� ��� .
   �ν� �Ͻ��� ���� �Ҷ��� ������ ��ũ�� Ư�� Ŭ������ �� �������ʰ� �ϰ� ���� ���.(�G��[�� ��ũ �� ���� �� �ν��Ͻ� �и� )
 */
