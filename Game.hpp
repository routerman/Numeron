#include "Include.hpp"
#include "Player.hpp"
#include "Human.hpp"
#include "Machine.hpp"

class Game{
private:
	//int mode;
	int count; 
	bool turn; //���A��U����U��
	Player *player[2];	//Player�N���X���p�������N���X�̃C���X�^���X�ւ̃|�C���^
	bool end; //�Q�[�����I��������
public:
	void Proc();
	Game(int mode);
	~Game();
};
