//----------------------------------------------------------
//�N���XCPP
//----------------------------------------------------------
#include "test_class.h"
c_Test::c_Test()
{
	//�������Ȃ�
}
c_Test::c_Test(int input)
{
	m_nData = input;
}
c_Test::~c_Test()
{
	CleanArray();
}
void Addc_Test(c_Test* pStart)
{
	c_Test *newc_Test = new c_Test;

	newc_Test->m_pNext	= pStart->m_pNext;
	newc_Test->m_pPrev	= pStart;

	pStart->m_pNext->m_pPrev	= newc_Test;
	pStart->m_pNext			= newc_Test;
}
void c_Test::MoveOut(c_Test* pStart,c_Test* pRecBox)
{
	//���I�_�~�[�̃I�u�W�F�N�g���g���A�����̃A�h���X��ۑ�
	c_Test pDummy;
	pDummy.m_pNext = m_pPrev->m_pNext;

	//���������X�g������o��
	m_pPrev->m_pNext	= m_pNext;//�O�I�u�W�F�N�g��Next�@�������̎��Ɏw��
	m_pNext->m_pPrev	= m_pPrev;//��I�u�W�F�N�g��Prev�@�������̑O�Ɏw��

	//�_�~�[���g���A���������T�C�N���̒��ɓ����
	m_pPrev = pRecBox->m_pPrev;
	pRecBox->m_pPrev->m_pNext = pDummy.m_pNext;

	pRecBox->m_pPrev = pDummy.m_pNext;
	m_pNext = pRecBox;

}
void c_Test::CleanArray(void)
{
	if(m_pPrev)
		delete m_pPrev;
	if(m_pNext)
		delete m_pNext;
}





