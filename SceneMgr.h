#ifndef SCENEMGR_H_
#define SCENEMGR_H_

#include "InputNickName.h"
#include "Menu.h"
#include "Selection.h"
#include "Game.h"
#include "MakePuzzle.h"
#include "MouseState.h"

// �V�[���񋓑�
typedef enum {
	InputNickNameScr,	// �j�b�N�l�[�����͉��
	MenuScr,			// ���j���[���
	SelectionScr,		// ��Փx�E�p�Y���I�����
	GameScr,			// �`���[�g���A��/�Q�[���v���C���
	MakePuzzleScr,			// �p�Y���쐬/���e���
	None				// �ڑ����s
} EScene;

//�@�V�[���Ǘ��\����
typedef struct SCR_MGR {
	InputNickName_t mInputNickName;	// �j�b�N�l�[�����͉�ʍ\����
	Menu_t          mMenu;			// ���j���[��ʍ\����
	Selection_t	    mSelection;		// ��Փx�E�p�Y���I����ʍ\����
	Game_t          mGame;			// �`���[�g���A��/�Q�[���v���C��ʍ\����
	MakePuzzle_t    mMakePuzzle;	// �p�Y���쐬/���e��ʍ\����
} ScrMgr_t;							


// M1:�V�[������������
EScene InitializeScene(EScene nextScene, ScrMgr_t* scrMgr);

// M2:�V�[���X�V����
EScene UpdateScene(EScene scene, ScrMgr_t* scrMgr, Mouse_t mouse, int* key, Puzzle puzzle);

// M3:�V�[���I������
void FinalizeScene(EScene scene, ScrMgr_t* scrMgr);

#endif /* SCENEMGR_H_ */
