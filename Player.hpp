/*
�����̃w�b�_�t�@�C������ǂݍ��܂��w�b�_�t�@�C���ɂ�
"#pragma once"�����A�N���X�̍Ē�`�������B 
*/
#pragma once
#include "Include.hpp"

/*
Human��Machine�̊��N���X�ŁA�u�v���C���[�v�Ƃ��ĕK�v�ȋ@�\�����B
�܂��A�����z�֐������邽�߁A���ۃN���X�ł�����B
*/
class Player{
protected:	
	//�q�N���X�Ŏg���ϐ��̃A�N�Z�X�C���q��private�ł͂Ȃ�protected
	bool turn;	//�����̃^�[��
	int number;	//�����̐���
	map<int, int> query_reply_map;	//����ƕԎ��̗���
	string name;	//���O
public:

	/* �����z�֐�( �֐�=0;�̂�� )�͎q�N���X�ŕK���I�[�o�[���C�h���Ȃ���΂Ȃ�Ȃ� */
	//�����̐�����I��
	virtual void SelectMyNumber()=0;
	
	//����Ɏ���𑗂�
	virtual int SendQuery()=0;
	
	//����̎�����󂯎��
	virtual void ResvQuery(int query, int reply)=0;
	
	//name�ȊO������������֐�
	virtual void Init()=0;

	/* ���̂܂܌p���������֐� */
	//�Ԏ�������
	int SendReply(int query);

	//���O��Ԃ�
	string getName(){return this->name;}

	//�����̐�����\������
	void ShowMyNumber(){ cout << this->name << ">>my number is" << number << endl; }

	//����̗�����\������
	void ShowQueryHistory();

	//�R���X�g���N�^
	Player(bool turn){
		this->turn = turn;
	}

};
