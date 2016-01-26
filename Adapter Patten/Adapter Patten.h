


// Adapter Pattern C++ Version 
// 20070730 
/************************************************************************/
/* ���α׷��� �� �̹� ���� �Ǿ� �ִ� ������ �״�� ��� �Ҽ� ���� ��쿡 �ʿ��� ���·� �ٲ㼭
����ϰ� �Ǵ� �� , �̹� ���� �Ǿ� �ִ� �Ͱ� �ʿ��Ѱ� ������ ������ �޿�� �������� �ϴ� �����̴�.
�� , ���� �� 110v �� ���ϴ� ������ 12V �� ��ȭ �����ִ� ���� AC ����ε�, 
�� AC ����� �� ���� ������ �ϴ� �� �ٷ� Adapter �����̴�.

  - Target( ��� ) : �ʿ�� �ϴ� �޼ҵ带 ���� �ϴ� ��Ȱ�� Ŭ���̾�Ʈ�� ��� �ϴ� ������ �� ���� ���� ���� ���̽� ���� Ŭ���� 
  - Client         : TarGet ��Ȯ�� �޼ҵ带 ��� �ؼ� ���� �ϰ� �ϴ� ��Ȱ
  - Adaptee        : ���� ���̽� ������ �ʿ��� ������ ���� ���̽� 
  - Adapter        : Target ���� ���̽� �� Adapte�� �������̽� �� ���� �ִ� Ŭ���� �̴� */
 /************************************************************************/


#include <iostream.h>
#include <string>
// Target
class Tatget
{
public:
	virtual void REquest() = 0;
};



// Adaptee
class Adaptee
{
public:

	void SpecificRequest()
	{
		cout<<"Called Specific Request"<<"\n";
	}
};


//Adapter

class Adapter : public Tatget 
{
private:
	Adaptee adaptee;

public:

	virtual void Request()
	{
		adaptee.SpecificRequest();		
	}

};

//SECOND Exam
//Target

class FruitT
{

protected:
	std::string name;
	float price;

public:

	FruitT(std::string name); name(0), price(0)
	{
		this->name = name;
	}

	void setPrice(float price)
	{
		this->price = price;
	}

	float getPrice()
	{

		return price;
	}

};


// Adaptee
class FruitInfo 
{

public: 
	float getPriceInfo(string fruit)
	{
		float price =0;
		if(fruit == "apple")
		{
			price = 1000;
		}
		else if(fruit =="pear")
		{
			price = 2000;
			return price;
		}
	}	
};

class FruitA : public FruitR
{

private:
	FruitInfo finfo;

public:
	FruitA(std::string name) : FruitT(name)
	{
		price = finfo.getPriceInfo(name);
	}

	void Show()
	{
		cout<<"name: "<<name.c_str()<<"\n";
		cout<<"price:" << price <<"\n";
	}
};