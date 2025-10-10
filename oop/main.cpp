#include "CController.h"
#include "MyListEx.h"
#include "UserData.h"

int main() {
	CController ctrl;
	ctrl.run();
	return 0;
}
/*#include "UserInterface.h"
#include "MyListEx.h"
#include "UserData.h"

// CController로 더미헤더선언 이전 기존 더미헤더세팅은 list로 이관
int main()
{
	CMyListEx DB(new CUserData("Dummy", "Head"));
	CUserInterface UI(DB);
	UI.run();
}*/
