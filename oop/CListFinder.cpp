#include "CListFinder.h"
#include "IngredientData.h"
#include "MyNode.h"
#include "MyList.h"
#include <cstring>
#include <vector>
#include <ctime>

CListFinder::CListFinder(CMyList& list)
    : m_list(list)
{
}

// data vector로 저장
// 이름으로 검색
std::vector<CMyNode*> CListFinder::findByName(const char* pszName)
{
    std::vector<CMyNode*> results;   //  결과 저장용

    for (CMyNode* pTmp = m_list.getHead()->getNext();
        pTmp != nullptr; pTmp = pTmp->getNext())
    {
        CIngredientData* pUser = static_cast<CIngredientData*>(pTmp);
        if (_stricmp(pUser->getName(), pszName) == 0)
        {
            results.push_back(pTmp); //  일치 시 vector에 저장
        }
    }

    return results; //  출력은 하지 않고 결과만 반환
}

// 식별자로 검색
std::vector<CMyNode*> CListFinder::findByIdt(const char* pszID)
{
    std::vector<CMyNode*> results;

    for (CMyNode* pTmp = m_list.getHead()->getNext();
        pTmp != nullptr; pTmp = pTmp->getNext())
    {
        CIngredientData* pUser = static_cast<CIngredientData*>(pTmp);
        if (strcmp(pUser->getIdt(), pszID) == 0)
        {
            results.push_back(pTmp);
        }
    }

    return results;
}


// 목록으로 검색
std::vector<CMyNode*> CListFinder::findByCategory(const char* pszCategory)
{
    std::vector<CMyNode*> results;

    for (CMyNode* pTmp = m_list.getHead()->getNext();
        pTmp != nullptr; pTmp = pTmp->getNext())
    {
        CIngredientData* pUser = static_cast<CIngredientData*>(pTmp);
        if (_stricmp(pUser->getCategorytmp(), pszCategory) == 0)
        {
            results.push_back(pTmp);
        }
    }

    return results;
}
// 공급처로 검색
std::vector<CMyNode*> CListFinder::findBySupplier(const char* pszExpr)
{
    std::vector<CMyNode*> results;

    for (CMyNode* pTmp = m_list.getHead()->getNext();
        pTmp != nullptr; pTmp = pTmp->getNext())
    {
        CIngredientData* pUser = static_cast<CIngredientData*>(pTmp);
        if (_stricmp(pUser->getSupplier(), pszExpr) == 0)
        {
            results.push_back(pTmp);
        }
    }

    return results;
}

//부분 문자열 탐색 
std::vector<CMyNode*> CListFinder::findByPartialName(const char* pszSubName) {
    std::vector<CMyNode*> results; //  결과 저장용 벡터

    for (CMyNode* p = m_list.getHead()->getNext(); p != nullptr; p = p->getNext()) {
        CIngredientData* user = static_cast<CIngredientData*>(p);

        //  MyString 변환 후 부분 문자열 검색
        CMyString tempName(user->getName()); // const char* → CMyString
        if (tempName.Find(pszSubName) != -1) {
            results.push_back(user); // 일치하는 사용자 추가
        }
    }

    return results; // vector<CIngredientData*> 반환
}

// 유통기한 임박 및 만료 제품 확인
void CListFinder::findExprStatus(
    int days,
    std::vector<CMyNode*>& expiringSoon,
    std::vector<CMyNode*>& expired)
{
    // 오늘 날짜 (연, 월, 일만)
    time_t now = time(nullptr);
    struct tm today {};
    localtime_s(&today, &now);
    today.tm_hour = 0;
    today.tm_min = 0;
    today.tm_sec = 0;
    time_t todayMidnight = mktime(&today);

    for (CMyNode* p = m_list.getHead()->getNext();
        p != nullptr; p = p->getNext())
    {
        CIngredientData* data = static_cast<CIngredientData*>(p);
        const char* expr = data->getExpr();

        // YYYYMMDD 형식 검사
        if (strlen(expr) != 8)
            continue;

        int y, m, d;
        if (sscanf_s(expr, "%4d%2d%2d", &y, &m, &d) != 3)
            continue;

        struct tm expiry {};
        expiry.tm_year = y - 1900;
        expiry.tm_mon = m - 1;
        expiry.tm_mday = d;
        expiry.tm_hour = 0;
        expiry.tm_min = 0;
        expiry.tm_sec = 0;

        time_t expiryTime = mktime(&expiry);

        // 날짜 차이 계산 (일 단위)
        double diffDays = difftime(expiryTime, todayMidnight) / (60 * 60 * 24);

        if (diffDays < 0) {
            // 유통기한 지난 제품
            expired.push_back(p);
        }
        else if (diffDays <= days) {
            // 유통기한 임박 제품
            expiringSoon.push_back(p);
        }
    }
}