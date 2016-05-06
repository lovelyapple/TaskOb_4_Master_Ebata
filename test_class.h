//----------------------------------------------------------
//クラスヘッダー
//----------------------------------------------------------
#ifndef	_CLASS_H
#define _CLASS_H
#include <stdio.h>
#include "macro.h"

class c_Test
{
public:
	c_Test();			//コンストラクタ
	c_Test(int input);	//コンストラクタオーバーロード
	~c_Test();			//デストラクタ
	void CleanArray(void);
	void MoveOut(c_Test& pStart,c_Test& pRecBox);	//リストから取り出す

	c_Test*	m_pPrev;		//前のクラスへのポインター
	c_Test*	m_pNext;		//後のクラスへのポインター
private:
	int		m_nData;	//メンバー
};

void Addc_Test(c_Test& pStart);
void Delete_Test(c_Test* pStart);

#endif