#include "CListFinder.h"
#include "UserData.h"
#include "MyNode.h"
#include "MyList.h"
#include <cstring>
#include <vector>

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
        CUserData* pUser = static_cast<CUserData*>(pTmp);
        if (_stricmp(pUser->getName(), pszName) == 0)
        {
            results.push_back(pTmp); //  ��ġ �� vector�� ����
        }
    }

    return results; //  ����� ���� �ʰ� ����� ��ȯ
}

// �й����� �˻�
std::vector<CMyNode*> CListFinder::findByIdt(const char* pszID)
{
    std::vector<CMyNode*> results;

    for (CMyNode* pTmp = m_list.getHead()->getNext();
        pTmp != nullptr; pTmp = pTmp->getNext())
    {
        CUserData* pUser = static_cast<CUserData*>(pTmp);
        if (strcmp(pUser->getKey(), pszID) == 0)
        {
            results.push_back(pTmp);
        }
    }

    return results;
}

// ���г⵵(�й� �� 4�ڸ�)�� �˻�
std::vector<CMyNode*> CListFinder::findByAdmissionYear(const char* pszYear)
{
    std::vector<CMyNode*> results;

    for (CMyNode* pTmp = m_list.getHead()->getNext();
        pTmp != nullptr; pTmp = pTmp->getNext())
    {
        CUserData* pUser = static_cast<CUserData*>(pTmp);
        if (strncmp(pUser->getAdmissionYear(), pszYear, 4) == 0)
        {
            results.push_back(pTmp);
        }
    }

    return results;
}

// �������� �˻�
std::vector<CMyNode*> CListFinder::findByCategory(const char* pszCategory)
{
    std::vector<CMyNode*> results;

    for (CMyNode* pTmp = m_list.getHead()->getNext();
        pTmp != nullptr; pTmp = pTmp->getNext())
    {
        CUserData* pUser = static_cast<CUserData*>(pTmp);
        if (strcmp(pUser->getCategorytmp(), pszCategory) == 0)
        {
            results.push_back(pTmp);
        }
    }

    return results;
}
// �а��� �˻�
std::vector<CMyNode*> CListFinder::findByExpr(const char* pszExpr)
{
    std::vector<CMyNode*> results;

    for (CMyNode* pTmp = m_list.getHead()->getNext();
        pTmp != nullptr; pTmp = pTmp->getNext())
    {
        CUserData* pUser = static_cast<CUserData*>(pTmp);
        if (_stricmp(pUser->getDepartment(), pszExpr) == 0)
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
        CUserData* user = static_cast<CUserData*>(p);

        //  MyString ��ȯ �� �κ� ���ڿ� �˻�
        CMyString tempName(user->getName()); // const char* �� CMyString
        if (tempName.Find(pszSubName) != -1) {
            results.push_back(user); // ��ġ�ϴ� ����� �߰�
        }
    }

    return results; // vector<CUserData*> ��ȯ
}