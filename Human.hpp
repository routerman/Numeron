#include "Include.hpp"
#include "Player.hpp"

/*
Human�N���X
player�N���X���p������
*/
class Human : public Player{
private:

public:
	/* Player�N���X����I�[�o�[���C�h����֐� */
	void ResvQuery(int query, int reply);
	void Init();
	void SelectMyNumber();
	int SendQuery();

	//�R���X�g���N�^
	Human(bool turn) : Player(turn){
		cout << "What's your name?:";
		cin >> this->name;
	}
};