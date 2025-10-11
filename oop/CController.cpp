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
    m_list.addNewNode(new CUserData("Alexander Smith", "2026-68814", "2001", "ComputerEng", "010-8592-8369"));
    m_list.addNewNode(new CUserData("Benjamin Brown", "2027-54203", "2000", "SoftwareSys", "010-7324-9912"));
    m_list.addNewNode(new CUserData("Charlotte Davis", "2028-39425", "2002", "AIResearch", "010-1557-6238"));
    m_list.addNewNode(new CUserData("Dominic Carter", "2029-81247", "1999", "MechDesign", "010-4682-5071"));
    m_list.addNewNode(new CUserData("Eleanor Wilson", "2023-10563", "2003", "DataScience", "010-9135-2746"));


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
        case 5: sortByID(); break;
        }
    } while (input != 0);
}


// Model 조작 로직은 Controller가 담당
void CController::addUser() {
    char name[32], id[32], birth[32], dept[64], tel[32];
    
    m_ui->inputName(name);
    m_ui->inputStudentID(id);
    m_ui->inputBirth(birth);
    m_ui->inputDept(dept);
    m_ui->inputTel(tel);


    int nResult = m_list.addNewNode(new CUserData(name, id, birth, dept, tel));
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

    printf("\nSuccessfully added \n");
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
    char id[32];
    m_ui->inputName(id);
    CMyNode* p = m_list.findNode(id);
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

void CController::sortByID() {
    m_list.sortByID();
}