/* 
Abstract Factory ���� �߻� ���� ��ǰ�� �����ؼ� �߻� ���� ��ǰ�� ����� �� �ǹ̷� ��ǰ�� ��ü���� ���� ���� 
�ָ����� �ʰ� �������̽����� �ָ� �Ͽ�, �� ���� ���̽� �� ��� �ؼ� ��ǰ�� �����ؼ� ��ǰ�� �ϼ� �ϴ� �����̴�.
��, ���� Ŭ���� ���� ��ü���� ������ ���� �ϰ� ��ü���� ��ǰ�� �����ؼ� ��ü���� ��ǰ�� ����� 

- Client: AbstractFactory  �� AbstractProduct �� ���� ���̽� �� ��� �ؼ� ���� ���� �Ѵ� 
- AbstractFactory: AbstractProduct �� �ν� �Ͻ� �� ����� ���� ���� �������̽� �� ���� �Ѵ� 
- ConcreteProduct: AbstractProduct �� �������̽� ���� �Ѵ� 
- ConcreteFactory: Abstract Factory �� ���� ���̽��� ���� �Ѵ� 
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




/* ���� �Ǿ����� ��ü ���� ConcreteProduct �� �� ��ų�� �ִ�
  ��,Product�� ��� ���� �ǵ��� ���� system �� ���� ���� �� �ִ� 
  ��ü���� ����(ConcreteFactory)�� �ս��� ��ȯ�� ������ �߰� �Ҽ� �� �ִ�

  �� , AbstractFactory �� ���ο� ��ǰ(�޼ҵ� ��)�� ������ ��ƴ� 
*/

  









