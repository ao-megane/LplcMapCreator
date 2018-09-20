#include"Chore.h"
#include"DxLib.h"
#include"Value.h"
#include"Obj.h"
#include<fstream>
#include<string>
#include<iostream>
#include<sstream>
#include<list>
#include<stdio.h>

int Loading;
int Credit;
int Tytle;
int Logo;
int Pause;
int Manual;
int Prologue[6];
int UIBack;
int UIIcon;

int Keeper;	//透過用カウントキーパー
int flag;	//現状態フラグ 0 normal 1 ending 2 bord

int BGM;
int Move;
int Choice;

int proFlag;
int manFlag;

int Score;

int nishiki;
int SystemInitialize() {
	Prologue[0] = LoadGraph("images/system/prologue/1.png");
	Prologue[1] = LoadGraph("images/system/prologue/2.png");
	Prologue[2] = LoadGraph("images/system/prologue/3.png");
	Prologue[3] = LoadGraph("images/system/prologue/4.png");
	Prologue[4] = LoadGraph("images/system/prologue/5.png");
	Prologue[5] = LoadGraph("images/system/prologue/6.png");


	if (AddFontResourceEx("Font/nishiki-teki.ttf", FR_PRIVATE, NULL) == 0) {
		//printfDx("AddFontResourceEx失敗\n");
	}
	nishiki = CreateFontToHandle("Nishiki-teki", 60, -1, DX_FONTTYPE_ANTIALIASING_8X8);
	if (nishiki == -1) {
		//printfDx("CreateFontToHandle失敗\n");
	}
	Keeper = 0;
	flag = 0;
	proFlag = 0;
	manFlag = 0;

	return 0;
}

int PlayMove() {
	PlaySoundMem(Move, DX_PLAYTYPE_BACK);
	DrawFormatString(0, 40, RED, "Sound!");
	return 0;
}

int PlayChoice() {
	PlaySoundMem(Choice, DX_PLAYTYPE_BACK);
	DrawFormatString(0, 40, RED, "Sound!");
	return 0;
}

int* ScorePass() {
	return &Score;
}

int PlayBGM() {
	PlaySoundMem(BGM, DX_PLAYTYPE_LOOP);
	return 0;
}

int DrawOP() {
	//DrawModiGraph(0, 0, DISP_WIDTH, 0, DISP_WIDTH, DISP_HEIGHT, 0, DISP_HEIGHT, Tytle, true);
	DrawFormatString(0, 0, RED, "TYTLE");
	/*DrawModiGraph(
		DISP_WIDTH / 2 + 185	  , DISP_HEIGHT / 2 + 170 + (levelFlag) * 110,
		DISP_WIDTH / 2 + 200 + 185, DISP_HEIGHT / 2 + 170 + (levelFlag) * 110,
		DISP_WIDTH / 2 + 200 + 185, DISP_HEIGHT / 2 + 200 + 170 + (levelFlag) * 110,
		DISP_WIDTH / 2 + 185	  , DISP_HEIGHT / 2 + 200 + 170 + (levelFlag) * 110,
		Allow, true);*/
	return 0;
}
int DrawPrologue(int b) {
	//DrawModiGraph(0, 0, DISP_WIDTH, 0, DISP_WIDTH, DISP_HEIGHT, 0, DISP_HEIGHT, ProBack, true);
	switch (proFlag)
	{
	case 0:
		DrawModiGraph(0, 0, DISP_WIDTH, 0, DISP_WIDTH, DISP_HEIGHT, 0, DISP_HEIGHT, Prologue[1], true);
		DrawFormatString(0, 20, RED, "PROLOGUE1");
		break;
	case 1:
		DrawModiGraph(0, 0, DISP_WIDTH, 0, DISP_WIDTH, DISP_HEIGHT, 0, DISP_HEIGHT, Prologue[2], true);
		DrawFormatString(0, 40, RED, "PROLOGUE2");
		break;
	case 2:
		DrawModiGraph(0, 0, DISP_WIDTH, 0, DISP_WIDTH, DISP_HEIGHT, 0, DISP_HEIGHT, Prologue[3], true);
		DrawFormatString(0, 80, RED, "PROLOGUE3");
		break;
	case 3:
		DrawModiGraph(0, 0, DISP_WIDTH, 0, DISP_WIDTH, DISP_HEIGHT, 0, DISP_HEIGHT, Prologue[4], true);
		DrawFormatString(0, 120, RED, "PROLOGUE4");
		break;
	default:
		break;
	}
	if (b == 1) {
		proFlag++;
		if (proFlag == 4) {
			proFlag = 0;
			return 1;
		}
	}
	return 0;
}

int DrawPause() {
	//DrawModiGraph(0, 0, DISP_WIDTH, 0, DISP_WIDTH, DISP_HEIGHT, 0, DISP_HEIGHT, Pause, true);
	DrawFormatString(0, 0, RED, "PAUSE");
	DrawFormatString(0, 20, RED, "Aでタイトルに戻る");
	DrawFormatString(0, 40, RED, "Wでさっきの画面に戻る");
	return 0;
}

//int manFlag;
int DrawManual(int b) {
	switch (manFlag)
	{
	case 0:
		//DrawModiGraph(0, 0, DISP_WIDTH, 0, DISP_WIDTH, DISP_HEIGHT, 0, DISP_HEIGHT, Manual, true);
		DrawFormatString(0, 0, RED, "MANUAL");
		break;
	//case 1:
	//	DrawModiGraph(0, 0, DISP_WIDTH, 0, DISP_WIDTH, DISP_HEIGHT, 0, DISP_HEIGHT, Manual2, true);
	//	//DrawFormatString(0, 0, RED, "2");
		break;
	}

	if (b == 1) {
		manFlag++;
		if (manFlag == 2) {
			manFlag = 0;
			return 1;
		}
	}
	return 0;
}

int DrawCredit() {
	DrawFormatStringFToHandle(DISP_WIDTH / 2, DISP_HEIGHT / 2, RED, nishiki, "CREDIT!");
	//DrawModiGraph(0, 0, DISP_WIDTH, 0, DISP_WIDTH, DISP_HEIGHT, 0, DISP_HEIGHT, Credit2, true);
	return 0;
}

void DrawChore() {
	DrawFormatString(0, 0, RED, "UI?");
	//if (count < NORMAL_COUNT) {
	//	DrawModiGraph(
	//		UI_MARGIN_WIDTH, UI_MARGIN_HEIGHT,
	//		UI_WIDTH + UI_MARGIN_WIDTH, UI_MARGIN_HEIGHT,
	//		UI_WIDTH + UI_MARGIN_WIDTH, UI_HEIGHT + UI_MARGIN_HEIGHT,
	//		UI_MARGIN_WIDTH, UI_HEIGHT + UI_MARGIN_HEIGHT, UIBack, true);

	//DrawFormatStringFToHandle(DISP_WIDTH - 500, 10, BROWN, nishiki, "SCORE : %5d", Score);
}

int SetBack() {
	
	return 0;
}

int UpdataBack(int count) {//count使わなくてもできる(?)
	return 0;
}

int DrawBack() {
	return 0;
}

/*---------------------------------------------------------------------------*/

int InputFile(std::string file) {
	std::ifstream fin("kanuma2017.txt"); // ファイルを開く
	if (fin.fail()) {  // if(!fin)でもよい。
		std::cout << "入力ファイルをオープンできません" << std:: endl;
		return 1;
	}
	//fin >> NumofPlayers >> NumofWinner >> HighScore;

	return 0;
}

int DrawData() {
	/*DrawFormatStringToHandle(DISP_WIDTH / 2 - 500, 50, BROWN, nishiki, "プレイ人数:%3d", NumofPlayers);
	DrawFormatStringToHandle(DISP_WIDTH / 2 + 0, 50, BROWN, nishiki, "クリア率:%5.2f%%", (double)(NumofWinner)/(double)(NumofPlayers) * 100.0);
	DrawFormatStringToHandle(DISP_WIDTH / 2 + 500, 50, BROWN, nishiki, "ハイスコア:%5d", HighScore);
	*/
	DrawFormatString(0, 100, RED, "DATA!");
	return 0;
}

int UpdataFile(std::string file, int levelFlag, int score) {
	std::ofstream fout("kanuma2017.txt");
	if (fout.fail()) {  // if(!fin)でもよい。
		std::cout << "出力ファイルをオープンできません" << std::endl;
		return 1;
	}
	//fout << NumofPlayers << "\n" << NumofWinner << "\n" << HighScore << "\n";

	return 0;
}

bool IsHitColorCtoAll(Circle x, int a, int image) {
	//半径の正方形作って，その中で円内の点を判定
	if (image == 0)//階段内
		return false;
	for (int i = x.Getx() - x.GetRadius(); i < x.Getx() + x.GetRadius(); i++) {
		for (int j = x.Getx() - x.GetRadius(); j < x.Getx() + x.GetRadius(); j++) {
			if ((i*i + j*j) <= x.GetRadius()*x.GetRadius())
				if (a == GetPixelPalCodeSoftImage(image, x.Getx(), x.Gety()))
					return true;
		}
	}
	return false;
}

int r, g, b,a;
bool IsHitColorDot(Dot x, int R,int G,int B, int Softimage) {
	GetPixelSoftImage(Softimage, x.Getx(), x.Gety(), &r, &g, &b, &a);
	if (R == r && G == g && B == b) {
		return true;
	}
	else {
		return false;
	}
}

Dot RotateDot(double thita, Dot x, Dot c) {
	Dot ans;
	ans.Setx((x.Getx() - c.Getx())*cos(-thita) - (x.Gety() - c.Gety())*sin(-thita) + c.Getx());
	ans.Sety((x.Getx() - c.Getx())*sin(-thita) + (x.Gety() - c.Gety())*cos(-thita) + c.Gety());
	return ans;
}

/*----------------------------------------------------------------------------------------------*/

int counter = 0, FpsTime[2] = { 0, }, FpsTime_i = 0;
double Fps = 0.0;
char Key[256];
void FpsTimeFanction() {
	if (FpsTime_i == 0)
		FpsTime[0] = GetNowCount();               //1周目の時間取得
	if (FpsTime_i == 49) {
		FpsTime[1] = GetNowCount();               //50周目の時間取得
		Fps = 1000.0f / ((FpsTime[1] - FpsTime[0]) / 50.0f);//測定した値からfpsを計算
		FpsTime_i = 0;//カウントを初期化
	}
	else
		FpsTime_i++;//現在何周目かカウント
	if (Fps != 0)
		DrawFormatString(DISP_WIDTH-200, DISP_HEIGHT-40, WHITE, "FPS %.1f", Fps); //fpsを表示
	return;
}