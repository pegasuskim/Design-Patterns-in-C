



#include "Composite Pattern.h"

int main()
{
	 Composite* root = new Composite("** Parent ");
	 root->Add(new Leaf("Leaf A"));
	 root->Add(new Leaf("Leaf B"));

	 Composite* fcomp = new Composite("## subParent");
	 fcomp->Add(new Leaf("Leaf C"));
	 root->Add(fcomp);
	 root->Display();
	 delete root;

	 return 0;
}

//Composite Pattern������ ���� ����ұ��?

/*
������ �ý��ۿ��� ������ȿ� �ڽ� �����츦 �����ϰ�, 
�ٽ� �ڽ�������� �Ǵٸ� �����츦 �����ϴ� Ʈ�������� �����µ�, Composite ���ϴ� �̷� ������� ȣ���� �ʿ��� ������ �ַ� ����մϴ�.

�������, ���� �ڽ� �����츦 ������, ���� ������ �������� ��üȭ���� �簻��(repaint) �Ϸ��� �Ѵٰ� �սô�.

�̶�, ���� ������ ������ �Ӹ� �ƴ϶� �ڽ� ������ ���� �簻��(repaint)ó���� ���־�� �ϴµ�, 
�ڽ������� ����, �� �ٸ� �ڽ������츦 ������ �ִ� ������� �ϸ�,  
Compoiste ������ �����Ͽ� ��������� paint ó���� ���ִ°��� �ٶ����մϴ�. 

�ֳ��ϸ�, �θ� �ڽİ��� ���踦 Composite �������� �����Ͽ��ٸ�,  ���� ��� �ڽ� �����츦 �߰������� ���Ѵٰ� �ϴ���, 
������ �簻��(repaint)ó�� ����� �������� �ʰ� ���� Ȯ���۾��� �����Ҽ� �ֱ� �����Դϴ�.

*/
