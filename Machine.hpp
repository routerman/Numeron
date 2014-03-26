#include "Include.hpp"
#include "Player.hpp"


//�l�ԃN���X
class Machine : public Player{
private:
	list<int> numbers_list;	//"vector list �Ⴂ"�Ō���

public:
	/* Player�N���X����I�[�o�[���C�h����֐� */
	void SelectMyNumber();
	int SendQuery();
	void ResvQuery(int query, int reply);
	void Init();
	
	//�V���ɒǉ�����֐�
	void noway(int query, int reply);
	int isEffective(int query);
	int vnoway(int query, int reply);

	//�R���X�g���N�^
	Machine(bool turn) : Player(turn){
		this->name = "Machine";
		if (turn){ this->name += "2"; }
		else{ this->name += "1"; }
		for (int i = 0; i < 1000; i++){
			if (isValidNumber(i) == true){
				numbers_list.push_back(i);
			}
		}

	}
};
