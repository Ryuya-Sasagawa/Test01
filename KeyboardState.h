#ifndef KEYBOARD_STATE_H_
#define KEYBOARD_STATE_H_

// M5:�L�[�{�[�h��Ԃ̎擾
void GetKeyBoardState(int* key) {
	char tmpKey[256];			// ���݂̃L�[�̓��͏�Ԃ��i�[����ϐ�
	GetHitKeyStateAll(tmpKey);	// ���ׂẴL�[�̓��͏�Ԃ𓾂�

	for (int i = 0; i < 256; i++) {
		if (tmpKey[i] != 0) {	// i�Ԗڂ̃L�[�ɑΉ�����L�[��������Ă��
			key[i]++;			// �L�[�{�[�h��Ԋi�[�ϐ���i�Ԗڂ����Z
		}
		else {					// ������Ă��Ȃ����
			key[i] = 0;			// �L�[�{�[�h��Ԋi�[�ϐ���i�Ԗڂ�0�ɂ���
		}
	}
}

#endif /* KEYBOARD_STATE_H_ */
