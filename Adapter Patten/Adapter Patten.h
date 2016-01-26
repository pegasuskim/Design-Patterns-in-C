


// Adapter Pattern C++ Version 
// 20070730 
/************************************************************************/
/* 프로그래밍 시 이미 제공 되어 있는 조건을 그대로 상요 할수 없는 경우에 필요한 형태로 바꿔서
사용하게 되는 데 , 이미 제공 되어 있는 것과 필요한것 사이의 간격을 메우는 구실을하 하는 패턴이다.
즉 , 가정 용 110v 을 원하는 형태인 12V 로 변화 시켜주는 것이 AC 어뎁터인데, 
이 AC 어댑터 와 같은 구실을 하는 게 바로 Adapter 패턴이다.

  - Target( 대상 ) : 필요로 하는 메소드를 제공 하는 역활로 클라이언트가 사용 하는 도메인 에 종속 적인 인터 페이스 정의 클래스 
  - Client         : TarGet 역확의 메소드를 사용 해서 일을 하게 하는 역활
  - Adaptee        : 인터 페이스 변경이 필요한 기존의 인터 페이스 
  - Adapter        : Target 인터 페이스 에 Adapte의 인터페이스 를 맞추 주는 클래스 이다 */
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