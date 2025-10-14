#pragma once
#include "MyList.h"
#include "IngredientData.h"
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

    // 특정 검색 결과(벡터)에 대한 출력(단일출력 후 저장)
    void printNodes(const std::vector<CMyNode*>& nodes);

    // 특정 검색 결과(벡터)에 대한 출력(단일출력)
    void printSimpleList(const std::vector<CMyNode*>& nodes);

    // 통계 출력
    void printStatisticsByName(CMyList& list);
    void printStatisticsByCategory(CMyList& list);
    void printStatisticsBySupplier(CMyList& list);

    // 검색 결과 파일 저장
    void saveToFile(const std::vector<CMyNode*>& nodes, const char* filename);

    // 전체 출력 파일 저장
    void saveToFileAll(const char* filename);
};