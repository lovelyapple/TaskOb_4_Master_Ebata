//----------------------------------------------------------
//MainCPP
//----------------------------------------------------------

//------------------------------
//インクルード
#include <stdio.h>
#include "macro.h"
#include "test_class.h"

//------------------------------
//グローバル変数
c_Test	*g_pStartTest;
c_Test	*g_pRecycle;
//------------------------------
//プロトタイプ
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
//不要なメンバーをクリアする
	int nCntRecycle = Recycle();

	Unit();

	rewind(stdin);
	getchar();
}
//--------------------------------------------------
//初期化処理
void Init(void)
{
	g_pStartTest = new c_Test;
	g_pStartTest->m_pPrev	= g_pStartTest;
	g_pStartTest->m_pNext	= g_pStartTest;	

	g_pRecycle	= new c_Test;
	g_pRecycle->m_pNext = g_pRecycle->m_pPrev	= g_pRecycle;
}
//--------------------------------------------------
//終了処理
void Unit(void)
{
	//残ったものをすべてリサイクルリストの中に入れる
	for(c_Test* ActiveTest = g_pStartTest;
		ActiveTest->m_pNext!= g_pStartTest;
		ActiveTest	= ActiveTest->m_pNext)
	{
		ActiveTest->MoveOut(g_pStartTest,g_pRecycle);
	}

	//リサイクルを一回実行
	int nCntRes = 0;
	nCntRes = Recycle();


	//安全開放
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

