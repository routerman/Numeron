#include "Game.hpp"

void Game::Proc(){
	do{
		//������
		int que, rep, try_count;

		//���v���C���[�̓��������߂�
		player[0]->Init();
		player[1]->Init();

		//�Q�[���J�n
		while (!end){
			//sleep(1);
			cout << endl << "<<--- " << player[turn]->getName() << "'s turn!! (" << this->count << ") --->>" << endl;
			//3�񑱂��Ė����Ȏ���𑗐M�����畉��
			try_count = 0;
			do{
				if (++try_count == 3){
					end = true;
					break;
				}
				que = player[turn]->SendQuery();
			} while (isValidNumber(que) == false);
			if (end) continue;

			//�L���Ȏ���ɑ΂��A�Ԏ�������B
			rep = player[!turn]->SendReply(que);
			//sleep(1);

			//3-0�̏ꍇ�͏I������
			if (rep == 30){
				end = true;
			}else{
				//���ʂ��󂯎��A��������
				player[turn]->ResvQuery(que, rep);
				if (turn == true) count++;
				turn = !turn;	//���
			}
		}
		//�������킹
		cout << "winner:" << player[turn]->getName() << endl;
		player[turn]->ShowMyNumber();

		string command;
		cout << "revenge?(y/n):";
		cin >> command;
		if (command[0] != 'y')break;
		this->end = false;	//������
		this->count = 1;
	} while (true);
}

//
Game::Game(int mode){
	turn = false;
	//"this"�͂��̃N���X�̕ϐ��ł��邱�Ƃ𖾎��I�Ɏ����B
	this->end = false;
	this->count = 1;
	switch (mode)
	{
	case 1:
		player[0] = new Human(false);
		player[1] = new Human(true);
		break;
	case 2:
		player[0] = new Human(false);
		player[1] = new Machine(true);
		break;
	case 3:
		player[0] = new Machine(false);
		player[1] = new Human(true);
		break;
	case 4:
		player[0] = new Machine(false);
		player[1] = new Machine(true);
		break;
	default:
		break;
	}
}

Game::~Game(){
	delete player[0];
	delete player[1];
}