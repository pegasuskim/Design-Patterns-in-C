


/* ���º�ȭ�� ���� �ϴ� �������� , �ϴ� �� �� ���ü��� ���� ��ü ���� ��� �� ��ü�� ���°� ���ϸ� ������ �ٸ� ��ü�鿡�� ���� ��ȭ�� 
   �˷��� �׿� ���õ� ������ ������Ʈ �Ǿ������� �Ѵ� .


Subject : ���� ��� �� ��Ȱ�� �Ѵ�. �� �ټ��� observer ��ü���� Subject �� �����Ѵ� 
          �� �������� observer ���� ��� , ���� �ϴ� �żҵ� �� �������ִ�

ConcreteSubject: ��ü���� ���� ���ü �� ��Ÿ���� �ִ� ��Ȱ�� �ϰ� ���ü�� ���°� ���ϸ� �������� observer ���� 
                  ���� �Ǿ����� ���� �Ѵ�

Observer : ������ �μ� Subject �� ���� ���� ��ȭ�� ���� �޴´� update() �޼ҵ尡 ȣ�� �ȴ� 

ConcreteObserver: ConcreteSubject �� ���� ������ ���ϰ� �ְ� ���� ���ü(Subject)�� ���¿� �ϰ����� ���� �ϱ� ���ؼ� 
                  (Subject �� ���� ȣ�� �Ǿ� ���� ) update()�޼ҵ带 ���� �Ѵ�
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






