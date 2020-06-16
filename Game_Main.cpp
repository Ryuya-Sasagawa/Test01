#include "DxLib.h"
#include "SceneMgr.h"
#include "MouseState.h"
#include "KeyboardState.h"

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK);

	ScrMgr_t scrMgr;	// �V�[���Ǘ��\����

	EScene scene = None;		// ���݃V�[��
	EScene nextScene = None;	// ���̃V�[��

	int key[256];		// �L�[�{�[�h��Ԋi�[�ϐ�
	Mouse_t mouse;		// �}�E�X��Ԋm�F�ϐ�

	Pazzle pz = tutorialPz;		// �V�ԃp�Y��(������Ԃ̓`���[�g���A���p�Y��)

	scene = CheckPlayerID("�t�@�C���p�X");		// �N��������
	
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && scene != None) {
		GetKeyBoardState(key);		// �L�[�{�[�h��Ԏ擾
		GetMouseState(&mouse);		// �}�E�X��Ԏ擾

		// �V�[�����J�ڂ���Ȃ��
		if (scene != nextScene) {	
			scene = InitializeScene(nextScene, &scrMgr);	// �J�ڐ�̃V�[���̏����������s���āC���̃V�[������J��
			FinalizeScene(scene, &scrMgr);					// �J�ڑO�̂̃V�[�����I��
		}

		nextScene = UpdateScene(scene, &scrMgr, mouse, key, &pz);	// ���̃V�[���̍X�V(�`����܂�)���đJ�ڐ�̃V�[�������߂�
	}

	DxLib_End();		    // �c�w���C�u�����g�p�̏I������
	return 0;				// �\�t�g�̏I�� 
}