#include "Machine.hpp"

//�����𐶐����Ď����̐��������肷��
void Machine::SelectMyNumber(){
	int ans;
	srand((unsigned)time(NULL));
	ans = rand() % 1000;
	while (isValidNumber(ans) == false){
		//cout<<"Invalid!"<<endl;
		ans = ans*ans + ans + ans / 2;
		ans = ans % 1000;
	}
	this->number = ans;

	cout << this->name << " >> My number is ..???" << endl;
	//cout << this->number << endl;
}

//���₷�鐔����I��
int Machine::SendQuery(){
	//��␔���̕\��
	//for (list<int>::iterator it = numbers_list.begin(); it != numbers_list.end(); it++){
	//cout << *it << ",";
	//}
	//�N�G�������̕\��
	ShowQueryHistory();
	//�Ƃ肠�����A��␔�̍ŏ�
	list<int>::iterator it = numbers_list.begin();
	cout << name << " >> nokori..." << numbers_list.size() << " numbers, I guess your number is .." << *it << endl;
	return *it;

}

//���ʂ��󂯂Ƃ�����폜����
void Machine::ResvQuery(int query, int reply){
	query_reply_map.insert( map<int, int>::value_type(query, reply) );
	//numbers_list.remove_if(noway(query,reply/10,reply%10));
	noway(query, reply);
}

//�}�C�i���o�[���␔���X�g������������
void Machine::Init(){
	number = 0;
	query_reply_map.clear();
	numbers_list.clear();
	for (int i = 0; i < 1000; i++){
		if (isValidNumber(i) == true){
			numbers_list.push_back(i);
		}
	}
	//�����̐�����I��
	SelectMyNumber();
}

//
void Machine::noway(int query, int reply){
	int m;
	numbers_list.remove(query);
	//xeat�łȂ���΍폜
	for (list<int>::iterator it = numbers_list.begin(); it != numbers_list.end();){
		m = 0;
		if ((query / 100 == *it / 100))m++;
		if ((query / 10 % 10 == *it / 10 % 10))m++;
		if ((query % 10 == *it % 10))m++;
		if (m != reply / 10){
			//cout << *it <<",";
			if (it != numbers_list.end())it = numbers_list.erase(it);
			else numbers_list.erase(it);
		}
		else{
			if (it != numbers_list.end())it++;
		}
	}
	//xbite�ȊO�͍폜
	for (list<int>::iterator it = numbers_list.begin(); it != numbers_list.end();){
		m = 0;
		if ((query / 100 == *it / 10 % 10) || (query / 100 == *it % 10))m++;
		if ((query / 10 % 10 == *it / 100) || (query / 10 % 10 == *it % 10))m++;
		if ((query % 10 == *it / 100) || (query % 10 == *it / 10 % 10))m++;
		if (m != reply % 10){
			//cout << *it << ",";
			if (it != numbers_list.end())it = numbers_list.erase(it);
			else numbers_list.erase(it);
		}
		else{
			if (it != numbers_list.end())it++;
		}
	}
}
