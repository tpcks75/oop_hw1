#pragma once
#include "CController.h"
#include "MyIterator.h"

class CController; // 전방 선언

class CUserInterface {
private:
    CController& m_ctrl; // Controller 참조

public:
    CUserInterface(CController& ctrl);
    int printMenu();
    
    void inputName(char* name);
    void inputStudentID(char* id);
    void inputBirth(char* birth);
    void inputDept(char* dept);
    void inputTel(char* tel);
    void inputAdmissionYear(char* year);

    void printMessage(const char* msg);
    void displayUserList(CMyIterator& it);
};