



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

//Composite Pattern패턴은 언제 사용할까요?

/*
윈도우 시스템에선 윈도우안에 자식 윈도우를 포함하고, 
다시 자식윈도우는 또다른 윈도우를 포함하는 트리구조를 가지는데, Composite 패턴는 이런 재귀적인 호출이 필요한 구조에 주로 사용합니다.

예를들어, 여러 자식 윈도우를 가지는, 메인 프레임 윈도우의 전체화면을 재갱신(repaint) 하려고 한다고 합시다.

이때, 메인 프레임 윈도우 뿐만 아니라 자식 윈도우 역시 재갱신(repaint)처리를 해주어야 하는데, 
자식윈도우 역시, 또 다른 자식윈도우를 가지고 있는 구조라고 하면,  
Compoiste 패턴을 적용하여 재귀적으로 paint 처리를 해주는것이 바람직합니다. 

왜냐하면, 부모 자식간의 관계를 Composite 패턴으로 구현하였다면,  추후 몇몇 자식 윈도우를 추가적으로 더한다고 하더라도, 
기존의 재갱신(repaint)처리 모듈을 변경하지 않고도 쉽게 확장작업을 수행할수 있기 때문입니다.

*/
