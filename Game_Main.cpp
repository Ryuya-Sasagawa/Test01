#include "DxLib.h"
#include "SceneMgr.h"
#include "MouseState.h"
#include "KeyboardState.h"
#include "Information.h"
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK);
	SetGraphMode(1080, 720, 16);
	SetBackgroundColor(255, 255, 255);
	
	

	ScrMgr_t scrMgr;

	int scene=none;
	int nextScene = InputNickNameScr;

	int key[256];
	Mouse_t mouse;

	//Puzzle_t pz= tutorialPz;

	//scene = CheckPlayerID("ファイルパス");
	Puzzle_t pz;

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && scene != None) {
		GetKeyBoardState(key);
		GetMouseState(&mouse);

		if (scene != nextScene) {	
			scene = InitializeScene(nextScene, &scrMgr);
			FinalizeScene(scene, &scrMgr);
		}

		nextScene = UpdateScene(scene, &scrMgr, &mouse, key, &pz);
	}

	DxLib_End();
	return 0;	
}