#ifndef VALUE_H
#define VALUE_H
#include"dxlib.h"

#define PI 3.1415926535

const int RED = GetColor(255, 0, 0);
const int GREEN = GetColor(0, 255, 0);
const int BLUE = GetColor(0, 0, 255);
const int BLACK = GetColor(0, 0, 0);
const int GRAY = GetColor(127, 127, 127);
const int WHITE = GetColor(255, 255, 255);
const int ORANGE = GetColor(243, 152, 0);
const int BROWN = GetColor(46, 33, 13);

#define W (Key[0])
#define A (Key[1])
#define S (Key[2])
#define D (Key[3])
#define L_CLICK (Key[11])
#define RIGHT (Key[4])
#define LEFT (Key[5])
#define R_TRIG (Key[6]) //Trigから加算を始める
#define L_TRIG (Key[7]) //Trigから加算を始める
#define THUMB_Y (Key[8])//-100～+100 100が最大値
#define THUMB_X (Key[9]) //-100～+100 100が最大値
#define PAUSE (Key[10])

//const int Trig = 200; //R2L2のカウントを始めるしきい値
//const int ThumbTrig = 16383; //thumbの無視する範囲 ～32767

const int DISP_WIDTH = 1366;	//画面の大きさ(tamuraPC)
const int DISP_HEIGHT = 768;

//const int DOOR = GetColor(0, 255, 0);
//const int WALL = GetColor(0, 0, 0);
//const int STEP1 = GetColor(255, 0, 0);
//const int STEP2 = GetColor(0, 0, 255);
//const int FLOOR1 = GetColor(0, 0, 255);
//const int FLOOR2 = GetColor(0, 0, 255);

const int P_SIZE = 20;	//プレイヤーの半径
const double P_SPEED = 0.02;
//↑判定系 ↓描画系
const double P_WIDTH = 1 * P_SIZE;
const double P_HEIGHT = 1 * P_SIZE;
const int P_NUM = 1; //同時に描画する最大人数

//const int C_NUM = 1;
const int CAMERA_SIZE = 100;//正方形
const int COVERAGE_SIZE = 200;//正方形
const int COVERAGE_COLOR = WHITE;
const int EFFICI_ANGLE = PI / 6.0;

const int UI_HEIGHT = 400;
const int UI_WIDTH = 300;
const int UI_MARGIN_HEIGHT = 20;
const int UI_MARGIN_WIDTH = 20;

const int WIFIRANGE = 40;

const int SERVER_NUM = 1;		//サーバーの数
const int SERVER_C_MAX = 10;	//サーバーの持つ最大のカメラの数

#endif // !VALUE_H
