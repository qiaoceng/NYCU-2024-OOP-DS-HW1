#include "header.h"
#include <iostream>
#include <cstdlib>
#include <random>
#include <chrono>
#include <iomanip>

using namespace std;

my_pokemon* choose_one_pokemon = NULL;
int availible_choose_pokemon_num = 0;//�i�H�諸�_�i�ڼ�
int availible_pokemon_num = 0;//�ٯ�԰����_�i�ڼ�

bool whole_battle(int my_num, int NPC_num, trainer* NPC, pokemon* opponents[]) {
	availible_choose_pokemon_num = my_num;
	availible_pokemon_num = my_num;
	my_pokemon* choose_my_pokemons[6] = { NULL };
	for (int i = 0; i < NPC_num; i++) {
		if (NPC != NULL) {
			cout << "\n[" << NPC->get_name() << " ���X�F " << opponents[i]->get_name() << "(";
			opponents[i]->print_attribute();
			cout << ")]";
			cin.ignore();
			cout << "\n";
		}
		else {
			cout << "\n[" << opponents[i]->get_name() << "(";
			opponents[i]->print_attribute();
			cout << ")]";
			cin.ignore();
			cout << "\n";
		}
		while (opponents[i]->get_HP() > 0) {
			if (choose_one_pokemon == NULL) {
				//����_�i��
				int choose_num = 0;
				cout << "�п�ܧA�n���X���_�i�ڡG\n";
				//�ٯ��s��
				if (availible_choose_pokemon_num > 0) {
					player.print_my_pokemon_value(opponents[i]);
					if (current_mission == &missions[0][1]) {
						cout << "\n  [HINT]\n  �H�W���A�ثe�������_�i�ڡC\n";
						cout << "  �_�i�ڦW�r�᭱�����ݩʡC�ݩʬ۫g�|�v�T�����P���m�A�Y�_�i�ڪ��ݩʦ��Q���ԡA�h�|�����u���ˡv�r�ˡA�Ϥ���M�C\n";
						cout << "  �Y�O�ݩʨS���S�O���Q�Τ��Q�h���|��ܡC\n";
						cout << "  �W�r�U������_�i�ڪ�HP�H�ΰ��j�׻P�f���סC�O��A���j�׻P�f���׭Y<=3�N�L�k��ԡC\n";
						cout << "  ���U�ӴX����ܪ��O�_�i�ڪ��ۦ��P���ݩʡC�j�ۻݭn����A�����O�V���ݭn������q�N�V���C�p�ۭt�d���j�۶���A�P�ˡA�����O�V���ֿn������q�N�V���C\n";
						cout << "  ����ܽs��1 �֥d�C �a\n";
					}
					while (choose_num == 0) {
						cout << "\n�п�J�A����ܡG"; cin >> choose_num;
						if (player.get_my_pokemon(choose_num - 1)->get_catch() == false || player.get_my_pokemon(choose_num - 1)->get_HP() <= 0 || player.get_my_pokemon(choose_num - 1)->get_hungry() <= 3 || player.get_my_pokemon(choose_num - 1)->get_thirsty() <= 3) {
							cout << "��J�L�ġA�Э��s���\n";
							choose_num = 0;
						}
					}
					for (int j = my_num; j >= availible_choose_pokemon_num; j--) {
						if (choose_my_pokemons[j] == player.get_my_pokemon(choose_num - 1)) {
							choose_one_pokemon = player.get_my_pokemon(choose_num - 1);
						}
						if (j == availible_choose_pokemon_num) {
							availible_choose_pokemon_num--;
							choose_my_pokemons[availible_choose_pokemon_num] = player.get_my_pokemon(choose_num - 1);
							choose_one_pokemon = player.get_my_pokemon(choose_num - 1);
							break;
						}
					}
				}
				//�����s��
				else {
					//�L�ﶵ
					for (int h = 0; h < my_num; h++) {
						cout << h+1 << "." << choose_my_pokemons[h]->get_name() << "(";
						choose_my_pokemons[h]->print_attribute();
						cout << ")�G";
						if (choose_my_pokemons[h]->get_HP() == 0 || choose_my_pokemons[h]->get_hungry() <= 3 || choose_my_pokemons[h]->get_thirsty() <= 3) {
							cout << "�L�k�԰�";
						}
						else {
							double confict_value_attack = 1, confict_value_defence = 1;
							for (int x = 0; x < choose_my_pokemons[h]->get_attribute_num(); x++) {
								for (int y = 0; y < choose_my_pokemons[h]->get_attribute_num(); y++) {
									confict_value_attack *= attribute_conflict_table[*choose_my_pokemons[h]->get_attribute(x)][*opponents[i]->get_attribute(y)];
									confict_value_defence *= attribute_conflict_table[*opponents[i]->get_attribute(y)][*choose_my_pokemons[h]->get_attribute(x)];
								}
							}
							if (confict_value_attack - confict_value_defence < 2) {
								cout << "������";
							}
							else if (confict_value_attack - confict_value_defence > 2) {
								cout << "����";
							}
						}
						cout << "\n  HP�G" << choose_my_pokemons[h]->get_HP() << "/" << choose_my_pokemons[h]->get_max_HP() << "  ���j�{�סG" << choose_my_pokemons[h]->get_hungry() << "/15  �f���{�סG" << choose_my_pokemons[h]->get_thirsty() << "/15\n";
						for (int o = 0; o < choose_my_pokemons[h]->get_trick_num(); o++) {
							if (choose_my_pokemons[h]->get_trick(o)->get_bigORsmall() == 0) {
								cout << "  �j�ۡG" << setw(8) << right << choose_my_pokemons[h]->get_trick(o)->get_name() << "�G" << setw(7) << left << attribute_list[choose_my_pokemons[h]->get_trick(o)->get_attribute()] << "�����O�G" << choose_my_pokemons[h]->get_trick(o)->get_attack() << endl;
							}
							else if (choose_my_pokemons[h]->get_trick(o)->get_bigORsmall() == 1) {
								cout << "  �p�ۡG" << setw(8) << right << choose_my_pokemons[h]->get_trick(o)->get_name() << "�G" << setw(7) << left << attribute_list[choose_my_pokemons[h]->get_trick(o)->get_attribute()] << "�����O�G" << choose_my_pokemons[h]->get_trick(o)->get_attack() << endl;
							}
						}
					}
					cout << "�п�J�A����ܡG";
					int choose; cin >> choose;
					choose_one_pokemon = choose_my_pokemons[choose - 1];
				}
			}
			one_battle(&player, NPC, opponents[i]);
			if (availible_pokemon_num == 0) {//��A���HP�k��
				for (int k = 0; k < NPC_num; k++) {
					opponents[k]->set_HP(opponents[k]->get_max_HP());
				}
				choose_one_pokemon = NULL;
				return false;
			}
		}
	}
	//�԰������]Ĺ�^�A�Ҧ��_�i�ڶ����k�s�A���HP�k���A�X���_�i����o�g���
	for (int k = 0; k < NPC_num; k++) {
		opponents[k]->set_current_gas(0);
		if (NPC != NULL) {
			opponents[k]->set_HP(opponents[k]->get_max_HP());
		}
	}
	for (int k = 0; k < my_num; k++) {
		if (choose_my_pokemons[k] != NULL) {
			choose_my_pokemons[k]->set_current_gas(0);
			if (choose_one_pokemon->get_mega() == true) {
				choose_one_pokemon->set_mega(false);
				my_cout("[" + choose_one_pokemon->get_name() + "�ܦ^�@�뫬�A]");
			}
		}
	}
	if (in_rocket_battle == true) {
		for (int k = my_num - 1; k >= 0; k--) {
			my_cout("\n[���b��]�G�n�Q�����Pı�ڡI�I�I�I");
			my_cout("\n[���ߧA��o�ӧQ�I]");
			my_cout("[�X���_�i����o�g���]");
			choose_my_pokemons[k]->add_experience(15);
			choose_my_pokemons[k]->set_hungry(-3);
			choose_my_pokemons[k]->set_thirsty(-3);
		}
	}
	else {
		my_cout("[�AĹ�o�԰�]");
		my_cout("[�X���_�i����o�g���]");
		for (int k = my_num - 1; k >= 0; k--) {
			if (choose_my_pokemons[k] != NULL) {
				choose_my_pokemons[k]->add_experience(20);
			}
		}
	}
	choose_one_pokemon = NULL;
	return true;
}

void one_battle(you* player_, trainer* NPC, pokemon* opponent) {
	cout << "[�A���X�F " << choose_one_pokemon->get_name() << "]";
	cin.ignore(); cout << endl;
	if (current_mission == &missions[0][1]) {
		cout << "\n  [HINT]\n  �}�l��ԧa�I�A���}�l�����C\n\n";
	}
	while (choose_one_pokemon->get_HP() > 0 || opponent->get_HP() > 0) {
		int choose_num1 = 0, choose_num2 = 0;
		double attribute_conflict = 1;
		//���a����
		choose_num1 = print_attack_in_battle(choose_one_pokemon);
		if (choose_num1 == -1) {
			choose_one_pokemon = NULL;
			break;
		}
		cout << "\n[" << choose_one_pokemon->get_name() << " �ϥX�F " << choose_one_pokemon->get_trick(choose_num1)->get_name() << "]";
		cin.ignore();
		for (int i = 0; i < opponent->get_attribute_num(); i++) {
			attribute_conflict *= attribute_conflict_table[choose_one_pokemon->get_trick(choose_num1)->get_attribute()][*opponent->get_attribute(i)];
			if (player.get_now_badge_attribute() < 18) {
				if (player.get_now_badge_attribute() == *opponent->get_attribute(i)) {
					attribute_conflict *= 1.2;
				}
			}
		}
		if (choose_one_pokemon->get_trick(choose_num1)->get_bigORsmall() == 0) {
			choose_one_pokemon->do_big_trick(choose_one_pokemon->get_trick(choose_num1)->get_attack() * attribute_conflict);
		}
		else if (choose_one_pokemon->get_trick(choose_num1)->get_bigORsmall() == 1) {
			choose_one_pokemon->do_small_trick(choose_one_pokemon->get_trick(choose_num1)->get_attack() * attribute_conflict);
		}
		double damage = choose_one_pokemon->get_trick(choose_num1)->get_attack() * attribute_conflict;
		opponent->receive_trick(damage);
		cout << "\n[" << opponent->get_name() << "��HP���" << damage << "]\n";
		attribute_conflict = 1;
		//�D�u3-6���S�����
		if (current_mission == &missions[5][2] && choose_one_pokemon == &Frogadier && opponent->get_HP() <= 50) {
			availible_pokemon_num--;
			break;
		}
		//��⥢�h�԰���O�H
		if (opponent->get_HP() <= 0) {
			cout << "[" << opponent->get_name() << " �L�k�i����]\n";
			opponent->set_current_gas(0);
			if (opponent->get_mega() == true) {
				opponent->set_mega(false);
				cout << "[" << opponent->get_name() << "�ܦ^�@�뫬�A]\n";
			}
			break;
		}
		else {
			cout << "[" << opponent->get_name() << "�{�b��HP�G" << opponent->get_HP() << "]";
			cin.ignore();
			cout << endl;
		}
		//���mega�i�ơH
		if (opponent->get_mega_ability() == true && opponent->get_mega() == false) {
			if (opponent->get_HP() <= opponent->get_max_HP() * 0.5) {
				opponent->set_mega(true);
				cout << "[" << NPC->get_name() << "]�G" << opponent->get_name() << "�Amega�i�Ƨa�I";
				my_cout("[" + opponent->get_name() + "mega�i�ƤF]");
			}
		}
		
		//NPC����
		//�G�M��
		if (opponent == &Wobbuffet) {
			//�G�M�Τj��
			if (opponent->get_gas() >= opponent->get_trick(1)->get_attack()) {
				cout << "[" << opponent->get_name() << " �ϥX�F " << opponent->get_trick(1)->get_name() << "]\n";
				opponent->do_big_trick(5);
				choose_one_pokemon->receive_trick(opponent->get_max_HP() - opponent->get_HP());
				cout << "[" << choose_one_pokemon->get_name() << "��HP���" << opponent->get_max_HP() - opponent->get_HP() << "]\n";
				//�D�u1-3���S�����
				if (current_mission == &missions[0][2] && Pikachu.get_HP() <= 50) {
					Pikachu.set_HP(0 - Pikachu.get_HP());
					availible_pokemon_num--;
					break;
				}
				opponent->set_HP(opponent->get_max_HP() - opponent->get_HP());
				my_cout("[�G�M�Ϋ�_����HP]");
			}
			//�G�M�Τp��
			else {
				cout << "[" << opponent->get_name() << " �ϥX�F " << opponent->get_trick(0)->get_name() << "]\n";
				for (int i = 0; i < choose_one_pokemon->get_attribute_num(); i++) {
					attribute_conflict *= attribute_conflict_table[opponent->get_trick(0)->get_attribute()][*choose_one_pokemon->get_attribute(i)];
				}
				double damage = opponent->get_trick(0)->get_attack() * attribute_conflict;
				opponent->do_small_trick(damage);
				choose_one_pokemon->receive_trick(damage);
				cout << "[" << choose_one_pokemon->get_name() << "��HP���" << damage << "]\n";
				//�D�u1-3���S�����
				if (current_mission == &missions[0][2] && Pikachu.get_HP() <= 50) {
					Pikachu.set_HP(0 - Pikachu.get_HP());
					availible_pokemon_num--;
					break;
				}
				attribute_conflict = 1;
			}
		}
		//�@��ĤH
		else {
			while (choose_num2 != -1) {//��ۡG�Y���j�۵o�j�ۡA�Y�S���o�p��
				unsigned seed = chrono::system_clock::now().time_since_epoch().count();
				default_random_engine generator(seed);
				uniform_int_distribution<int> distribution(0, 1);
				choose_num2 = distribution(generator);
				if (opponent->get_trick_num() >= choose_num2 + 2) {
					if (opponent->get_trick(choose_num2 + 2)->get_bigORsmall() == 0 && opponent->get_gas() >= opponent->get_trick(choose_num2 + 2)->get_attack()) {
						choose_num2 += 2;
						break;
					}
					else if (opponent->get_trick(choose_num2)->get_bigORsmall() == 1) {
						break;
					}
				}
				else {
					break;
				}
			}
			cout << "[" << opponent->get_name() << " �ϥX�F " << opponent->get_trick(choose_num2)->get_name() << "]\n";
			for (int i = 0; i < choose_one_pokemon->get_attribute_num(); i++) {
				attribute_conflict *= attribute_conflict_table[opponent->get_trick(choose_num2)->get_attribute()][*choose_one_pokemon->get_attribute(i)];
				if (player.get_now_badge_attribute() < 18) {
					if (player.get_now_badge_attribute() == *choose_one_pokemon->get_attribute(i)) {
						attribute_conflict *= 0.8;
					}
				}
			}
			if (opponent->get_trick(choose_num2)->get_bigORsmall() == 0) {
				opponent->do_big_trick(opponent->get_trick(choose_num2)->get_attack() * attribute_conflict);
			}
			else if (opponent->get_trick(choose_num2)->get_bigORsmall() == 1) {
				opponent->do_small_trick(opponent->get_trick(choose_num2)->get_attack() * attribute_conflict);
			}
			double damage= opponent->get_trick(choose_num2)->get_attack() * attribute_conflict;
			choose_one_pokemon->receive_trick(damage);
			cout << "[" << choose_one_pokemon->get_name() << "��HP���" << damage << "]\n";
			attribute_conflict = 1;
			//�D�u6-1���S�����
			if (current_mission == &missions[5][0] && choose_one_pokemon == &Talonflame && choose_one_pokemon->get_HP() <= 50) {
				availible_pokemon_num--;
				break;
			}
			//�D�u6-3���S�����
			if (current_mission == &missions[5][2] && choose_one_pokemon == &Frogadier && choose_one_pokemon->get_HP() <= 50) {
				availible_pokemon_num--;
				break;
			}
			//�D�u7-4���S�����
			if (current_mission == &missions[6][3] && choose_one_pokemon == &Greninja && choose_one_pokemon->get_HP() <= 50) {
				availible_pokemon_num--;
				break;
			}
			//�i��
			if (evolution_condition() == true) {
				my_cout("\n[�A]�G" + choose_one_pokemon->get_name() + "�I");
				my_cout("[���ɡA�A����" + choose_one_pokemon->get_name() + "�P�D��¶�ۥզ⪺��]");
				cout << "[" << choose_one_pokemon->get_name() << "�i�Ʀ�" + choose_one_pokemon->get_higher_ptr()->get_name() + "�F]"; cin.ignore();
				player.evolution(choose_one_pokemon);
				choose_one_pokemon = choose_one_pokemon->get_higher_ptr();
			}
		}
		//���a�_�i�ڥ��h�԰���O�H
		if (choose_one_pokemon->get_HP() <= 0) {
			cout << "[" << choose_one_pokemon->get_name() << " ���h�԰���O]\n";
			availible_pokemon_num--;
			if (choose_one_pokemon->get_mega() == true) {
				choose_one_pokemon->set_mega(false);
				cout << "[" << choose_one_pokemon->get_name() << "�ܦ^�@�뫬�A]\n";
			}
			choose_one_pokemon->set_current_gas(0);
			choose_one_pokemon = NULL;
			break;
		}
		else {
			cout << "[" << choose_one_pokemon->get_name() << "�{�b��HP�G" << choose_one_pokemon->get_HP() << "]";
			cin.ignore();
			cout << endl;
		}
		//�Ե�mega�i�ơH
		if (choose_one_pokemon->get_mega_ability() == true && choose_one_pokemon->get_mega() == false) {
			if (choose_one_pokemon->get_HP() <= choose_one_pokemon->get_max_HP() * 0.5) {
				choose_one_pokemon->set_mega(true);
				my_cout("[�ҶP�Ե쪺�������ͤF�ܤ�]\n[" + choose_one_pokemon->get_name() + "�P�D�Q���s���]��]");
			}
		}
	}
}

bool evolution_condition() {
	if (current_mission == &missions[2][1] && choose_one_pokemon == &Fletchling && choose_one_pokemon->get_HP() <= 20) {
		return true;
	}
	if (current_mission == &missions[2][4] && choose_one_pokemon == &Froakie && choose_one_pokemon->get_HP() <= 10) {
		return true;
	}
	if (current_mission == &missions[3][1] && choose_one_pokemon == &Goomy && choose_one_pokemon->get_HP() <= 20) {
		return true;
	}
	if (current_mission == &missions[5][0] && choose_one_pokemon == &Fletchinder && choose_one_pokemon->get_HP() <= 20) {
		return true;
	}
	if (current_mission == &missions[5][3] && choose_one_pokemon == &Frogadier && choose_one_pokemon->get_HP() <= 20) {
		Greninja.set_mega_ability(true);
		return true;
	}
}

int print_attack_in_battle(pokemon* now_battle) {
	int a = 10;
	cout << "�п�ܰʧ@�G\n";
	if (availible_pokemon_num > 1 && current_mission != &missions[5][1]) {
		cout << "0.���_�i��\n";
	}
	for (int i = 0; i < now_battle->get_trick_num(); i++) {
		cout << i + 1 << "." << now_battle->get_trick(i)->get_name() << "(";
		if (now_battle->get_trick(i)->get_bigORsmall() == 0 ) {
			cout << "�j��) ";
			if (now_battle->get_gas() < now_battle->get_trick(i)->get_attack()) {
				cout << "(�ثe�L�k���)";
			}
		}
		else if (now_battle->get_trick(i)->get_bigORsmall() == 1) {
			cout << "�p��)";
		}
		cout << endl;
	}
	while (a > now_battle->get_trick_num()) {
		cout << "�п�J�A����ܡG";
		cin >> a;
		if (a == 0 && current_mission != &missions[5][1]) {
			return a - 1;
		}
		else if (now_battle->get_trick(a - 1)->get_bigORsmall() == 0 && now_battle->get_gas() < now_battle->get_trick(a - 1)->get_attack()) {
			cout << "��ܵL��\n";
		}
		else {
			return a - 1;
		}
	}
}