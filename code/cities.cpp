#include "header.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <thread>

using namespace std;

city cities[8];

void build_city() {
	cities[0].set_city("�K���p��", "�q�t����", 5, 3);
	cities[0].add_spots(1, "�K���p����");
	cities[0].add_spots(1, "�W���");
	cities[0].add_spots(1, "���Զ�ճդh��s��");
	cities[0].add_spots(3, "�����s��");
	cities[0].add_spots(4, "�_�i�ڤ���");

	cities[1].set_city("���ȥ�", "�Ψt����", 5, 11);
	cities[1].add_spots(1, "�|���D���˪L");//���A�p�b��
	cities[1].add_spots(1, "���ȹD�]");
	cities[1].add_spots(2, "�j��˪L", "�A�P�A���_�i�ڦb�˪L�̹J���F�������ȴ�", 40);
	cities[1].add_spots(3, "�r�����J�����Q�u");
	cities[1].add_spots(4, "�_�i�ڤ���");

	cities[2].set_city("������", "���ۨt����", 5, 12);
	cities[2].add_spots(1, "�����D�]");
	cities[2].add_spots(1, "�Q�@���D���˪L");//���A�L���N�H
	cities[2].add_spots(2, "�����s", "�A�P�A���_�i�ڦb�s���W�@�_�ݤF�����", 20);
	cities[2].add_spots(3, "�����r��");
	cities[2].add_spots(4, "�_�i�ڤ���");

	cities[3].set_city("�Pù��", "�氫�t����", 6, 6);
	cities[3].add_spots(1, "�Ť����H�V�m����");//�p�b���i��
	cities[3].add_spots(1, "��Ҥ���");
	cities[3].add_spots(1, "�Q�G���D���˪L");//�K�K�w��i��
	cities[3].add_spots(1, "�Q�G���D����`");//���A�H�H�_
	cities[3].add_spots(3, "�q���p��");
	cities[3].add_spots(4, "�_�i�ڤ���");

	cities[4].set_city("���l��", "��t����", 5, 4);
	cities[4].add_spots(1, "���l�D�]");
	cities[4].add_spots(1, "�Q�G���D�����");//�H�H�_�i��
	cities[4].add_spots(1, "�Q�T���D���˪L");//�H����i��
	cities[4].add_spots(2, "�s���a�V", "�A�P�A���_�i�ڦb�a�V�䪺���W�ݨ���l���ۦW���Ų��\", 20);
	cities[4].add_spots(4, "�_�i�ڤ���");

	cities[5].set_city("���ȥ�", "����t����", 6, 17);
	cities[5].add_spots(1, "���ȹD�]");
	cities[5].add_spots(1, "���q���A�˩�");//���ӹ��1
	cities[5].add_spots(1, "�Q�����D���˪L");//����佻
	cities[5].add_spots(2, "�j�Ѫ��j��", "�A�P�A���_�i�ڤ@�_�Y��F�ʦ~���o���y�P�B", 30);
	cities[5].add_spots(3, "�Ѥ���");
	cities[5].add_spots(4, "�_�i�ڤ���");

	cities[6].set_city("�ʨ襫", "�W��O�t����", 6, 10);
	cities[6].add_spots(1, "���h���s");//���b���i��
	cities[6].add_spots(1, "�ʨ�D�]");
	cities[6].add_spots(1, "�Ԫ̧�");//�K�Y��i��
	cities[6].add_spots(1, "�Q�K���D���˪L");//���ӹ��2�A��Ԧ�P1�A�佻�i��
	cities[6].add_spots(2, "�y���S���", "�A�P�A���_�i�ڦb�S��ϻ{�ѤF�\�h�V�m�a�P�_�i�ڡA�ûP�L�̦����B��", 20);
	cities[6].add_spots(4, "�_�i�ڤ���");

	cities[7].set_city("�M����", "�B�t����", 5, 5);
	cities[7].add_spots(1, "�M���D�]");
	cities[7].add_spots(1, "�o��p���");//��Ԧ�P2�A���ӹ��3
	cities[7].add_spots(1, "�˪L�n���s�}");
	cities[7].add_spots(3, "�˪L�_���B�e");
	cities[7].add_spots(4, "�_�i�ڤ���");
}

string spot::get_name() {
	return name;
}
int spot::get_catogory() {
	return catogory;
}
void spot::set_name(string name_) {
	name = name_;
}
void spot::set_catogory(int catogory_) {
	catogory = catogory_;
}

main_spot::main_spot(string name, int catogory_) {
	set_name(name); set_catogory(catogory_);
}
void main_spot::things_to_do() {
	main_menu();
}

camp::camp(string name, string event_, int my_pokemon_experience_, int catogory_) {
	set_name(name); event = event_; my_pokemon_experience = my_pokemon_experience_; set_catogory(catogory_);
}
camp::camp(string name, int catogory_) {
	set_name(name); my_pokemon_experience = 0; set_catogory(catogory_);
}
void camp::things_to_do() {
	int choose_to_camp;
	cout << "[�o�O�@�ӾA�X���窺�a��C]\n";
	if (my_tent.get_numbers() == 0) {
		cout << "[�A�ثe�L�k����C���ʶR�b�O]\n";
	}
	else {
		cout << "�O�_�n�b���B����H\n�п�J�A����ܡG(1�G�O�A2�G�_)";
		cin >> choose_to_camp;
		if (choose_to_camp == 1) {
			cout << "�Цb���B��20��";
			this_thread::sleep_for(chrono::seconds(20));
			player.fill_tiredness();
			player.set_hungry(-3);
			int i = 0;
			cout << endl;
			if (my_pokemon_experience != 0) {
				cout << "[" << event << "�A�_�i�ڸg��ȤW��" << my_pokemon_experience << "]";
				cin.ignore();
			}
			while (player.get_my_pokemon(i) != NULL) {
				if (player.get_my_pokemon(i)->get_catch() == true) {
					player.get_my_pokemon(i)->set_hungry(-3);
					player.get_my_pokemon(i)->add_experience(my_pokemon_experience);
					i++;
				}
				else{
					break;
				}
			}
			my_cout("�A�P�A���_�i�ڲ{�b���믫�����I���~��ȵ{");
		}
	}
	main_menu();
}

water_land::water_land(string name, int catogory_) {
	set_name(name); set_catogory(catogory_);
}
void water_land::things_to_do() {
	int choose_to_fillwater;
	cout << "[�o�̦��n�h�u���C�A�i�H��I�]�̪����ɺ�]\n�O�_�n�b���B�ɤ��H\n�п�J�A�����(1�G�O�A2�G�_)�G";
	cin >> choose_to_fillwater;
	if (choose_to_fillwater == 1) {
		bottle.fill_water();
		my_cout("���w�g�ɺ��F");
	}
	cout << endl;
	main_menu();
}

pokemon_center::pokemon_center(string name, int catogory_) {
	set_name(name); set_catogory(catogory_);
}
void pokemon_center::things_to_do() {
	int choose_service;
	cout << "\n[���p�j]�G�w��Ө� " << current_city->get_name() << " ���_�i�ڤ��ߡC�аݻݭn�����U�O�H\n";
	if (current_mission == &missions[0][4]) {
		cout << "\n    [HINT]\n    �C�ӫ��������_�i�ڤ��ߡA���ѰV�m�a�𮧡B�ʶR���~�B�v���_�i�ڵ��A�ȡC\n    �A����O�Ȥw�k�s�A�Х���� 1.��J�@��\n\n";
	}
	cout << "1.��J�@�ߡ]�ֹ�150���^\n2.��_�_�i��HP�]�ֹ�200���^\n3.�ʶR���~\n4.�^��D���\n�п�J�A����ܡG";
	cin >> choose_service;
	if (choose_service == 1) {
		player.set_money(-150);
		cout << "\n[���p�j]�G�Цb���B��20��";
		this_thread::sleep_for(chrono::seconds(20));
		player.fill_tiredness();
		player.set_hungry(-3);
		int i = 0;
		while (player.get_my_pokemon(i) != NULL) {
			if (player.get_my_pokemon(i)->get_catch() == true) {
				player.get_my_pokemon(i)->set_hungry(-3);
				i++;
			}
			else {
				break;
			}
		}
		cin.ignore();
		my_cout("\n[���p�j]�G�A�P�A���_�i�ڲ{�b���믫�����I���~��ȵ{");
		if (current_mission == &missions[0][4]) {
			my_cout("\n    [HINT]\n    �C���ɥR��O�A���a�P�_�i�ڪ����j�׳��|�U���C�p�����n�аO�o�t�~�h�ɥR���j�סC\n    �t�~�A���F�_�i�ڤ��ߥi�H�ɥR�ƫ~�B���Ѧ�B�A�U�ӫ����]���a��i�H�K�O�ɥR�����γ���C\n    ���a�@���A���M����ݭn�۳Ʊb�O�]�i�b�_�i�ڤ����ʶR�^�A���]�i��J��@�ǰ��o�ƥ�B�i�����_�i�ڪ��g��ȳ�I�յۥh�����ݬݧa");
			current_mission = &missions[1][0];
		}
		pokemon_center::things_to_do();
	}
	else if (choose_service == 2) {
		player.set_money(-200);
		my_pokemon* now_point = player.get_my_pokemon(0);
		while (now_point != NULL) {
			now_point->set_HP(now_point->get_max_HP());
			now_point = now_point->get_next_ptr();
		}
		cin.ignore();
		my_cout("\n[���p�j]�G�A���_�i�ڳ���_���d�F�I���~��ȵ{");
		pokemon_center::things_to_do();
	}
	else if (choose_service == 3) {
		int choose_item = 0, number;
		cout << "\n�ө��c�檫�~�p�U�G\n";
		cout << "       �~���W��                      �ӫ~����    �����ƶq    ����\n";
		for (int i = 0; i < 12; i++) {
			cout << setw(2) << i + 1 << "." << setw(12) << player.get_consumable(i)->get_name() << setw(30) << player.get_consumable(i)->get_direction() << setw(12) << player.get_consumable(i)->get_numbers() << setw(8) << player.get_consumable(i)->get_price() << endl;
		}
		cout << "13.    ���}�ө�\n";
		while (choose_item != 13) {
			cout << "\n�A�֦����ֹ��G" << player.get_money() << endl;
			cout << "�п�J�A�n�ʶR�����~�G";
			cin >> choose_item;
			if (choose_item == 13) {
				break;
			}
			cout << "�п�J�ʶR�ƶq�G";
			cin >> number;
			player.get_consumable(choose_item - 1)->add_num(number);
			player.set_money(-player.get_consumable(choose_item - 1)->get_price() * number);
			cout << "�A�w��o " << player.get_consumable(choose_item - 1)->get_name() << " " << player.get_consumable(choose_item - 1)->get_numbers() << " ��\n";
			cout << "�O�_�~���ʪ��H(�O:1�A�_:2)"; cin >> choose_item;
			if (choose_item == 2) {
				break;
			}
		}
		pokemon_center::things_to_do();
	}
	else {
		main_menu();
	}
}

void city::set_city(string t_name, string t_describe, int num, int attribute_) {
	name = t_name, describe = t_describe, spot_num = num; attribute = attribute_;
}
void city::add_spots(int catogory, string name_) {
	//1:main�A2:camp�A3:water�A4:center
	if (catogory == 1) {
		spots.push_back(new main_spot(name_, catogory));
	}
	else if (catogory == 2) {
		spots.push_back(new camp(name_, catogory));
	}
	else if (catogory == 3) {
		spots.push_back(new water_land(name_, catogory));
	}
	else if (catogory == 4) {
		spots.push_back(new pokemon_center(name_, catogory));
	}
}
void city::add_spots(int catogory, string name_, string event_, int my_pokemon_experience_) {
	if (catogory == 2) {
		spots.push_back(new camp(name_, event_, my_pokemon_experience_, catogory));
	}
}
string city::get_name() {
	return name;
}
string city::get_describe() {
	return describe;
}
spot* city::get_spot(int index) {
	return spots[index];
}
int city::get_spot_num() {
	return spot_num;
}
int city::get_attribute() {
	return attribute;
}