/******************************************
*** Designer : ����
*** Date     : 2020.6.12
*** Purpose  : ���C������
*******************************************/

#include "DxLib.h"
#include "SceneMgr.h"
#include "MouseState.h"
#include "Information.h"

/*****************************************************
*** Function Name : WinMain
*** Designer      : ����
*** Date          : 2020.7.20
*** Function      : ���C���֐�
*** Return        : 0 (�v���O�����̐���I��)
******************************************************/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	SetGraphMode(1080, 720, 16);	// �E�B���h�E�T�C�Y��1080�~720�ɐݒ�
	ChangeWindowMode(TRUE);	// �E�B���h�E���[�h�ɐݒ�
	DxLib_Init();	// DxLib������
	SetDrawScreen(DX_SCREEN_BACK);	// ����ʂɐݒ�
	SetBackgroundColor(222, 184, 135);	// �w�i�F��(R, G, B) = (222, 184, 135)�ɐݒ�
	
	ScrMgr_t scrMgr;	// �\������V�[�������V�[���\���̂̕ϐ�

	int scene = None;	// ���݂̃V�[���ԍ����i�[����ϐ�
	int nextScene = InputNickNameScr;	// ���̑J�ڐ�̃V�[�����i�[����ϐ�

	Mouse_t mouse;	// �g���Ă���}�E�X�ɑΉ�����}�E�X�ϐ�

	Puzzle_t pz;	// �V�ԃp�Y���̃p�Y���ϐ�

	// ���C�����[�v
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {
		GetMouseState(&mouse, TRUE);	// �}�E�X�̏�ԍX�V(C1:M4)

		// �}�E�X�̃{�^����������Ă��Ȃ����
		if (mouse.mButton == none) {
			mouse.waitRelease = 0;	// �������ςȂ���Ԃ���ύX
		}

		SetDrawScreen(DX_SCREEN_BACK);	// ����ʂɐݒ�

		// ���݂̃V�[���Ǝ��̃V�[�����قȂ��Ă�����
		if (scene != nextScene) {
			FinalizeScene(scene, &scrMgr, &pz);	// ���݂̃V�[���ɑ΂��ďI������(C1:M3)
			scene = InitializeScene(nextScene, &scrMgr, &pz);// ���̃V�[����������(C1:M1)���Č��݂̃V�[���ɃZ�b�g
		}

		nextScene = UpdateScene(scene, &scrMgr, &mouse, &pz);	// ���݂̃V�[�����X�V(C1:M2)���Ď��̃V�[���ɃZ�b�g
	}

	DxLib_End();	// DxLib���
	return 0;	// ����I��
}