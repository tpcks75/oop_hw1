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

// data vector�� ����
// �̸����� �˻�
std::vector<CMyNode*> CListFinder::findByName(const char* pszName)
{
    std::vector<CMyNode*> results;   //  ��� �����

    for (CMyNode* pTmp = m_list.getHead()->getNext();
        pTmp != nullptr; pTmp = pTmp->getNext())
    {
        CIngredientData* pUser = static_cast<CIngredientData*>(pTmp);
        if (_stricmp(pUser->getName(), pszName) == 0)
        {
            results.push_back(pTmp); //  ��ġ �� vector�� ����
        }
    }

    return results; //  ����� ���� �ʰ� ����� ��ȯ
}

// �ĺ��ڷ� �˻�
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


// ������� �˻�
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
// ����ó�� �˻�
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

//�κ� ���ڿ� Ž�� 
std::vector<CMyNode*> CListFinder::findByPartialName(const char* pszSubName) {
    std::vector<CMyNode*> results; //  ��� ����� ����

    for (CMyNode* p = m_list.getHead()->getNext(); p != nullptr; p = p->getNext()) {
        CIngredientData* user = static_cast<CIngredientData*>(p);

        //  MyString ��ȯ �� �κ� ���ڿ� �˻�
        CMyString tempName(user->getName()); // const char* �� CMyString
        if (tempName.Find(pszSubName) != -1) {
            results.push_back(user); // ��ġ�ϴ� ����� �߰�
        }
    }

    return results; // vector<CIngredientData*> ��ȯ
}

// ������� �ӹ� �� ���� ��ǰ Ȯ��
void CListFinder::findExprStatus(
    int days,
    std::vector<CMyNode*>& expiringSoon,
    std::vector<CMyNode*>& expired)
{
    // ���� ��¥ (��, ��, �ϸ�)
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

        // YYYYMMDD ���� �˻�
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

        // ��¥ ���� ��� (�� ����)
        double diffDays = difftime(expiryTime, todayMidnight) / (60 * 60 * 24);

        if (diffDays < 0) {
            // ������� ���� ��ǰ
            expired.push_back(p);
        }
        else if (diffDays <= days) {
            // ������� �ӹ� ��ǰ
            expiringSoon.push_back(p);
        }
    }
}