//----------------------------------------------------------
//�N���XCPP
//----------------------------------------------------------
#include "test_class.h"
c_Test::c_Test()
{
	m_nData = 0;
	m_pPrev = NULL;
	m_pNext = NULL;
}
c_Test::c_Test(int input)
{
	m_nData = 0;
	m_pPrev = NULL;
	m_pNext = NULL;

	m_nData = input;
}
c_Test::~c_Test()
{
	//CleanArray();
}
void c_Test::MoveOut(c_Test& pStart,c_Test& pRecBox)
{
	//���������X�g������o��
	m_pPrev->m_pNext	= m_pNext;//�O�I�u�W�F�N�g��Next�@�������̎��Ɏw��
	m_pNext->m_pPrev	= m_pPrev;//��I�u�W�F�N�g��Prev�@�������̑O�Ɏw��

	//���������T�C�N���̒��ɓ����
	pRecBox.m_pNext->m_pPrev = this;
	m_pNext	= pRecBox.m_pNext;

	pRecBox.m_pNext = this;
	m_pPrev = &pRecBox;

}
void c_Test::CleanArray(void)
{
	if(m_pPrev)
		m_pPrev = NULL;
	if(m_pNext)
		m_pNext = NULL;
}
void Addc_Test(c_Test& pStart)
{
	c_Test *newc_Test = new c_Test;

	//����������
	newc_Test->m_pNext	= pStart.m_pNext;
	newc_Test->m_pPrev	= &pStart;

	//���X�g�O��̒���
	pStart.m_pNext->m_pPrev	= newc_Test;
	pStart.m_pNext			= newc_Test;
}




