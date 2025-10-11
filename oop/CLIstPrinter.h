#pragma once
#include "MyList.h"
#include "UserData.h"
// 다중처리를 위한 STL
#include <vector>

class CListPrinter
{
private:
    CMyList& m_list;

public:
    CListPrinter(CMyList& list);
    ~CListPrinter() {}

    // 전체 출력
    void printAll();

    // 특정 검색 결과(벡터)에 대한 출력
    void printNodes(const std::vector<CMyNode*>& nodes);

    // 통계 출력
    void printStatisticsByAdmissionYear(CMyList& list);
    void printStatisticsByBirthYear(CMyList& list);
    void printStatisticsByDepartment(CMyList& list);

    // 검색 결과 파일 저장
    void saveToFile(const std::vector<CMyNode*>& nodes, const char* filename);

    // 전체 출력 파일 저장
    void saveToFileAll(const char* filename);
};