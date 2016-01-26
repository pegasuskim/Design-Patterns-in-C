

/*

  Strategy Pattern 

모든 프로그램은 문제를 해결하기 위해서 만들어진다. 그리고 문제를 해결하기 위해선 특정 알고리즘이 사용되어 지고, 
위 구현된 알고리즘을 교체해 가면서, 동일한 문제를 다른 방법으로 해결해 나가는 패턴이Strategy이다. 

각요소들의 역할 

- Strategy: Strategy패턴을 이용하기 위한 인터페이스를 정의하는 역할
- Context:  Strategy를 이용하는 역할로, ConcreteStrategy 의 인스턴스를 가지고 있으며 필요에 따라서 그것을 이용한다.
- ConcreteStrategy: Strategy을 실제로 구현하는 역할을 한다.
*/

// "Strategy Pattern"
#include <iostream.h>
#include <string>
#include <list>

namespace Strategy {


 // "Strategy"
 class Strategy {
  public:
   virtual void Sort(std::list<std::string> li) = 0;
 };

 // "ConcreteStrategy"
 class QuickSort : public Strategy{
  public:
   void Sort(std::list<std::string> li){
    cout << "Sorted by QuickSort \n";
   }
 };

 

 // "ConcreteStrategy"
 class BubbleSort : public Strategy{
  public:
   void Sort(std::list<std::string> li){
    cout << "Sorted by BubbleSort \n";
   }

 };
 
 // "Context"
 class Context {
  private:
   std::list<std::string> li;
   Strategy* sortalgorism;
  public:
   void changeAlgorism(Strategy* sortalgorism){
    this->sortalgorism =sortalgorism;
   }
   void Sort(){
    sortalgorism->Sort(li);
   }
 };

};


 