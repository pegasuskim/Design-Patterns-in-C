

/*

  Strategy Pattern 

��� ���α׷��� ������ �ذ��ϱ� ���ؼ� ���������. �׸��� ������ �ذ��ϱ� ���ؼ� Ư�� �˰����� ���Ǿ� ����, 
�� ������ �˰����� ��ü�� ���鼭, ������ ������ �ٸ� ������� �ذ��� ������ ������Strategy�̴�. 

����ҵ��� ���� 

- Strategy: Strategy������ �̿��ϱ� ���� �������̽��� �����ϴ� ����
- Context:  Strategy�� �̿��ϴ� ���ҷ�, ConcreteStrategy �� �ν��Ͻ��� ������ ������ �ʿ信 ���� �װ��� �̿��Ѵ�.
- ConcreteStrategy: Strategy�� ������ �����ϴ� ������ �Ѵ�.
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


 