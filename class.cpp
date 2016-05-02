//----------------------------------------------------------
//クラスCPP
//----------------------------------------------------------
#include "test_class.h"
c_Test::c_Test()
{
	//何もしない
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
	//動的ダミーのオブジェクトを使い、自分のアドレスを保存
	c_Test pDummy;
	pDummy.m_pNext = m_pPrev->m_pNext;

	//自分をリストから取り出す
	m_pPrev->m_pNext	= m_pNext;//前オブジェクトのNext　を自分の次に指す
	m_pNext->m_pPrev	= m_pPrev;//後オブジェクトのPrev　を自分の前に指す

	//ダミーを使い、自分をリサイクルの中に入れる
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





