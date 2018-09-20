#include"DxLib.h"
#include"Chore.h"
#include"Value.h"
#include"input.h"

//TODO
//ServerDrawを円の面積に
//人の向きで撮影判定
//データの流れの可視化(Drawlineとかで)
//このシミュレータ用のデータ形式の定義
//オープンデータと↑を繋ぐ

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	SetGraphMode(DISP_WIDTH, DISP_HEIGHT, 32);
	SetBackgroundColor(100,100,100);
	{
		SetWindowSizeChangeEnableFlag(TRUE);
		SetWindowSizeExtendRate(0.6);
		ChangeWindowMode(TRUE);
	}

	DxLib_Init();
	SetDrawScreen(DX_SCREEN_BACK);

	//XINPUT_STATE input;

	int Key[11] = { 0 };

	int flag = 0;
	int selectFlag = 0;	//0:simulate,1:manual,2:credit
	int count = 0;
	int keep_count = 0;

	SystemInitialize();
	
	//InputFile("kanuma2017.txt");

	Dot start;
	start.Set(DISP_WIDTH / 2.0, DISP_HEIGHT / 2.0);
	/*Dot camera[1];
	camera[0].Set(DISP_WIDTH / 3.0, DISP_HEIGHT / 3.0);*/
	double dir[1] = { PI / 3.0 };
	SetBack();

	flag = 0;
	int down = 0;
	int up = 0;
	int sum = 0;
	while (!ScreenFlip() && !ProcessMessage() && !ClearDrawScreen()) {

		//GetJoypadXInputState(DX_INPUT_PAD1, &input);
		//InputUpdata(input, Key);
		InputUpdata(Key);
		PrintInput(Key);

		DrawBack();

		switch (flag) {
		case 0://初期化
			count = 0;
			
			break;
		case 1://書く
			if (CheckHitKey(KEY_INPUT_SPACE))flag++;
			break;
		case 2://出力
			break;
		case 3://マニュアル
			if (DrawManual(A)) {
				flag = 0;
				count = 0;
			}
			break;
		default:
			break;
		}

		count++;
		if (CheckHitKey(KEY_INPUT_DELETE)) break;
		FpsTimeFanction();
		ScreenFlip();
	}

	//UpdataFile("kanuma2017.txt", 0, 0);
	DxLib_End();

	return 0;
}