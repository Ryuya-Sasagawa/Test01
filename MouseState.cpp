#include "DxLib.h"
#include "MouseState.h"

void GetMouseState(Mouse_t* mouse) {
	mouse->mButton = GetMouseInput();			// �}�E�X�̓��͏�Ԏ擾
	mouse->mWheel = GetMouseWheelRotVol();		// �}�E�X�̃z�C�[����]�ʎ擾
	GetMousePoint(&(mouse->mX), &(mouse->mY));	// �}�E�X�̍��W�擾
}