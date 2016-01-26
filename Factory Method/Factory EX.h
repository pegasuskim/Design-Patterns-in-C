
/*
Factory Method 
�ν� �Ͻ��� ���� ��� �� ���� Ŭ���� (Creator) ���� ���� ������ 
��ü���� �̸� ������ ���� ���� �ʴ´�. ��ü���� ���� ��� ���� Ŭ���� ���� ���� �ǵ��� �Ѵ�
�׷� �Ƿ� �ν��Ͻ� ���������� ��ũ �� ������ �ν� �Ͻ� ���� �ϴ� Ŭ������ �и��� ���� �´� 
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
�ҽ� �� ���� ��� ��� �ϸ�, ���ø� ���ڷ� OneProduct ��� TwoProduct �� ����ϸ�  

FactoryMethod �� ��� �Ͽ� TwoProduct �� ���� �ɰ��Դϴ�..

Factory Method ������ ���� ��� �ұ�

���� �� ��ü Ÿ�� (��� Product �� ���� ���� ) �� ������ �� ������ ���� �� ��ü�� �����ϴ� å���� ����Ŭ������ ���� �ϰ��� �ϴ� ���

��ü ���� �� å�� �� ���� Ŭ������ ���� ��Ű�� ���� Ŭ���� �� ���� ������ ���� �ϰ�  �Ҷ� ��� �Ѵ�. */
