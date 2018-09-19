#ifndef PLAYER_H
#define PLAYER_H

#include"Obj.h"

class Player{

public:/*
	Player();
	~Player();*/
	void Initialize();	//�Q�[���J�n���i�摜�n���h�����Ӂj
	void PlayAttack_s();
	void PlayAttack_l();
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
	void SetJump();
	void UpdataJump(int count,int flag);
	void SetPriJump();
	void UpdataPriJump(int count);
	void SetAttack_w();
	void UpdataAttack_w(int count);
	void SetAttack_s();
	void UpdataAttack_s(int count);
	void SetAttack_l();
	void UpdataAttack_l(int count);
	void Updata(int count,int key[]);
	int GetStateFlag();
	int GetIsRightFlag();
	Dot GetCenter();
	int WeaponFlag;
	Square GetAttackArea();
	Dot weapon;
	int GetAttack();
	int Draw();
	int PriJump;
	//int height;			//�`�掞�̃v���C���[���̂̍��� P_REAL_HEIGHT*P_RATIO
	//int width;
	int End();

private:
	Dot center;			//���S���W
	Square weakArea;	//��_���͈�
	Square attackArea;	//�^�_���͈�
	//int jump;			
	int attack;			//���݂̍U����
	int Image;			//���݂̉摜
	int bodyClock;		//�A�j���[�V�����p�̓����v
	int IsJumping;		//jump���U���pflag
	int isRightFlag;	//�����Ă�����t���O�i0�ō� 1�ŉE�j
	int acceptFlag;		//���͎�t�t���O�i1�Ŏ�t�j
	
	int stateFlag;		//����ԃt���O
	/*
	0 stand
	1 run
	2 dash
	3 guard
	4 jump
	5 attack_strong
	6 attack_weak
	7 attack_long
	8 princess_jump
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