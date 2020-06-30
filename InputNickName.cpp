/***************************
*** Designer	:����
*** Date		:2020.06.23
*** Purpsoe		:C1 UI������	M5 �j�b�N�l�[�����͉�ʏ���
***************************/

#include <stdio.h>
#include <Windows.h>
#include"InputNickName.h"
#include "DxLib.h"
#include "SceneMgr.h"

//memo(�쐬�A�C���\��)
/*
�E�j�b�N�l�[���̏ƍ��������
�E�f�U�C����ύX����
�E�t�H���g�T�C�Y�̎d�l��ύX����
*/

//standard
static int textX = (int)(SCR_SIZE_X / 2 - FONT_SIZE * 12);
static int textY = (int)(SCR_SIZE_Y * 0.2);
static int textBoxX1 = (int)(SCR_SIZE_X / 2 - FONT_SIZE * 8), textBoxX2 = (int)(SCR_SIZE_X / 2 + FONT_SIZE * 8);
static int textBoxY1 = (int)(SCR_SIZE_Y * 0.4), textBoxY2 = (int)(SCR_SIZE_Y * 0.4 + FONT_SIZE * 2);
static int limitX = (int)(SCR_SIZE_X / 2 + FONT_SIZE * 6);
static int limitY = (int)(SCR_SIZE_Y * 0.4 - FONT_SIZE);
static int OKRectX1 = (int)(SCR_SIZE_X / 2 - FONT_SIZE * 3), OKRectX2 = (int)(SCR_SIZE_X / 2 + FONT_SIZE * 3);
static int OKRectY1 = (int)(SCR_SIZE_Y * 0.7), OKRectY2 = (int)(SCR_SIZE_Y * 0.7 + FONT_SIZE * 2);
static int OKTextX = (int)(SCR_SIZE_X / 2 - FONT_SIZE * 0.5);
static int OKTextY = (int)(SCR_SIZE_Y * 0.7 + FONT_SIZE * 0.5);

//textBox
static int TextBoxCurSorX = (int)(SCR_SIZE_X / 2 - FONT_SIZE * 8.5);
static int TextBoxCurSorY1 = (int)(SCR_SIZE_Y * 0.4 + FONT_SIZE * 0.3), TextBoxCurSorY2 = (int)(SCR_SIZE_Y * 0.4 + FONT_SIZE * 1.7);
static int textBoxTextX = (int)(SCR_SIZE_X / 2 - FONT_SIZE * 7.5);
static int textBoxTextY = (int)(SCR_SIZE_Y * 0.4 + FONT_SIZE * 0.5);

//check & used(dialog)
static int dialogX1 = (int)(SCR_SIZE_X / 2 - FONT_SIZE*15), dialogX2 = (int)(SCR_SIZE_X / 2 + FONT_SIZE * 15);
static int dialogY1 = (int)(SCR_SIZE_Y * 0.3), dialogY2 = (int)(SCR_SIZE_Y * 0.7);
static int checkTextX = (int)(SCR_SIZE_X / 2 - FONT_SIZE * 12), checkTextY = (int)(SCR_SIZE_Y * 0.4 + FONT_SIZE);
static int checkOKX1 = (int)(SCR_SIZE_X / 2 - FONT_SIZE * 5), checkOKX2 = (int)(SCR_SIZE_X / 2 - FONT_SIZE * 2);
static int checkOKY1 = (int)(SCR_SIZE_Y * 0.5), checkOKY2 = (int)(SCR_SIZE_Y * 0.5 + FONT_SIZE * 2);
static int checkOKTextX = (int)(SCR_SIZE_X / 2 - FONT_SIZE * 4.5), checkOKTextY = (int)(SCR_SIZE_Y * 0.5 + FONT_SIZE * 0.5);
static int checkNGX1 = (int)(SCR_SIZE_X / 2 + FONT_SIZE * 2), checkNGX2 = (int)(SCR_SIZE_X / 2 + FONT_SIZE * 5);
static int checkNGY1 = (int)(SCR_SIZE_Y * 0.5), checkNGY2 = (int)(SCR_SIZE_Y * 0.5 + FONT_SIZE * 2);
static int checkNGTextX = (int)(SCR_SIZE_X / 2 + FONT_SIZE * 2.5), checkNGTextY = (int)(SCR_SIZE_Y * 0.5 + FONT_SIZE * 0.5);
static int usedOKX1 = (int)(SCR_SIZE_X / 2 - FONT_SIZE * 3), usedOKX2 = (int)(SCR_SIZE_X / 2 + FONT_SIZE * 3);
static int usedOKY1 = (int)(SCR_SIZE_Y * 0.5), usedOKY2 = (int)(SCR_SIZE_Y * 0.5 + FONT_SIZE * 2);
static int usedOKTextX = (int)(SCR_SIZE_X / 2 - FONT_SIZE * 0.5), usedOKTextY = (int)(SCR_SIZE_Y * 0.5 + FONT_SIZE * 0.5);

//�P�̃e�X�g�p�v���O����
/*
int test_Initialize(InputNickName_t *innt) {
	int color;

	color = GetColor(255,255,255);
	SetFontSize((int)(FONT_SIZE * 1.5));
	DrawFormatString(textX, textY,color, "�j�b�N�l�[������͂��Ă�������");
	SetFontSize(FONT_SIZE);
	DrawBox(textBoxX1, textBoxY1, textBoxX2, textBoxY2, color, FALSE);
	DrawFormatString(limitX, limitY, color, "%d/%d", innt->nickName.size(), NAME_MAX);
	DrawBox(OKRectX1, OKRectY1, OKRectX2, OKRectY2, color, FALSE);
	DrawFormatString(OKTextX, OKTextY, color, "OK");

	return 0;
}

int test_Update(InputNickName_t *innt, Mouse_t *mouse) {
	
	int originalName = 0, c = -1;
	int color = GetColor(255, 255, 255);
	int dialogColor = GetColor(0,0,0);
	test_Initialize(innt);
	GetMouseState(mouse);

	//DrawFormatString(0, 0, color, "phase:%d.", innt->phase);
	
	//phase�̕���
	if (mouse->mButton == left) {
		if (innt->phase == check && click(mouse, checkOKX1, checkOKY1, checkOKX2, checkOKY2)) {
			innt->phase = standard;
			return 1;//Escene menu
		}
		else if (innt->phase == check && click(mouse, checkNGX1, checkNGY1, checkNGX2, checkNGY2)) innt->phase = standard;
		else if (innt->phase == used && click(mouse, usedOKX1, usedOKX2, usedOKY1, usedOKY2)) innt->phase = standard;
		else if (click(mouse, textBoxX1, textBoxY1, textBoxX2, textBoxY2)) innt->phase = textBox;
		else if (click(mouse, OKRectX1, OKRectY1, OKRectX2, OKRectY2)) {
			originalName = checkNickName(innt->nickName);
			innt->phase = check;
		}
		else innt->phase = standard;
	}

	switch (innt->phase) {
	case standard:
		DrawFormatString(textBoxTextX, textBoxTextY, color, "%s", innt->nickName.c_str());
		break;
	case textBox:
		//draw text cursor(check mouse point)
		c = CheckHitKey();
		if (c != -1 && (int)c == 8) {
			innt->nickName = innt->nickName.erase((innt->nickName.size() == 0)? 0 : innt->nickName.size() - 1);
		}
		else if (c != -1 && innt->nickName.size() < NAME_MAX) {
			innt->nickName.push_back((char)c);
		}
		DrawFormatString(textBoxTextX, textBoxTextY, color, "%s", innt->nickName.c_str());
		Sleep(70);
		break;
	case check:
		DrawBox(dialogX1, dialogY1, dialogX2, dialogY2, dialogColor, TRUE);
		DrawBox(dialogX1, dialogY1, dialogX2, dialogY2, color, FALSE);
		DrawFormatString(checkTextX, checkTextY, color, "your nick name is\"%s\" right?", innt->nickName.c_str());
		DrawBox(checkOKX1, checkOKY1, checkOKX2, checkOKY2, color, FALSE);
		DrawFormatString(checkOKTextX, checkOKTextY, color, "OK");
		DrawBox(checkNGX1, checkNGY1, checkNGX2, checkNGY2, color, FALSE);
		DrawFormatString(checkNGTextX, checkNGTextY, color, "cancel");
		break;
	case used:
		break;
	}

	return 0;
}
void test_Finalize(InputNickName_t *innt) {

}*/
//�P�̃e�X�g�p�v���O�����@�����܂�




/******************************
*** Function Name	: InitializeInputNickName
*** Designer		: ����
*** Date			: 2020.6.23
*** Function		:�j�b�N�l�[�����͉�ʂ�\������
*** Return			: Escene	--�J�ڐ�̉�ʂ��w��
******************************/
int InitializeInputNickName (InputNickName_t *innt){
	int color;

	color = GetColor(255, 255, 255);
	SetFontSize((int)(FONT_SIZE * 1.5));
	DrawFormatString(textX, textY, color, "�j�b�N�l�[������͂��Ă�������");
	SetFontSize(FONT_SIZE);
	DrawBox(textBoxX1, textBoxY1, textBoxX2, textBoxY2, color, FALSE);
	DrawFormatString(limitX, limitY, color, "%d/%d", innt->nickName.size(), NAME_MAX);
	DrawBox(OKRectX1, OKRectY1, OKRectX2, OKRectY2, color, FALSE);
	DrawFormatString(OKTextX, OKTextY, color, "OK");

	return 0;//InputNickName
}

/******************************
*** Function Name	: UpdateInputNickName
*** Designer		: ����
*** Date			: 2020.6.23
*** Function		:�}�E�X���͂�L�[�{�[�h���͂��󂯎��A����ɏ]���ĕ\����ύX����
*** Return			: Escene	--�J�ڐ�̉�ʂ��w��
******************************/
int UpdateInputNickName(InputNickName_t *innt, Mouse_t *mouse) {
	int originalName = 0, c = -1;
	int color = GetColor(255, 255, 255);
	int dialogColor = GetColor(0, 0, 0);
	InitializeInputNickName(innt);
	GetMouseState(mouse);

	//DrawFormatString(0, 0, color, "phase:%d.", innt->phase);

	//phase�̕���
	if (mouse->mButton == left) {
		if (innt->phase == check && click(mouse, checkOKX1, checkOKY1, checkOKX2, checkOKY2)) {
			innt->phase = standard;
			return 1;//MenuScr
		}
		else if (innt->phase == check && click(mouse, checkNGX1, checkNGY1, checkNGX2, checkNGY2)) innt->phase = standard;
		else if (innt->phase == used && click(mouse, usedOKX1, usedOKX2, usedOKY1, usedOKY2)) innt->phase = standard;
		else if (click(mouse, textBoxX1, textBoxY1, textBoxX2, textBoxY2)) innt->phase = textBox;
		else if (click(mouse, OKRectX1, OKRectY1, OKRectX2, OKRectY2)) {
			originalName = checkNickName(innt->nickName);
			innt->phase = check;
		}
		else innt->phase = standard;
	}

	switch (innt->phase) {
	case standard:
		DrawFormatString(textBoxTextX, textBoxTextY, color, "%s", innt->nickName.c_str());
		break;
	case textBox:
		//draw text cursor(check mouse point)
		c = CheckHitKey();
		if (c != -1 && (int)c == 8) {
			innt->nickName = innt->nickName.erase((innt->nickName.size() == 0) ? 0 : innt->nickName.size() - 1);
		}
		else if (c != -1 && innt->nickName.size() < NAME_MAX) {
			innt->nickName.push_back((char)c);
		}
		DrawFormatString(textBoxTextX, textBoxTextY, color, "%s", innt->nickName.c_str());
		Sleep(70);
		break;
	case check:
		DrawBox(dialogX1, dialogY1, dialogX2, dialogY2, dialogColor, TRUE);
		DrawBox(dialogX1, dialogY1, dialogX2, dialogY2, color, FALSE);
		DrawFormatString(checkTextX, checkTextY, color, "your nick name is\"%s\" right?", innt->nickName.c_str());
		DrawBox(checkOKX1, checkOKY1, checkOKX2, checkOKY2, color, FALSE);
		DrawFormatString(checkOKTextX, checkOKTextY, color, "OK");
		DrawBox(checkNGX1, checkNGY1, checkNGX2, checkNGY2, color, FALSE);
		DrawFormatString(checkNGTextX, checkNGTextY, color, "cancel");
		break;
	case used:
		break;
	}

	return 0;//InputNickName
}

/******************************
*** Function Name	: FinalizeInputNickName
*** Designer		: ����
*** Date			: 2020.6.23
*** Function		:�g�p�����摜�̃n���h�����J������B�����_�ł͎g�p���Ă��Ȃ�
*** Return			: void		--�߂�l�Ȃ�
******************************/
void FinalizeInputNickName(InputNickName_t *innt) {}

/******************************
*** Function Name	: checkNickName
*** Designer		: ����
*** Date			: 2020.6.23
*** Function		:UpdateInputNickName�œ��͂��ꂽ�j�b�N�l�[���Ɠ����j�b�N�l�[�����f�[�^�x�[�X�ɂ��邩�`�F�b�N����
*** Return			: 0		--�j�b�N�l�[�����f�[�^�x�[�X�ɑ��݂��Ă���
					  1		--�j�b�N�l�[�����f�[�^�x�[�X�ɑ��݂��Ȃ�(�I���W�i���̃j�b�N�l�[���ł���)
******************************/
int checkNickName(std::string name) {
	//�C���^�[�l�b�g�ʐM�����āA�I���W�i���̖��O���`�F�b�N
	return 1;
}

/******************************
*** Function Name	: click
*** Designer		: ����
*** Date			: 2020.6.23
*** Function		:�}�E�X�̍��W�ƃ{�^���̍��W����}�E�X���{�^���̏�ɂ��邩�`�F�b�N����
*** Return			: 0		--�}�E�X���{�^����ɂȂ�
					  1		--�}�E�X���{�^����ɂ���
******************************/
int click(Mouse_t *mouse, int x1, int y1, int x2, int y2) {
	if (mouse->mX > x1 && mouse->mX < x2 && mouse->mY > y1 && mouse->mY < y2) {
		return 1;
	}
	return 0;
}
