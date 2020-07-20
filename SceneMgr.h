/******************************************
*** Designer : ����
*** Date     : 2020.6.12
*** Purpose  : �`���[�g���A��/�Q�[���v���C��ʂ�
			�@�@�̍\����Game_t�̃����o�Ɗe�֐���
			   �v���g�^�C�v�錾(M12~M15)
*******************************************/

#ifndef SCENEMGR_H_
#define SCENEMGR_H_

#include "InputNickName.h"
#include "Menu.h"
#include "Selection.h"
#include "Game.h"
#include "MakePuzzle.h"
#include "MouseState.h"
#include "Information.h"

// �V�[���ԍ�
typedef enum {
	InputNickNameScr,	//�@�N�����V�[���ԍ�
	MenuScr,	//�@���j���[�V�[���ԍ�
	SelectionScr,	//�@��Փx�E�p�Y���I���V�[���ԍ�
	GameScr,	//�@�`���[�g���A��/�Q�[���v���C�V�[���ԍ�
	MakePuzzleScr,	// �p�Y���쐬�V�[���ԍ�
	None	// ���N���V�[���ԍ�
}EScene;

// �V�[���\����
typedef struct SCR_MGR {
	InputNickName_t mInputNickName;	// �N������ʍ\����
	Menu_t          mMenu;	// ���j���[��ʍ\����
	Selection_t	    mSelection;	// ��Փx�E�p�Y���I����ʍ\����
	Game_t          mGame;	// �`���[�g���A��/�Q�[���v���C��ʍ\����
	MakePuzzle_t    mMakePuzzle;	// �p�Y���쐬��ʍ\����
} ScrMgr_t;

// M1:�V�[������������
int InitializeScene(int, ScrMgr_t*, Puzzle_t*);

// M2:�V�[���X�V����
int UpdateScene(int, ScrMgr_t*, Mouse_t*, Puzzle_t*);

// M3:�V�[���I������
void FinalizeScene(int, ScrMgr_t*, Puzzle_t*);

#endif /* SCENEMGR_H_ */