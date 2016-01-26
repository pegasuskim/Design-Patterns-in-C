


/* 상태변화를 통지 하는 패턴으로 , 일대 다 의 관련성을 갖는 객체 들의 경우 한 객체의 상태가 변하면 나머지 다른 객체들에게 상태 변화를 
   알려서 그와 관련된 사항이 업데이트 되어지도록 한다 .


Subject : 관찰 대상 의 역활을 한다. 즉 다수의 observer 객체들이 Subject 을 관찰한다 
          또 관찰자인 observer 들을 등록 , 삭제 하는 매소드 를 가지고있다

ConcreteSubject: 구체적인 관찰 대상체 를 나타내고 있는 역활을 하고 대상체의 상태가 변하면 관찰자인 observer 에게 
                  변경 되었음을 통지 한다

Observer : 관찰자 로서 Subject 로 부터 상태 변화를 통지 받는다 update() 메소드가 호출 된다 

ConcreteObserver: ConcreteSubject 에 대한 차몾를 지니고 있고 관찰 대상체(Subject)의 상태와 일관성을 유지 하기 위해서 
                  (Subject 로 부터 호출 되어 지는 ) update()메소드를 구현 한다
*/

// observer pattern

#include <iostream.h>
#include <string.h>
#include <list>

using namespace std;

namespace Observer{

	class Observer
	{
	public:
		virtual void Update() = 0;
	};

	class Subject
	{
		private: 
			list<Observer*> observers;
	public:
		virtual ~Subject()
		{
			observers.clear();
		}

		void Attach(Observer* observer)
		{
			observers.push_back(observer);
		}

		void Detach(Observer* observer)
		{
			observers.remove(observer);
		}

		void Notify()
		{
			list<Observer*>::iterator li;

			int len  = observers.size();

			for(li = observers.begin(); li != observers.end(); li++)
			{
				(*li)->Update();
			}

		}

	};

	//ConcreteSubject
	class ConcreteSubject :public Subject
	{
	private:
		string state;
	public:

		void Setstate(string state)
		{
			this->state = state;
		}

		string GetState()
		{
			return state;
		}
	};

	//ConcreteObject
	class  ConcreteObserver : public Observer
	{
	private:
		string name;
		string obstate;
		ConcreteSubject* subject;

	public:
		ConcreteObserver(ConcreteSubject*	 subject, string name)
		{
			this->name = name;
			this->subject = subject;
		}

		virtual void Update()
		{
			obstate = subject->GetState();
			cout<<"Observer : " <<name.c_str()<<" 's state is"<<obstate.c_str()<<"\n";
		}

	};

};






