/******************************************
*** Designer : �ٴ�
*** Date     : 2020.6.12
*** Purpose  : �ᥤ��I��
*******************************************/

#include "DxLib.h"
#include "SceneMgr.h"
#include "MouseState.h"
#include "Information.h"

/*****************************************************
*** Function Name : WinMain
*** Designer      : �ٴ�
*** Date          : 2020.7.20
*** Function      : �ᥤ���v��
*** Return        : 0 (�ץ����������K��)
******************************************************/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	SetGraphMode(1080, 720, 16);	// ������ɥ���������1080��720���O��
	ChangeWindowMode(TRUE);	// ������ɥ���`�ɤ��O��
	DxLib_Init();	// DxLib���ڻ�
	SetDrawScreen(DX_SCREEN_BACK);	// �Y������O��
	SetBackgroundColor(222, 184, 135);	// ����ɫ��(R, G, B) = (222, 184, 135)���O��

	ScrMgr_t scrMgr;	// ��ʾ���륷�`���֤ĥ��`������Ή���

	int scene = None;	// �F�ڤΥ��`�󷬺Ť��{�������
	int nextScene = MenuScr;	// �Τ��w���ȤΥ��`����{�������

	Mouse_t mouse;	// ʹ���Ƥ���ޥ����ˌ��ꤹ��ޥ�������

	Puzzle_t pz;	// �[�֥ѥ���Υѥ������

	// �ᥤ���`��
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {
		GetMouseState(&mouse, TRUE);	// �ޥ�����״�B����(C1:M4)

		// �ޥ����Υܥ���Ѻ����Ƥ��ʤ����
		if (mouse.mButton == none) {
			mouse.waitRelease = 0;	// Ѻ���äѤʤ�״�B������
		}

		SetDrawScreen(DX_SCREEN_BACK);	// �Y������O��

		// �F�ڤΥ��`��ȴΤΥ��`�󤬮��ʤäƤ�����
		if (scene != nextScene) {
			FinalizeScene(scene, &scrMgr, &pz);	// �F�ڤΥ��`��ˌ����ƽK�˄I��(C1:M3)
			scene = InitializeScene(nextScene, &scrMgr, &pz,&mouse);// �ΤΥ��`�����ڻ�(C1:M1)���ƬF�ڤΥ��`��˥��å�
		}

		nextScene = UpdateScene(scene, &scrMgr, &mouse, &pz);	// �F�ڤΥ��`������(C1:M2)���ƴΤΥ��`��˥��å�
	}

	DxLib_End();	// DxLib���d
	return 0;	// �����K��
}