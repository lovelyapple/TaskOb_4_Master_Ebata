//----------------------------------------------------------
//クラスヘッダー
//----------------------------------------------------------
#ifndef	_CLASS_H
#define _CLASS_H
#include <stdio.h>

class Class
{
public:
	Class();			//コンストラクタ
	Class(int input);	//コンストラクタオーバーロード
	~Class();			//デストラクタ

	Class*	pPrev;		//前のクラスへのポインター
	Class*	pNext;		//後のクラスへのポインター
private:
	int		m_nData;	//メンバー


};

void AssertClass(Class* pStart);
#endif