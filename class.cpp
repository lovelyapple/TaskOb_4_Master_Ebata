//----------------------------------------------------------
//�N���XCPP
//----------------------------------------------------------
#include "class.h"
Class::Class()
{
	//�������Ȃ�
}
Class::Class(int input)
{
	m_nData = input;
}
Class::~Class()
{
	if(pPrev)
		delete pPrev;
	if(pNext)
		delete pNext;
	

}
void AssertClass(Class* pStart)
{
	Class *newClass = new Class;

	newClass->pNext = pStart->pNext;
	newClass->pPrev	= pStart;

	pStart->pNext	= newClass;
	pStart->pNext->pPrev = newClass;

}


