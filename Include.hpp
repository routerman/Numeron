#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <map>

#include <cstdlib>
#include <ctime>
#include <functional>

#ifdef __linux__
   //sleep()
   #include <unistd.h>
#endif

using namespace std;

#define DEBUG

/*
typedef struct{
	int eat;
	int bite;
}Reply;

typedef struct{
	int a,b,c;
}Number;
*/

//�O���[�o���֐���extern�őO�錾����B
//��{�I�Ƀw�b�_�t�@�C���ł͊֐���ϐ��̖{�̂�錾���Ȃ�
//�����̃\�[�X�t�@�C������Ă΂��w�b�_�t�@�C���͓��ɁB
extern bool isValidNumber(int query);
extern int getRandomNumber(int min,int max);
