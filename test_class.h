//----------------------------------------------------------
//�N���X�w�b�_�[
//----------------------------------------------------------
#ifndef	_CLASS_H
#define _CLASS_H
#include <stdio.h>
#include "macro.h"

class c_Test
{
public:
	c_Test();			//�R���X�g���N�^
	c_Test(int input);	//�R���X�g���N�^�I�[�o�[���[�h
	~c_Test();			//�f�X�g���N�^
	void CleanArray(void);
	void MoveOut(c_Test& pStart,c_Test& pRecBox);	//���X�g������o��

	c_Test*	m_pPrev;		//�O�̃N���X�ւ̃|�C���^�[
	c_Test*	m_pNext;		//��̃N���X�ւ̃|�C���^�[
private:
	int		m_nData;	//�����o�[
};

void Addc_Test(c_Test& pStart);
void Delete_Test(c_Test* pStart);

#endif