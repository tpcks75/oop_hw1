#pragma once
#include "CController.h"
#include "MyIterator.h"

class CController; // ���� ����

class CUserInterface {
private:
    CController& m_ctrl; // Controller ����

public:
    CUserInterface(CController& ctrl);
    int printMenu();
    void inputName(char* name);
    void inputPhone(char* phone);
    void printMessage(const char* msg);
    void displayUserList(CMyIterator& it);
};