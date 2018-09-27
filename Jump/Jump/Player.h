#ifndef PLAYER_H
#define PLAYER_H

#include"Obj.h"

class Player{

public:/*
	Player();
	~Player();*/
	int Initialize();	//�Q�[���J�n���i�摜�n���h�����Ӂj

	int Set(int stageflag);			//�v���C�J�n���i���W���Ӂj

	int SetStand(int count);		//stand��Ԃɓ���֐�
	int SetDash(int count);
	int SetJump(int count);
	int SetAttack_s(int count);
	int SetAttack_w(int count);
	int SetDamage(int count);
	//int SetAttack_air(int count);
	//int SetKunai(int count);

	int Update1(int count, int key[]);	//���͎��ӂ̏���
	int Update2(SquareMng a);	//�ǎ��ӂ̏���
	//int Update2(SquareMng a,imageSquareMng b);	//�ǎ��ӂ̏���

	int UpdateStand(int count);		//stand��Ԓ��̏���,�A�j���[�V������U���͂̐ݒ�
	int UpdateDash(int count);
	int UpdateJump(int count);
	int UpdateAttack_s(int count);
	int UpdateAttack_w(int count);
	int UpdataDamge(int count);
	//int UpdateAttack_air(int count);
	//int UpdateKunai(int count);

	int PlayAttack_s();	//���ʉ�
	int PlayAttack_w();
	int PlayGet();
	int PlayJump();
	
	int GetStateFlag();
	int GetIsRightFlag();
	Dot GetCenter();
	SquareMng GetAttackAreaMng();
	SquareMng GetWeakAreaMng();
	Dot weapon;
	int GetAttack();
	int Draw();
	int End();

private:
	Dot center;			//���S���W
	Dot acceleration;	//�����x
	Dot velocity;		//���x
	Dot telepo_back;	//0,0�ȊO�Ȃ�e���|��

	SquareMng weakAreaMng;	//��_���͈�
	SquareMng attackAreaMng;	//�^�_���͈�

	int attack;			//���݂̍U����
	int image;			//���݂̉摜
	int bodyClock;		//�A�j���[�V�����p�̓����v
	bool isRightFlag;	//�����Ă�����t���O�i0�ō� 1�ŉE�j
	bool acceptFlag;	//���͎�t�t���O�i1�Ŏ�t�j
	bool isAir;			//�󒆂��ۂ��̃t���O
	//bool onSquare;		//�l�p�̏�ɂ��邩�ۂ��̃t���O
	
	int stateFlag;		//����ԃt���O
	/*
	0 stand
	1 dash
	2 jump
	3 attack_strong
	4 attack_weak
	5 attack_air
	6 telepo
	7 damage
	*/
	
};
//
//Player::Player()
//{
//}
//
//Player::~Player()
//{
//}

#endif // !PLAYER_H