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
    printf("Input Name: ");
    scanf_s("%s", name, 32);
}

void CUserInterface::inputStudentID(char* id) {
    printf("Input Student ID (10 digits): ");
    scanf_s("%s", id, 32);
}

void CUserInterface::inputBirth(char* birth) {
    printf("Input Birth Year (4 digits): ");
    scanf_s("%s", birth, 32);
}

void CUserInterface::inputDept(char* dept) {
    printf("Input Department: ");
    getchar(); // 공백 처리
    fgets(dept, 64, stdin);
    dept[strcspn(dept, "\n")] = 0; // 개행 제거
}

void CUserInterface::inputTel(char* tel) {
    printf("Input Tel: ");
    scanf_s("%s", tel, 32);
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