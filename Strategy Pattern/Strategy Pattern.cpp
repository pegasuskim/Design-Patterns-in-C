

#include "Strategy Pattern.h"

int main()
{

	 Strategy::QuickSort q;
	 Strategy::BubbleSort b;
	 Strategy::Context c;
	 // Quick Sort에 의해서
	 c.changeAlgorism(&q);
	 c.Sort();
	 // Bubble Sort에 의해서
	 c.changeAlgorism(&b);
	 c.Sort();
}

 


/*

 Strategy패턴은 근본적으로 알고리즘부분과 다른 부분을 의식적으로 분리해 놓고, 
 알고리즘과 인터페이스 부분만을 규정해 놓는다. 그리고, 각 알고리즘이 필요 시 프로그램에서 위임을 통해서 사용하게 된다. 
 결국, 실행중에 알고리즘을 변경(교체)할 수 있는 능력을 가지게 된다

 */

 


 
