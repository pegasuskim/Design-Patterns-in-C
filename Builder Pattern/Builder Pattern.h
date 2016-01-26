


/*
��ü�� ���� �ϴ� ��� �� ǥ�� ���ϴ� ����� ���� �ϴ� Ŭ�������� ������ �и� ���� ���� �ٸ� ǥ���̶� ��(��ü) ��
���� �ϴ� ��ƾ�� ���� �� ���� ������ �����ϵ��� �ϴ� �����̴�.

Builder :  �ν��Ͻ��� �ۼ��ϱ� ���� ���� ���̽��� ���� ���ϴ� ��Ȱ�� �����ϸ� , �ν� �Ͻ��� �� �κ��� ����� ���� �޼ҵ�� ������ ����� ��� ���� �޼ұװ� �غ�ȴ� 

ConcreteBuilder : Builder �� �������̽��� �����ϰ� �ִ� Ŭ���� �̴� ������ �ν� �Ͻ��� �ۼ� �Ҵ� ȣ��Ǵ� �޼ҵ尡 �غ�ȴ�.

Director: Builder �� ���� ���̽��� ����ؼ� �ν��Ͻ��� ���� �Ѵ� ConcreteBuilder �� ���������ʰ� Builder �޼ҵ�θ� ���α׷��� �Ѵ� 
*/


#include <string>
#include <vector>
#include <iostream.h>

using namespace std;

//Builder

class Builder
{
public: 
	virtual void makeTitle(std::string title) =0;
	virtual void makeString(std::string str)  =0;
	virtual void makeItem(std::vector<std::string> vec) =0;
};


class Director
{
private:
	Builder * builder;
public:
	Director(Builder * builder)
	{
		this->builder = builder;
	}

	void Build()
	{
		builder ->makeTitle("Design Pattern Study");
		builder ->makeString("By GOF");

		std::vector<std::string> vec;
		vec.push_back("Erich Gamma");
		vec.push_back("Richserd Helm");
		vec.push_back("JohnVlissides");
		vec.push_back("Raloh Johnson");
		builder->makeItem(vec);
		vec.clear();
	}
};

//ConcreteBuilder1
class LineDeco : public Builder
{
public:
	LineDeco(){}
	virtual void makeTitle(std::string title)
	{
		cout<<"------------------------------"<<"\n";
		cout<< "|" <<title.c_str()<<"|"<<"\n";
	}

	virtual void makeString(std::string str)
	{
		cout<< "|" <<str.c_str()<<"|"<<"\n";
	}

	virtual void makeItem(std::vector<std::string> vec)
	{
		for(int i=0; i<vec.size();i++)
		{
			cout<<"|"<<vec[i].c_str()<<"|"<<"\n";
		}
		cout<<"------------------------------"<<"\n";
	}

};

//ConcreteBuilder2

class starDeco : public Builder
{
public:
	starDeco(){}

	virtual void makeTitle(std::string title)
	{
		cout<<"*******************************"<<"\n";
		cout<< "*" <<title.c_str()<<"*"<<"\n";

	}
	virtual void makeString(std::string str)
	{
		cout<< "*" <<str.c_str()<<"*"<<"\n";
	}

	virtual void makeItem(std::vector<std::string> vec)
	{
		for(int i=0; i<vec.size();i++)
		{
			cout<<"*"<<vec[i].c_str()<<"*"<<"\n";
		}
		cout<<"*************************************"<<"\n";
	}
};
