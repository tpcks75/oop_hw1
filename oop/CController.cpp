#include "CController.h"
#include "UserInterface.h"
#include "MyList.h"
#include "UserData.h"
#include "MyIterator.h"

#include <cstdio>
#include <cstring>
#include <conio.h>
#include <cstdlib>

CController::CController(void)
{
    m_list.addNewNode(new CUserData("aa", "01"));
    m_list.addNewNode(new CUserData("bb", "02"));
    m_list.addNewNode(new CUserData("cc", "03"));
    m_list.addNewNode(new CUserData("dd", "04"));

	m_ui = new CUserInterface(*this);
}
// UI 생성자에 Controller 참조 넘겨서 양방향 연결

void CController::run() {
    int input = 0;
    do {
        input = m_ui->printMenu();
        switch (input) {
        case 1: addUser(); break;
        case 2: removeUser(); break;
        case 3: searchUser(); break;
        case 4: showAllUsers(); break;
        case 5: sortByName(); break;
        }
    } while (input != 0);
}


// Model 조작 로직은 Controller가 담당
void CController::addUser() {
    char name[32], phone[32];
    m_ui->inputName(name);
    m_ui->inputPhone(phone);
    int nResult = m_list.addNewNode(new CUserData(name, phone));
    if (nResult == 0)
    {
        puts("ERROR: 이미 존재하는 데이터입니다.");
        _getch();

    }

    else if (nResult == -1)
    {
        puts("ERROR: 잘못입력했습니다.");
        _getch();

    }

    printf("\nSuccessfully added \"%s\" (%s)\n", name, phone);
    printf("아무 키나 누르면 메뉴로 돌아갑니다...\n\n");
    _getch();
}

void CController::removeUser() {
    char name[32];
    m_ui->inputName(name);
    if (m_list.removeNode(name))
        m_ui->printMessage("삭제 완료.");
    else
        m_ui->printMessage("삭제 실패. 데이터 없음.");
}

void CController::searchUser() {
    char name[32];
    m_ui->inputName(name);
    CMyNode* p = m_list.findNode(name);
    if (p) p->printNode();
    else m_ui->printMessage("데이터 없음.");
    printf("\n검색을 완료하였습니다.\n");
    printf("아무 키나 누르면 메뉴로 돌아갑니다...\n\n");
    _getch();
}

void CController::showAllUsers() {

	CMyIterator iter = m_list.makeIterator();
    CUserData* pNode = nullptr;

    // model에서 데이터를가져와 UI에 출력요청
    m_ui->displayUserList(iter);
}

void CController::sortByName() {
    m_list.sortByName();
}