//----------------------------------------------------------
//�N���X�w�b�_�[
//----------------------------------------------------------
#ifndef	_CLASS_H
#define _CLASS_H
#include <stdio.h>

class Class
{
public:
	Class();			//�R���X�g���N�^
	Class(int input);	//�R���X�g���N�^�I�[�o�[���[�h
	~Class();			//�f�X�g���N�^

	Class*	pPrev;		//�O�̃N���X�ւ̃|�C���^�[
	Class*	pNext;		//��̃N���X�ւ̃|�C���^�[
private:
	int		m_nData;	//�����o�[


};

void AssertClass(Class* pStart);
#endif