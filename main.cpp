//----------------------------------------------------------
//MainCPP
//----------------------------------------------------------

//------------------------------
//�C���N���[�h
#include <stdio.h>
#include "macro.h"
#include "test_class.h"

//------------------------------
//�O���[�o���ϐ�
c_Test	*g_pStartTest;
c_Test	*g_pRecycle;
//------------------------------
//�v���g�^�C�v
void Init(void);
void Unit(void);
int Recycle(void);


//MAIN
void main(void)
{
	Init();
	int a = 0;

	Addc_Test(g_pStartTest);
	Addc_Test(g_pStartTest);
	for(c_Test* ActiveTest = g_pStartTest;
		ActiveTest->m_pNext!= g_pStartTest;
		ActiveTest	= ActiveTest->m_pNext)
	{
		a++;
		printf("%d",a);
	}

//----------------------------------
//�s�v�ȃ����o�[���N���A����
	int nCntRecycle = Recycle();

	Unit();

	rewind(stdin);
	getchar();
}
//--------------------------------------------------
//����������
void Init(void)
{
	g_pStartTest = new c_Test;
	g_pStartTest->m_pPrev	= g_pStartTest;
	g_pStartTest->m_pNext	= g_pStartTest;	

	g_pRecycle	= new c_Test;
	g_pRecycle->m_pNext = g_pRecycle->m_pPrev	= g_pRecycle;
}
//--------------------------------------------------
//�I������
void Unit(void)
{
	//�c�������̂����ׂă��T�C�N�����X�g�̒��ɓ����
	for(c_Test* ActiveTest = g_pStartTest;
		ActiveTest->m_pNext!= g_pStartTest;
		ActiveTest	= ActiveTest->m_pNext)
	{
		ActiveTest->MoveOut(g_pStartTest,g_pRecycle);
	}

	//���T�C�N���������s
	int nCntRes = 0;
	nCntRes = Recycle();


	//���S�J��
	if(g_pStartTest)
	{
		g_pStartTest->CleanArray();
		delete g_pStartTest;
	}
	if(g_pRecycle)
	{
		g_pRecycle->CleanArray();
		delete g_pRecycle;
	}
}
int Recycle(void)
{
	int nCntRes = 0;
	while(g_pRecycle->m_pNext != g_pRecycle)
	{
		c_Test* pActive = new c_Test;
		pActive = g_pRecycle->m_pNext;
		g_pRecycle->m_pNext	= g_pRecycle->m_pNext->m_pNext;

		if(pActive)
		{
			nCntRes++;
			pActive->CleanArray();
			delete pActive;
		}
	}
	return nCntRes;
}

