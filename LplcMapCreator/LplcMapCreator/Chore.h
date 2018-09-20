#ifndef CHORE_H
#define CHORE_H
#include"Obj.h"
#include<string>

//イベント画像、背景画像、UI、等など

int SystemInitialize();

int PlayMove();

int PlayChoice();

int* ScorePass();

int DrawOP();

int PlayBGM();

int DrawPrologue(int b);

int DrawManual(int b);

int DrawCredit();

int DrawPause();

//void DrawChore();

int SetBack();

int UpdataBack(int count);

int DrawBack();

int EndBack();

int InputFile(std::string file);

int DrawData();

int UpdataFile(std::string file,int levelFlag,int score);//呼び出される->一人分の更新

bool IsHitColorCtoAll(Circle x,int colorHandle,int imageHandle);

bool IsHitColorDot(Dot x, int R, int G, int B, int Softimage);

Dot RotateDot(double thita, Dot x, Dot c);

void FpsTimeFanction();

#endif // !CHORE_H
