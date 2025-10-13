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
    void addIngredient();
    void removeIngredient();
    void showAllIngredients();
    void sortByID();
    void searchIngredient();
    void sortIngredients();

    void showStatistics();

    /*
   1. Search by name
   2. Search by student ID
   3. Search by admission year
   4. Search by Category year
   5. Search by department name
   6. List All
    */

};