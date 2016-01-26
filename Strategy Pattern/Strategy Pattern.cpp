

#include "Strategy Pattern.h"

int main()
{

	 Strategy::QuickSort q;
	 Strategy::BubbleSort b;
	 Strategy::Context c;
	 // Quick Sort�� ���ؼ�
	 c.changeAlgorism(&q);
	 c.Sort();
	 // Bubble Sort�� ���ؼ�
	 c.changeAlgorism(&b);
	 c.Sort();
}

 


/*

 Strategy������ �ٺ������� �˰���κа� �ٸ� �κ��� �ǽ������� �и��� ����, 
 �˰���� �������̽� �κи��� ������ ���´�. �׸���, �� �˰����� �ʿ� �� ���α׷����� ������ ���ؼ� ����ϰ� �ȴ�. 
 �ᱹ, �����߿� �˰����� ����(��ü)�� �� �ִ� �ɷ��� ������ �ȴ�

 */

 


 
