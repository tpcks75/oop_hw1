#pragma once
//#include "UserInterface.h"
#include "MyList.h"

class CUserInterface; // ���� ����

class CController {
private:
    CMyList m_list;
    CUserInterface* m_ui;

public:
    CController(void);
    void run();

    // UI ��û�� ó���ϴ� �߰� �Լ���
    void addUser();
    void removeUser();
    void showAllUsers();
    void sortByID();
    void searchUser();
};