//----------------------------------------------------------
//MainCPP
//----------------------------------------------------------

//------------------------------
//インクルード
#include <stdio.h>
#include <crtdbg.h>
#include "macro.h"
#include "test_class.h"

//------------------------------
//グローバル変数
c_Test	*g_pStartTest;
c_Test	*g_pRecycle;
//------------------------------
//プロトタイプ
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
//不要なメンバーをクリアする
	printf("これからはすべてのプロジェクトをリサイクルリストの中に入れる\n");
	rewind(stdin);
	getchar();
	int nCntRecycle = Recycle();
	printf("リサイクルされたオブジェクトの数 %d\n",nCntRecycle);


	printf("これからはすべての削除する\n");
	rewind(stdin);
	getchar();
	Uninit();

	printf("これからはメモリリークチェックを行う\n");
	rewind(stdin);
	getchar();
	//メモリリークチェック、あれば出力ウィンドで出てくる
	 _CrtDumpMemoryLeaks();

	printf("プログラムはここまでだ\n");
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
	g_pRecycle->m_pNext	= g_pRecycle;
	g_pRecycle->m_pPrev = g_pRecycle;
}
//--------------------------------------------------
//リサイクル処理
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
//終了処理
void Uninit(void)
{
	//残ったものをすべてリサイクルリストの中に入れる
	for(c_Test* pActive	= g_pStartTest->m_pNext;
		pActive != g_pStartTest;)
	{
		c_Test* Backup = pActive->m_pNext;
		pActive->MoveOut(*g_pStartTest,*g_pRecycle);
		pActive = Backup;
	}


	//リサイクルを一回実行
	int nCntRes = 0;
	nCntRes = Recycle();
	printf("リサイクルされたオブジェクトの数 %d\n",nCntRes);


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

