#ifndef CHORE_H
#define CHORE_H
#include"Obj.h"
#include<string>

//�C�x���g�摜�A�w�i�摜�AUI�A���Ȃ�

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

int UpdataFile(std::string file,int levelFlag,int score);//�Ăяo�����->��l���̍X�V

bool IsHitColorCtoAll(Circle x,int colorHandle,int imageHandle);

bool IsHitColorDot(Dot x, int R, int G, int B, int Softimage);

Dot RotateDot(double thita, Dot x, Dot c);

void FpsTimeFanction();

#endif // !CHORE_H
