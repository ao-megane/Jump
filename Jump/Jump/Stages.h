#ifndef STAGES_H
#define STAGES_H
#include"Obj.h"

int StagesInitialize();	//�摜�ǂݍ��݂Ȃ�

int StageLoad(int stagenum);	//���Ԗڂ̃X�e�[�W��ǂݍ��ނ�

bool StageBeforeDescription(int stageFlag, int key[]);

int StageUpdata(int stagenum, int count, int flag);	//�ǂ���������

SquareMng GetStageStaticWalls();

SquareMng GetStageWalls();

int GetStageLimit();

int DrawStage(int count);	//�`��CUI�͔Y�݂ǂ���C�����ł�����

int StageEnd();	//�F�X������




#endif // !STAGES_H
