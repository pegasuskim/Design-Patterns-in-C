

/*
흔히 객체를 동적 으로 생성 할때 new 와 클래스 이름을 지정해서 인스 턴스 를 생성 한다.
그러나 클래스 이름 과 new 을 사용해서 인스 턴스 를 만드는 것이 아니라 인스턴스 를 
복사해서 새로운 인스턴스 를 만들어 내는 패턴이다. */

/*  

Prototype : 인스 턴스를 복사 해서 만들기 위한 메소드를 지정 한다 
Concrete  : Prototype : Prototype 을 실제 적으 구현 해서 , 인스 턴스 를 만들어 내는 역활을 한다 
Client    : 인스턴스를 복사 하는 메소드를 이용 해서 새로운 인스턴스를 만들어 낸다 

*/


#include <iostream.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <map>


using namespace std;

// Prototype Patten 사용 첫번째 예제


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
	// 생성자
	ConcretePrototypeI(string id):Prototype(id){}
	// 복사 생성자 
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
	// 생성자
	ConcretePrototypeII(string id):Prototype(id){}
	// 복사 생성자 
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



//Prototype Patten 사용 두번째 예제
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


  


// Prototype Patten 언제 사용 하나?
/* 취급 하는 객체의 종류가 너무 많아서 하나씩 다른 클래스로 만들면 다수의 소스 파일을 작성 해야 하는 부담이 있는 경우.
   생성하려는 인스턴스가 복잡한 과정을 거쳐서 만들어져서 직접적으로 클래스로 부터 인스턴스를 만들어 내는 것이 어려운 경우 .
   인스 턴스르 생성 할때의 프레임 웨크를 특정 클래스에 의 존하지않고 하고 싶은 경우.(픅레[임 웨크 와 생성 할 인스턴스 분리 )
 */
