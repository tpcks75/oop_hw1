#include "CController.h"
#include "UserInterface.h"
#include "MyList.h"
#include "UserData.h"
#include "MyIterator.h"
#include "CListFinder.h"
#include "CListPrinter.h"

#include <cstdio>
#include <cstring>
#include <conio.h>
#include <cstdlib>
#include <vector>

CController::CController(void)
{
    // ���� ������ ����
    m_list.addNewNode(new CUserData("Alexander Smith", "2006303001", "2001", "ComputerEng", "01085928369"));
    m_list.addNewNode(new CUserData("Benjamin Brown", "2003303531", "2000", "SoftwareSys", "01073249912"));
    m_list.addNewNode(new CUserData("Charlotte Davis", "2007343001", "2002", "AIResearch", "01015576238"));
    m_list.addNewNode(new CUserData("Dominic Carter", "2003303561", "1999", "MechDesign", "01046825071"));
    m_list.addNewNode(new CUserData("Eleanor Wilson", "2001223001", "2003", "DataScience", "01091352746"));
    m_list.addNewNode(new CUserData("Franklin Moore", "2006303022", "2001", "ComputerEng", "01012223333"));
    m_list.addNewNode(new CUserData("Grace Hall", "2003303599", "2000", "SoftwareSys", "01023334444"));
    m_list.addNewNode(new CUserData("Henry Clark", "2008303005", "1999", "MechDesign", "01034445555"));
    m_list.addNewNode(new CUserData("Isabella Young", "2007343012", "2002", "AIResearch", "01045556666"));
    m_list.addNewNode(new CUserData("Jack Turner", "2001223015", "2003", "DataScience", "01056667777"));
    m_list.addNewNode(new CUserData("Karen Adams", "2006303010", "2001", "ComputerEng", "01067778888"));
    m_list.addNewNode(new CUserData("Liam Scott", "2008303025", "1999", "MechDesign", "01078889999"));

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
        case 5: sortUsers(); break;
		case 6: showStatistics(); break;
        }
    } while (input != 0);
}


// Case 1
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
        puts("ERROR: �̹� �����ϴ� �������Դϴ�.");
        _getch();

    }

    else if (nResult == -1)
    {
        puts("ERROR: �߸��Է��߽��ϴ�.");
        _getch();

    }

    printf("\nSuccessfully added \n");
    printf("�ƹ� Ű�� ������ �޴��� ���ư��ϴ�...\n\n");
    _getch();
}

// Case 2
void CController::removeUser() {
    char name[32];
    m_ui->inputStudentID(name);
    if (m_list.removeNode(name))
        m_ui->printMessage("���� �Ϸ�.");
    else
        m_ui->printMessage("���� ����. ������ ����.");
}

//Case 4 ���� ����
void CController::showAllUsers() {

	CListPrinter printer(m_list);    // Printer ���� 
	printer.printAll();   //  CMyList::printAll() �� CListPrinter�� �̰�
    
	/*CMyIterator iter = m_list.makeIterator();
    CUserData* pNode = nullptr;

    // model���� �����͸������� UI�� ��¿�û
    m_ui->displayUserList(iter);
    */
}


/*
// Case 5
void CController::sortByID() {
    m_list.sortByID();
}
*/

void CController::sortUsers() {

    system("cls");
    printf("- Sort -\n1. Sort by name \n2. Sort by StudentID\n3. Sort by Birth\n4. Sort by Department\n> ");
    int sel;
    scanf_s("%d", &sel);
    switch (sel) {
    case 1: m_list.sortBy(SortType::NAME);
        break;
    case 2: m_list.sortBy(SortType::ID); 
        break;
    case 3: m_list.sortBy(SortType::BIRTH); 
        break;
    case 4: m_list.sortBy(SortType::DEPT); 
        break;
    default: puts("�߸��� �Է��Դϴ�.");  
        break;
    }
    //_getch();
}


/// ////////////////////////////////////////
/// case 3 - Search

void CController::searchUser() {
    CListFinder finder(m_list);      // Finder ����
    CListPrinter printer(m_list);    // Printer ����

    int choice = 0;
    system("cls");
    printf("- Search -\n");
    printf("1. Search by name\n");
    printf("2. Search by student ID\n");
    printf("3. Search by admission year\n");
    printf("4. Search by birth year\n");
    printf("5. Search by department name\n");
    printf("6. List All\n");
    printf("7. Search by partial name\n\n");
    printf("> ");

    scanf_s("%d", &choice);

    char key[64] = { 0 };

    switch (choice) {
    case 1:
        m_ui->inputName(key);
        printer.printNodes(finder.findByName(key));   
        //  inline ȣ��(��� ��ȯ �� ��� ����)
        //   vector �ٷ� ����
        break;

        /*
       m_ui->inputName(key);
       auto results = finder.findByName(key); //  vector ��ȯ
       CListPrinter printer(m_list);
       printer.printNodes(results);            //  ���� ��� ���
       break;
        */
    case 2:
        m_ui->inputStudentID(key);
        printer.printNodes(finder.findByStudentID(key));
        break;

    case 3:
        m_ui->inputAdmissionYear(key);
        printer.printNodes(finder.findByAdmissionYear(key));
        break;

    case 4:
        m_ui->inputBirth(key);
        printer.printNodes(finder.findByBirth(key));
        break;

    case 5:
        m_ui->inputDept(key);
        printer.printNodes(finder.findByDept(key));
        break;

    case 6:
        printer.printAll();   //  CMyList::printAll() �� CListPrinter�� �̰�
        break;

    case 7:
        printf("Enter partial name: ");
        scanf_s("%s", key, (unsigned)sizeof(key));  // �˻��� �Է� �ޱ�

        {
            auto results = finder.findByPartialName(key);

            if (results.empty()) {
                printf("\n�˻� ����� �����ϴ�.\n");
            }
            else {
                printf("\n[�κ� �̸� �˻� ���]\n");
                printf("----------------------------------------------\n");
                for (auto pNode : results) {
                    CUserData* user = static_cast<CUserData*>(pNode);
                    user->printNode();
                }
                printf("----------------------------------------------\n");
                printf("�� %d�� �߰ߵ�.\n", (int)results.size());
            }
            _getch();
        }
        break;

    default:
        printf("Invalid choice.\n");
        _getch();
        break;
    }
}

void CController::showStatistics() {
    system("cls");
    printf("==============================================\n");
    printf("                 [Statistics]\n");
    printf("==============================================\n\n");
    printf("1. Statistics by Admission Year\n");
    printf("2. Statistics by Birth Year\n");
    printf("3. Statistics by Department\n\n");
    printf("0. Return to Main Menu\n");
    printf("----------------------------------------------\n");
    printf("Select: ");

    int sel;
    scanf_s("%d", &sel);

    CListPrinter stprint(m_list);

    switch (sel) {
    case 1:
        stprint.printStatisticsByAdmissionYear(m_list);
        break;
    case 2:
        stprint.printStatisticsByBirthYear(m_list);
        break;
    case 3:
        stprint.printStatisticsByDepartment(m_list);
        break;
    default:
        printf("\nReturning to menu...\n");
        _getch();
        return;
    }
}