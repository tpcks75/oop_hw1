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
// UI �����ڿ� Controller ���� �Ѱܼ� ����� ����

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


// Model ���� ������ Controller�� ���
void CController::addUser() {
    char name[32], phone[32];
    m_ui->inputName(name);
    m_ui->inputPhone(phone);
    int nResult = m_list.addNewNode(new CUserData(name, phone));
    if (nResult == 0)
    {
        puts("ERROR: �̹� �����ϴ� �������Դϴ�.");
        _getch();

    }

    else if (nResult == -1)
    {
        puts("ERROR: �߸��Է��߽��ϴ�.");
        _getch();

    }

    printf("\nSuccessfully added \"%s\" (%s)\n", name, phone);
    printf("�ƹ� Ű�� ������ �޴��� ���ư��ϴ�...\n\n");
    _getch();
}

void CController::removeUser() {
    char name[32];
    m_ui->inputName(name);
    if (m_list.removeNode(name))
        m_ui->printMessage("���� �Ϸ�.");
    else
        m_ui->printMessage("���� ����. ������ ����.");
}

void CController::searchUser() {
    char name[32];
    m_ui->inputName(name);
    CMyNode* p = m_list.findNode(name);
    if (p) p->printNode();
    else m_ui->printMessage("������ ����.");
    printf("\n�˻��� �Ϸ��Ͽ����ϴ�.\n");
    printf("�ƹ� Ű�� ������ �޴��� ���ư��ϴ�...\n\n");
    _getch();
}

void CController::showAllUsers() {

	CMyIterator iter = m_list.makeIterator();
    CUserData* pNode = nullptr;

    // model���� �����͸������� UI�� ��¿�û
    m_ui->displayUserList(iter);
}

void CController::sortByName() {
    m_list.sortByName();
}