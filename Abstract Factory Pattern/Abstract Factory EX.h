/* 
Abstract Factory 에서 추상 적인 부품을 조립해서 추상 적인 제품을 만든다 는 의미로 부품의 구체적인 구현 에는 
주목하지 않고 인터페이스에만 주목 하여, 그 인터 페이스 를 사용 해서 부품을 조립해서 제품을 완성 하는 패턴이다.
즉, 하위 클래스 에서 구체적인 공장이 등장 하고 구체적인 부품을 조립해서 구체적인 제품을 만든다 

- Client: AbstractFactory  와 AbstractProduct 의 인터 페이스 를 사용 해서 일을 수행 한다 
- AbstractFactory: AbstractProduct 의 인스 턴스 를 만들어 내기 위한 인터페이스 를 결정 한다 
- ConcreteProduct: AbstractProduct 의 인터페이스 구현 한다 
- ConcreteFactory: Abstract Factory 의 인터 페이스를 구현 한다 
*/

//Abstract Factory Patten source
#include<iostream.h>

//AbstractProduct1 
class AbstractProduct1{
public:
	virtual void Run()
	{
		cout<<" Make AbstractProduct1 \r\n";
	}
};


//AbstractProduct2 
class AbstractProduct2{
public:
	virtual void Run()
	{
		cout<<" Make AbstractProduct2 \r\n";
	}
};





class ProductI1 : public AbstractProduct1{
public: 
	ProductI1();

	virtual void Run()
	{
		cout<<"Make ProductI1 \r\n ";
	}
};

//Concrete Factory2
class ProductI2 : public AbstractProduct2{
public: 
	ProductI2();

	virtual void Run()
	{
		cout<<"Make ProductI2 \r\n ";
	}
};





//Concrete Factory1
class ProductII1 : public AbstractProduct1
{
public: 
	ProductII1();

	virtual void Run()
	{
		cout<<"Make ProductII1 \r\n ";
	}
};

//Concrete Factory2
class ProductII2 : public AbstractProduct2
{
public: 
	ProductII2();

	virtual void Run()
	{
		cout<<"Make ProductII2 \r\n ";
	}
};


//Abstract Factory
class AbstractFactory
{
public:
	virtual AbstractProduct1 * CreateProduct1() =0 ;
	virtual AbstractProduct2 * CreateProduct2() =0 ;
};


//ConcreteFactory1
class ConcreteFactory1 : public AbstractFactory
{
public:
	virtual AbstractProduct1 * CreateProduct1()
	{
		return new ProductI1();
	}
	
	virtual AbstractProduct2 * CreateProduct2()
	{
		return new ProductI2();
	}
};

//ConcreteFactory2
class ConcreteFactory2 : public AbstractFactory
{
public:
	virtual AbstractProduct1 * CreateProduct1()
	{
		return new ProductII1();
	}
	
	virtual AbstractProduct2 * CreateProduct2()
	{
		return new ProductII2();
	}
};



//Client the Interaction environment of the products
class Building
{
private:
	AbstractProduct1 * Product1;
	AbstractProduct2 * Product2;


public:
	Building(AbstractFactory* factory)
	{
		Product1 = factory ->CreateProduct1();
		Product2 = factory ->CreateProduct2();

	}

	~Building()
	{
		delete Product1;
		delete Product2;
	}
	void Run()
	{
		Product1 ->Run();
		Product2 ->Run();

	}	
};




/* 생성 되어지는 구체 적인 ConcreteProduct 을 고립 시킬수 있다
  즉,Product가 어떻게 생성 되든지 간에 system 은 독립 적일 수 있다 
  구체적인 공장(ConcreteFactory)을 손쉽게 교환및 새로이 추가 할수 가 있다

  단 , AbstractFactory 에 새로운 부품(메소드 등)을 만들기는 어렵다 
*/

  









