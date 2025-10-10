#include "UserInterface.h"
#include "UserData.h"
#include "MyIterator.h"


#include <cstdio>
#include <cstring>
#include <conio.h>
#include <cstdlib>

CUserInterface::CUserInterface(CController& ctrl)
    : m_ctrl(ctrl) {
}

int CUserInterface::printMenu() {
    int sel;
    system("cls");
    printf("[1] Add\n[2] Remove\n[3] Search\n[4] PrintAll\n[5] Sort\n[0] Exit\nSelect: ");
    scanf_s("%d", &sel);
    return sel;
}

void CUserInterface::inputName(char* name) {
    printf("Input name: ");
    scanf_s("%s", name, 32);
}

void CUserInterface::inputPhone(char* phone) {
    printf("Input phone: ");
    scanf_s("%s", phone, 32);
}

void CUserInterface::printMessage(const char* msg) {
    printf("%s\n", msg);
    _getch();
}

void CUserInterface::displayUserList(CMyIterator& it) {
    CUserData* pNode = nullptr;
    while ((pNode = static_cast<CUserData*>(it.GetCurrent())) != nullptr) {
        pNode->printNode();
        it.MoveNext();
    }
    printf("\n아무 키나 누르면 메뉴로 돌아갑니다...\n\n");
    _getch();
}