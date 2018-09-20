#ifndef PLAYER_H
#define PLAYER_H

#include"Obj.h"

class Player{

public:/*
	Player();
	~Player();*/
	void Initialize();	//�Q�[���J�n���i�摜�n���h�����Ӂj
	void PlayAttack_s();
	void PlayAttack_w();
	void PlayGet();
	void PlayJump();
	void Set(int levelFlag);			//�v���C�J�n���i���W���Ӂj
	void SetStand();		//private��������֐�
	void UpdataStand(int count);//�_�b�V�����̍��W����������֐�
	void SetWalk();		
	void UpdataWalk(int count);
	void SetDash();
	void UpdataDash(int count);
	/*void SetGuard();
	void UpdataGuard(int count);*/
	void SetJump(int count);
	void UpdataJump(int count);
	void SetAttack_w();
	void UpdataAttack_w(int count);
	void SetAttack_s();
	void UpdataAttack_s(int count);
	void Updata(int count,int key[]);
	int GetStateFlag();
	int GetIsRightFlag();
	Dot GetCenter();
	int WeaponFlag;
	Square GetAttackArea();
	Dot weapon;
	int GetAttack();
	int Draw();
	//int height;			//�`�掞�̃v���C���[���̂̍��� P_REAL_HEIGHT*P_RATIO
	//int width;
	int End();

private:
	Dot center;			//���S���W
	Dot acceleration;	//�����x
	Dot velocity;		//���x

	Square weakArea;	//��_���͈�
	Square attackArea;	//�^�_���͈�

	int attack;			//���݂̍U����
	int image;			//���݂̉摜
	int bodyClock;		//�A�j���[�V�����p�̓����v
	int IsJumping;		//jump���U���pflag
	bool isRightFlag;	//�����Ă�����t���O�i0�ō� 1�ŉE�j
	bool acceptFlag;		//���͎�t�t���O�i1�Ŏ�t�j
	bool isAir;
	
	int stateFlag;		//����ԃt���O
	/*
	0 stand
	2 dash
	4 jump
	5 attack_strong
	6 attack_weak
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