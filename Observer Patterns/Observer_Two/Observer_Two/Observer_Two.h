#include <iostream>
#include <list>
#pragma once

//Observer들의 관리에 대한 책임을 맡고 있는 Class.
template<class T>
class Observed
{
public:
	Observed(){}
	virtual ~Observed(){}

	typedef std::list<T * >typeObservers;

	//  옵져버 등록1

	void RegisterObserver(T * pOb)
	{
		m_listObserver.push_back(pOb);
	}


	// 옵져버 (제거)
	void UnRegisterObserver(T * pOb)
	{
		m_listObserver.remove(pOb);
	}

protected:
	typeObservers m_listObserver;
};


class Observable
{
public:
	virtual void OnEvent(int a) = 0;
};



class Observable_A : public Observable
{
public:	
	void OnEvent(int a) 
	{
		std::cout << "Fire_A -> " << a << std::endl;
	}

};


class Observable_B : public Observable
{
public:
	void OnEvent(int a) 
	{
		std::cout << "Fire_B -> " << a << std::endl;
	}

};



class EventSrc : public Observed<Observable>
{
public:
	void Fire(int a)
	{
		typeObservers::iterator it;
		for(it = m_listObserver.begin(); it!=m_listObserver.end(); ++it) 
		{
			(*it)->OnEvent(a);
		}
	}
};
