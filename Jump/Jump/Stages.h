#ifndef STAGES_H
#define STAGES_H
#include"Obj.h"

int StagesInitialize();	//�摜�ǂݍ��݂Ȃ�

int StageLoad(int stagenum);	//���Ԗڂ̃X�e�[�W��ǂݍ��ނ�

int StageUpdata(int stagenum, int count, int flag,Dot pcenter);	//�ǂ���������

SquareMng GetStageWalls_judge();

SquareMng GetStageWalls_view();

int GetStageLimit();

int DrawStage(int count);	//�`��CUI�͔Y�݂ǂ���C�����ł�����

int StageEnd();	//�F�X������




#endif // !STAGES_H
