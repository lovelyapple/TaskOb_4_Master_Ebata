//----------------------------------------------------------
//MainCPP
//----------------------------------------------------------

//------------------------------
//�C���N���[�h
#include <stdio.h>
#include <crtdbg.h>
#include "macro.h"
#include "test_class.h"

//------------------------------
//�O���[�o���ϐ�
c_Test	*g_pStartTest;
c_Test	*g_pRecycle;
//------------------------------
//�v���g�^�C�v
void	Init(void);
void	Uninit(void);
int		Recycle(void);


//MAIN
void main(void)
{
	Init();
	int a = 0;

	Addc_Test(*g_pStartTest);
	Addc_Test(*g_pStartTest);
	for(c_Test* ActiveTest = g_pStartTest->m_pNext;
		ActiveTest!= g_pStartTest;
		ActiveTest	= ActiveTest->m_pNext)
	{
		a++;
		printf("%d\n",a);
	}

//----------------------------------
//�s�v�ȃ����o�[���N���A����
	printf("���ꂩ��͂��ׂẴv���W�F�N�g�����T�C�N�����X�g�̒��ɓ����\n");
	rewind(stdin);
	getchar();
	int nCntRecycle = Recycle();
	printf("���T�C�N�����ꂽ�I�u�W�F�N�g�̐� %d\n",nCntRecycle);


	printf("���ꂩ��͂��ׂĂ̍폜����\n");
	rewind(stdin);
	getchar();
	Uninit();

	printf("���ꂩ��̓��������[�N�`�F�b�N���s��\n");
	rewind(stdin);
	getchar();
	//���������[�N�`�F�b�N�A����Ώo�̓E�B���h�ŏo�Ă���
	 _CrtDumpMemoryLeaks();

	printf("�v���O�����͂����܂ł�\n");
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
	g_pRecycle->m_pNext	= g_pRecycle;
	g_pRecycle->m_pPrev = g_pRecycle;
}
//--------------------------------------------------
//���T�C�N������
int Recycle(void)
{
	int nCntRes = 0;

	for(c_Test* pActive	= g_pRecycle->m_pNext;
		pActive != g_pRecycle;)
	{
		nCntRes++;
		c_Test* Backup = pActive->m_pNext;
		pActive->CleanArray();
		delete pActive;
		pActive = Backup;
	}
	return nCntRes;
}

//--------------------------------------------------
//�I������
void Uninit(void)
{
	//�c�������̂����ׂă��T�C�N�����X�g�̒��ɓ����
	for(c_Test* pActive	= g_pStartTest->m_pNext;
		pActive != g_pStartTest;)
	{
		c_Test* Backup = pActive->m_pNext;
		pActive->MoveOut(*g_pStartTest,*g_pRecycle);
		pActive = Backup;
	}


	//���T�C�N���������s
	int nCntRes = 0;
	nCntRes = Recycle();
	printf("���T�C�N�����ꂽ�I�u�W�F�N�g�̐� %d\n",nCntRes);


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

