
/*
Factory Method 
인스 턴스의 생성 방법 을 상의 클래스 (Creator) 에서 결정 하지만 
구체적인 이름 까지는 결정 하지 않는다. 구체적인 것은 모두 하위 클래스 에서 구현 되도록 한다
그러 므로 인스턴스 생성프레임 워크 와 실제로 인스 턴스 생성 하는 클래스의 분리를 가져 온다 
*/

#include <iostream.h>

class Product
{
public:
	Product(){};
	virtual void printMessage()
	{
		cout<<"Product Message \r\n";
	}
};


class Creator
{
public: 
	Creator(){};
	virtual Product * FactoryMethod() = 0 ;
};



class  OneProdect : public Product
{
public:
	OneProdect(){};
	virtual void printMessage()
	{
		cout<<"OneProduct Message \r\n";
	}
};


class TwoProdect : public Product
{
	TwoProdect(){};
	virtual void printMessage()
	{
		cout<<"TwoProdect Message\r\n";
	}
};



template <class NewProduct>
class StandardCreator : public Creator
{
public:
	virtual Product * FactoryMethod();
};



template <class NewProduct>
Product * StandardCreator<NewProduct> :: FactoryMethod()
{
	return new NewProduct();

}

/*
소스 에 대해 잠깐 언급 하면, 템플릿 인자로 OneProduct 대신 TwoProduct 를 사용하면  

FactoryMethod 을 사용 하여 TwoProduct 가 생성 될것입니다..

Factory Method 패턴은 언제 사용 할까

생성 할 객체 타입 (어떠한 Product 를 생성 할지 ) 을 예측할 수 없을때 생성 할 객체를 구현하는 책임을 서브클래스에 정의 하고자 하는 경우

객체 생성 의 책임 을 서브 클래스에 위임 시키고 서브 클래스 에 대한 정보를 은익 하고  할때 사용 한다. */
