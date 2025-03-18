#include "header.h"
#include <iostream>
#include <cstdlib>
#include <random>
#include <chrono>
#include <iomanip>

using namespace std;

my_pokemon* choose_one_pokemon = NULL;
int availible_choose_pokemon_num = 0;//可以選的寶可夢數
int availible_pokemon_num = 0;//還能戰鬥的寶可夢數

bool whole_battle(int my_num, int NPC_num, trainer* NPC, pokemon* opponents[]) {
	availible_choose_pokemon_num = my_num;
	availible_pokemon_num = my_num;
	my_pokemon* choose_my_pokemons[6] = { NULL };
	for (int i = 0; i < NPC_num; i++) {
		if (NPC != NULL) {
			cout << "\n[" << NPC->get_name() << " 派出了 " << opponents[i]->get_name() << "(";
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
				//選擇寶可夢
				int choose_num = 0;
				cout << "請選擇你要派出的寶可夢：\n";
				//還能選新的
				if (availible_choose_pokemon_num > 0) {
					player.print_my_pokemon_value(opponents[i]);
					if (current_mission == &missions[0][1]) {
						cout << "\n  [HINT]\n  以上為你目前持有的寶可夢。\n";
						cout << "  寶可夢名字後面附註屬性。屬性相剋會影響攻擊與防禦，若寶可夢的屬性有利於對戰，則會附註「推薦」字樣，反之亦然。\n";
						cout << "  若是屬性沒有特別有利或不利則不會顯示。\n";
						cout << "  名字下方顯示寶可夢的HP以及飢餓度與口渴度。記住，飢餓度與口渴度若<=3就無法對戰。\n";
						cout << "  接下來幾行顯示的是寶可夢的招式與其屬性。大招需要集氣，攻擊力越高需要的集氣量就越高。小招負責幫大招集氣，同樣，攻擊力越高累積的集氣量就越高。\n";
						cout << "  先選擇編號1 皮卡丘 吧\n";
					}
					while (choose_num == 0) {
						cout << "\n請輸入你的選擇："; cin >> choose_num;
						if (player.get_my_pokemon(choose_num - 1)->get_catch() == false || player.get_my_pokemon(choose_num - 1)->get_HP() <= 0 || player.get_my_pokemon(choose_num - 1)->get_hungry() <= 3 || player.get_my_pokemon(choose_num - 1)->get_thirsty() <= 3) {
							cout << "輸入無效，請重新選擇\n";
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
				//不能選新的
				else {
					//印選項
					for (int h = 0; h < my_num; h++) {
						cout << h+1 << "." << choose_my_pokemons[h]->get_name() << "(";
						choose_my_pokemons[h]->print_attribute();
						cout << ")：";
						if (choose_my_pokemons[h]->get_HP() == 0 || choose_my_pokemons[h]->get_hungry() <= 3 || choose_my_pokemons[h]->get_thirsty() <= 3) {
							cout << "無法戰鬥";
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
								cout << "不推薦";
							}
							else if (confict_value_attack - confict_value_defence > 2) {
								cout << "推薦";
							}
						}
						cout << "\n  HP：" << choose_my_pokemons[h]->get_HP() << "/" << choose_my_pokemons[h]->get_max_HP() << "  飢餓程度：" << choose_my_pokemons[h]->get_hungry() << "/15  口渴程度：" << choose_my_pokemons[h]->get_thirsty() << "/15\n";
						for (int o = 0; o < choose_my_pokemons[h]->get_trick_num(); o++) {
							if (choose_my_pokemons[h]->get_trick(o)->get_bigORsmall() == 0) {
								cout << "  大招：" << setw(8) << right << choose_my_pokemons[h]->get_trick(o)->get_name() << "：" << setw(7) << left << attribute_list[choose_my_pokemons[h]->get_trick(o)->get_attribute()] << "攻擊力：" << choose_my_pokemons[h]->get_trick(o)->get_attack() << endl;
							}
							else if (choose_my_pokemons[h]->get_trick(o)->get_bigORsmall() == 1) {
								cout << "  小招：" << setw(8) << right << choose_my_pokemons[h]->get_trick(o)->get_name() << "：" << setw(7) << left << attribute_list[choose_my_pokemons[h]->get_trick(o)->get_attribute()] << "攻擊力：" << choose_my_pokemons[h]->get_trick(o)->get_attack() << endl;
							}
						}
					}
					cout << "請輸入你的選擇：";
					int choose; cin >> choose;
					choose_one_pokemon = choose_my_pokemons[choose - 1];
				}
			}
			one_battle(&player, NPC, opponents[i]);
			if (availible_pokemon_num == 0) {//輸，對手HP歸滿
				for (int k = 0; k < NPC_num; k++) {
					opponents[k]->set_HP(opponents[k]->get_max_HP());
				}
				choose_one_pokemon = NULL;
				return false;
			}
		}
	}
	//戰鬥結束（贏），所有寶可夢集氣歸零，對手HP歸滿，出戰寶可夢獲得經驗值
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
				my_cout("[" + choose_one_pokemon->get_name() + "變回一般型態]");
			}
		}
	}
	if (in_rocket_battle == true) {
		for (int k = my_num - 1; k >= 0; k--) {
			my_cout("\n[火箭隊]：好討厭的感覺啊！！！！");
			my_cout("\n[恭喜你獲得勝利！]");
			my_cout("[出戰寶可夢獲得經驗值]");
			choose_my_pokemons[k]->add_experience(15);
			choose_my_pokemons[k]->set_hungry(-3);
			choose_my_pokemons[k]->set_thirsty(-3);
		}
	}
	else {
		my_cout("[你贏得戰鬥]");
		my_cout("[出戰寶可夢獲得經驗值]");
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
	cout << "[你派出了 " << choose_one_pokemon->get_name() << "]";
	cin.ignore(); cout << endl;
	if (current_mission == &missions[0][1]) {
		cout << "\n  [HINT]\n  開始對戰吧！你先開始攻擊。\n\n";
	}
	while (choose_one_pokemon->get_HP() > 0 || opponent->get_HP() > 0) {
		int choose_num1 = 0, choose_num2 = 0;
		double attribute_conflict = 1;
		//玩家攻擊
		choose_num1 = print_attack_in_battle(choose_one_pokemon);
		if (choose_num1 == -1) {
			choose_one_pokemon = NULL;
			break;
		}
		cout << "\n[" << choose_one_pokemon->get_name() << " 使出了 " << choose_one_pokemon->get_trick(choose_num1)->get_name() << "]";
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
		cout << "\n[" << opponent->get_name() << "的HP減少" << damage << "]\n";
		attribute_conflict = 1;
		//主線3-6的特殊條件
		if (current_mission == &missions[5][2] && choose_one_pokemon == &Frogadier && opponent->get_HP() <= 50) {
			availible_pokemon_num--;
			break;
		}
		//對手失去戰鬥能力？
		if (opponent->get_HP() <= 0) {
			cout << "[" << opponent->get_name() << " 無法進行對戰]\n";
			opponent->set_current_gas(0);
			if (opponent->get_mega() == true) {
				opponent->set_mega(false);
				cout << "[" << opponent->get_name() << "變回一般型態]\n";
			}
			break;
		}
		else {
			cout << "[" << opponent->get_name() << "現在的HP：" << opponent->get_HP() << "]";
			cin.ignore();
			cout << endl;
		}
		//對手mega進化？
		if (opponent->get_mega_ability() == true && opponent->get_mega() == false) {
			if (opponent->get_HP() <= opponent->get_max_HP() * 0.5) {
				opponent->set_mega(true);
				cout << "[" << NPC->get_name() << "]：" << opponent->get_name() << "，mega進化吧！";
				my_cout("[" + opponent->get_name() + "mega進化了]");
			}
		}
		
		//NPC攻擊
		//果然翁
		if (opponent == &Wobbuffet) {
			//果然翁大招
			if (opponent->get_gas() >= opponent->get_trick(1)->get_attack()) {
				cout << "[" << opponent->get_name() << " 使出了 " << opponent->get_trick(1)->get_name() << "]\n";
				opponent->do_big_trick(5);
				choose_one_pokemon->receive_trick(opponent->get_max_HP() - opponent->get_HP());
				cout << "[" << choose_one_pokemon->get_name() << "的HP減少" << opponent->get_max_HP() - opponent->get_HP() << "]\n";
				//主線1-3的特殊條件
				if (current_mission == &missions[0][2] && Pikachu.get_HP() <= 50) {
					Pikachu.set_HP(0 - Pikachu.get_HP());
					availible_pokemon_num--;
					break;
				}
				opponent->set_HP(opponent->get_max_HP() - opponent->get_HP());
				my_cout("[果然翁恢復全部HP]");
			}
			//果然翁小招
			else {
				cout << "[" << opponent->get_name() << " 使出了 " << opponent->get_trick(0)->get_name() << "]\n";
				for (int i = 0; i < choose_one_pokemon->get_attribute_num(); i++) {
					attribute_conflict *= attribute_conflict_table[opponent->get_trick(0)->get_attribute()][*choose_one_pokemon->get_attribute(i)];
				}
				double damage = opponent->get_trick(0)->get_attack() * attribute_conflict;
				opponent->do_small_trick(damage);
				choose_one_pokemon->receive_trick(damage);
				cout << "[" << choose_one_pokemon->get_name() << "的HP減少" << damage << "]\n";
				//主線1-3的特殊條件
				if (current_mission == &missions[0][2] && Pikachu.get_HP() <= 50) {
					Pikachu.set_HP(0 - Pikachu.get_HP());
					availible_pokemon_num--;
					break;
				}
				attribute_conflict = 1;
			}
		}
		//一般敵人
		else {
			while (choose_num2 != -1) {//選招：若有大招發大招，若沒有發小招
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
			cout << "[" << opponent->get_name() << " 使出了 " << opponent->get_trick(choose_num2)->get_name() << "]\n";
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
			cout << "[" << choose_one_pokemon->get_name() << "的HP減少" << damage << "]\n";
			attribute_conflict = 1;
			//主線6-1的特殊條件
			if (current_mission == &missions[5][0] && choose_one_pokemon == &Talonflame && choose_one_pokemon->get_HP() <= 50) {
				availible_pokemon_num--;
				break;
			}
			//主線6-3的特殊條件
			if (current_mission == &missions[5][2] && choose_one_pokemon == &Frogadier && choose_one_pokemon->get_HP() <= 50) {
				availible_pokemon_num--;
				break;
			}
			//主線7-4的特殊條件
			if (current_mission == &missions[6][3] && choose_one_pokemon == &Greninja && choose_one_pokemon->get_HP() <= 50) {
				availible_pokemon_num--;
				break;
			}
			//進化
			if (evolution_condition() == true) {
				my_cout("\n[你]：" + choose_one_pokemon->get_name() + "！");
				my_cout("[此時，你見到" + choose_one_pokemon->get_name() + "周遭圍繞著白色的光]");
				cout << "[" << choose_one_pokemon->get_name() << "進化成" + choose_one_pokemon->get_higher_ptr()->get_name() + "了]"; cin.ignore();
				player.evolution(choose_one_pokemon);
				choose_one_pokemon = choose_one_pokemon->get_higher_ptr();
			}
		}
		//玩家寶可夢失去戰鬥能力？
		if (choose_one_pokemon->get_HP() <= 0) {
			cout << "[" << choose_one_pokemon->get_name() << " 失去戰鬥能力]\n";
			availible_pokemon_num--;
			if (choose_one_pokemon->get_mega() == true) {
				choose_one_pokemon->set_mega(false);
				cout << "[" << choose_one_pokemon->get_name() << "變回一般型態]\n";
			}
			choose_one_pokemon->set_current_gas(0);
			choose_one_pokemon = NULL;
			break;
		}
		else {
			cout << "[" << choose_one_pokemon->get_name() << "現在的HP：" << choose_one_pokemon->get_HP() << "]";
			cin.ignore();
			cout << endl;
		}
		//忍蛙mega進化？
		if (choose_one_pokemon->get_mega_ability() == true && choose_one_pokemon->get_mega() == false) {
			if (choose_one_pokemon->get_HP() <= choose_one_pokemon->get_max_HP() * 0.5) {
				choose_one_pokemon->set_mega(true);
				my_cout("[甲賀忍蛙的神情產生了變化]\n[" + choose_one_pokemon->get_name() + "周遭被水龍捲包圍]");
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
	cout << "請選擇動作：\n";
	if (availible_pokemon_num > 1 && current_mission != &missions[5][1]) {
		cout << "0.更換寶可夢\n";
	}
	for (int i = 0; i < now_battle->get_trick_num(); i++) {
		cout << i + 1 << "." << now_battle->get_trick(i)->get_name() << "(";
		if (now_battle->get_trick(i)->get_bigORsmall() == 0 ) {
			cout << "大招) ";
			if (now_battle->get_gas() < now_battle->get_trick(i)->get_attack()) {
				cout << "(目前無法選擇)";
			}
		}
		else if (now_battle->get_trick(i)->get_bigORsmall() == 1) {
			cout << "小招)";
		}
		cout << endl;
	}
	while (a > now_battle->get_trick_num()) {
		cout << "請輸入你的選擇：";
		cin >> a;
		if (a == 0 && current_mission != &missions[5][1]) {
			return a - 1;
		}
		else if (now_battle->get_trick(a - 1)->get_bigORsmall() == 0 && now_battle->get_gas() < now_battle->get_trick(a - 1)->get_attack()) {
			cout << "選擇無效\n";
		}
		else {
			return a - 1;
		}
	}
}