#include "UserInterface.h"
#include "MyList.h"
#include "UserData.h"
#include "MyIterator.h"

#include <cstdio>
#include <cstring>
#include <conio.h>
#include <cstdlib>

CUserInterface::CUserInterface(CMyList& rList)
	: m_list(rList)
{
}

CUserInterface::~CUserInterface(void)
{
}

void CUserInterface::add(void)
{
	char szName[32] = { 0 };
	char szPhone[32] = { 0 };

	printf("Input name : ");
	gets_s(szName, sizeof(szName));

	printf("Input Id Number : ");
	gets_s(szPhone, sizeof(szPhone));

	int nResult = m_list.addNewNode(new CUserData(szName, szPhone));

	if (nResult == 0)
	{
		puts("ERROR: 이미 존재하는 데이터입니다.");
		_getch();

	}

	else if (nResult == -1)
	{
		puts("ERROR: 욕설을 이름으로 쓸 수 없습니다.");
		_getch();

	}

	printf("\nSuccessfully added \"%s\" (%s)\n", szName, szPhone);
	printf("아무 키나 누르면 메뉴로 돌아갑니다...\n\n");
	_getch();
}

int CUserInterface::printUI(void)
{
	int nInput = 0;

	system("cls");
	printf("[1]Add\t[2]Search\t[3]Print all\t[4]Remove\t[5]Sort \t [0]Exit\n");
	printf("번호를 입력해주세요 : ");

	scanf_s("%d%*c", &nInput);

	return nInput;
}

void CUserInterface::search(void)
{
	char szName[32] = { 0 };
	CUserData* pNode = NULL;

	printf("Input name : ");
	fflush(stdin);
	gets_s(szName, sizeof(szName));

	pNode = static_cast<CUserData*>(m_list.findNode(szName));

	if (pNode != NULL)
		pNode->printNode();
	else
		puts("ERROR: 데이터를 찾을 수 없습니다.");

	printf("\n검색을 완료하였습니다.\n");
	printf("아무 키나 누르면 메뉴로 돌아갑니다...\n\n");
	_getch();

}



void CUserInterface::remove(void)
{
	char szName[32] = { 0 };

	printf("이름을 입력하세요 : ");
	gets_s(szName, sizeof(szName));

	if (m_list.removeNode(szName))
		puts("삭제가 완료되었습니다.");
	else
		puts("ERROR: 삭제할 데이터를 찾을 수 없습니다.");

	printf("\n아무 키나 누르면 메뉴로 돌아갑니다...\n\n");
	_getch();

}

int CUserInterface::run(void)
{
	int nMenu = 0;

	while ((nMenu = printUI()) != 0)
	{
		switch (nMenu)
		{
		case 1:    // Add
			add();
			break;

		case 2:    // Search
			search();
			break;

		case 3:    // Print all
			printAll();
			break;

		case 4:    // Remove
			remove();
			break;

		case 5:		// Sort by Name
			m_list.sortByName();
			break;

		}
	}

	return nMenu;
}

void CUserInterface::printAll(void)
{
	CMyIterator it = m_list.makeIterator();
	CUserData *pNode = NULL;

	while ((pNode = static_cast<CUserData*>(it.GetCurrent())) != NULL)
	{
		
		pNode->printNode();
		it.MoveNext();

	}
	printf("\n아무 키나 누르면 메뉴로 돌아갑니다...\n\n");
	_getch();
}