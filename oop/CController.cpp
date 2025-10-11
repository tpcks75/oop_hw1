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



CController::CController(void)
{
    m_list.addNewNode(new CUserData("Alexander Smith", "2006303001", "2001", "ComputerEng", "01085928369"));
    m_list.addNewNode(new CUserData("Benjamin Brown", "2003303531", "2000", "SoftwareSys", "01073249912"));
    m_list.addNewNode(new CUserData("Charlotte Davis", "2007343001", "2002", "AIResearch", "01015576238"));
    m_list.addNewNode(new CUserData("Dominic Carter", "2003303561", "1999", "MechDesign", "01046825071"));
    m_list.addNewNode(new CUserData("Eleanor Wilson", "2001223001", "2003", "DataScience", "01091352746"));


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

// Case 2
void CController::removeUser() {
    char name[32];
    m_ui->inputName(name);
    if (m_list.removeNode(name))
        m_ui->printMessage("삭제 완료.");
    else
        m_ui->printMessage("삭제 실패. 데이터 없음.");
}

//Case 4 제거 예정
void CController::showAllUsers() {

	CListPrinter printer(m_list);    // Printer 생성 
	printer.printAll();   //  CMyList::printAll() → CListPrinter로 이관
    
	/*CMyIterator iter = m_list.makeIterator();
    CUserData* pNode = nullptr;

    // model에서 데이터를가져와 UI에 출력요청
    m_ui->displayUserList(iter);
    */
}

// Case 5
void CController::sortByID() {
    m_list.sortByID();
}


/// ////////////////////////////////////////
/// case 3 - Search

void CController::searchUser() {
    CListFinder finder(m_list);      // Finder 생성
    CListPrinter printer(m_list);    // Printer 생성

    int choice = 0;
    system("cls");
    printf("- Search -\n");
    printf("1. Search by name\n");
    printf("2. Search by student ID (10 digits)\n");
    printf("3. Search by admission year (4 digits)\n");
    printf("4. Search by birth year (4 digits)\n");
    printf("5. Search by department name\n");
    printf("6. List All\n\n");
    printf("> ");
    scanf_s("%d", &choice);

    char key[64] = { 0 };

    switch (choice) {
    case 1:
        m_ui->inputName(key);
        printer.printNodes(finder.findByName(key));   
        //  inline 호출(즉시 반환 → 즉시 전달)
        //   vector 바로 전달
        break;

        /*
       m_ui->inputName(key);
       auto results = finder.findByName(key); //  vector 반환
       CListPrinter printer(m_list);
       printer.printNodes(results);            //  다중 결과 출력
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
        printer.printAll();   //  CMyList::printAll() → CListPrinter로 이관
        break;

    default:
        printf("Invalid choice.\n");
        _getch();
        break;
    }
}