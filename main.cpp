//----------------------------------------------------------
//MainCPP
//----------------------------------------------------------

//------------------------------
//�C���N���[�h
#include <stdio.h>
#include "class.h"
//------------------------------
//�O���[�o���ϐ�
Class	*g_pStartClass;
//------------------------------
//�v���g�^�C�v
void Init(void);


//MAIN
void main(void)
{
	Init();
	int a = 0;

	AssertClass(g_pStartClass);
	for(Class* ActiveClass = g_pStartClass;
		ActiveClass->pNext!= g_pStartClass;
		ActiveClass	= ActiveClass->pNext)
	{
		a++;
		printf("%d",a);
	}


}

void Init(void)
{
	g_pStartClass = new Class;
	g_pStartClass->pPrev	= g_pStartClass;
	g_pStartClass->pNext	= g_pStartClass;

					
}
