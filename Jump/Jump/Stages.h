#ifndef STAGES_H
#define STAGES_H
#include"Obj.h"

int StagesInitialize();	//画像読み込みなど

int StageLoad(int stagenum);	//何番目のステージを読み込むか

bool StageBeforeDescription(int stageFlag, int key[]);

int StageUpdata(int stagenum, int count, int flag);	//壁が動いたり

SquareMng GetStageStaticWalls();

SquareMng GetStageWalls();

int GetStageLimit();

int DrawStage(int count);	//描画，UIは悩みどころ，ここでいいか

int StageEnd();	//色々を消す




#endif // !STAGES_H
