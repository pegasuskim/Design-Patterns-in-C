

#pragma once

#include <stdio.h>
#include <iostream>
#include <set>
using namespace std;

class ObserverInterface
{
public:
	virtual void Update() = 0;

};


class Observer : public ObserverInterface
{
private:
	char m_ObserverName;

public:
	Observer(char ObserverName) : m_ObserverName(ObserverName) {}

	virtual void Update()
	{
		// 통지 메세지 출력 
		cout<< m_ObserverName << " : Notification Message"<< endl;

	}
};




class Subject
{
public:
	virtual void AttachObservers(ObserverInterface * pObserver) = 0;
	virtual void DetachObservers(ObserverInterface * pObserver) = 0;
	virtual void NotifyObservers() = 0;
};




class ObserverManager : public Subject
{
private:
	set<ObserverInterface * > m_Observers;
	int m_nState;

public:
	ObserverManager(int nState) : m_nState(nState) {}

	void AttachObservers(ObserverInterface * pObserver)
	{
		// observer 등록 
		m_Observers.insert(pObserver);
	}

	void DetachObservers(ObserverInterface * pObserver)
	{
		// 옵져버 해제
		m_Observers.erase(pObserver);
	}

	void NotifyObservers()
	{
		// 옵져버 들에거 메세지 발송
		for(set<ObserverInterface*>::const_iterator i = m_Observers.begin(); i != m_Observers.end(); i++ )
		{
			(*i)->Update();
		}

	}

	void SetState(int nState)
	{
		if(m_nState != nState)
		{
			m_nState = nState;
			NotifyObservers();
		}

	}

	int GetState()
	{
		return m_nState;
	}

};

