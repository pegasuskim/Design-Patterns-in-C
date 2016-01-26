


/*
객체를 생성 하는 방법 과 표혀 ㄴ하는 방법을 정의 하는 클래스들을 별도로 분리 시켜 서로 다른 표현이라도 이(객체) 를
생성 하는 루틴은 동일 한 생성 과정을 제공하도록 하는 패턴이다.

Builder :  인스턴스를 작성하기 위한 인터 페이스를 결저 ㅇ하는 역활을 수행하며 , 인스 턴스의 각 부분을 만들기 위한 메소드와 마지막 결과를 얻기 위한 메소그가 준비된다 

ConcreteBuilder : Builder 의 인터페이스를 구현하고 있는 클래스 이다 실제로 인스 턴스를 작성 할대 호출되는 메소드가 준빈된다.

Director: Builder 의 인터 페이스를 사용해서 인스턴스를 생성 한다 ConcreteBuilder 에 의존하지않고 Builder 메소드로만 프로그래밍 한다 
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
