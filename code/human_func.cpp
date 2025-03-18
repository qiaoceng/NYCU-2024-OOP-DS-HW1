#include "header.h"
#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <iomanip>

using namespace std;

void human::set_name(string newname) {
	name = newname;
}
void human::set_my_pokemon_ptr(my_pokemon* ptr) {
	my_pokemon_ptr = ptr;
}
void human::print_my_pokemon_value(pokemon* opponent) {
	int i = 1; my_pokemon* now_print = my_pokemon_ptr;
	while (now_print != NULL) {
		if (now_print->get_catch() == true) {
			cout << i << "." << now_print->get_name() << "(";
			now_print->print_attribute();
			cout << ")：";
			if (now_print->get_hungry() <= 3 || now_print->get_thirsty() <= 3 || now_print->get_HP() == 0) {
				cout << "無法戰鬥";
			}
			else {
				double confict_value_attack = 1, confict_value_defence = 1;
				for (int x = 0; x < now_print->get_attribute_num(); x++) {
					for (int y = 0; y < opponent->get_attribute_num(); y++) {
						confict_value_attack *= attribute_conflict_table[*now_print->get_attribute(x)][*opponent->get_attribute(y)];
						confict_value_defence *= attribute_conflict_table[*opponent->get_attribute(y)][*now_print->get_attribute(x)];
					}
				}
				if (confict_value_attack - confict_value_defence < 0) {
					cout << "不推薦";
				}
				else if (confict_value_attack - confict_value_defence > 0) {
					cout << "推薦";
				}
			}
			cout << "\n  HP：" << now_print->get_HP() << "/" << now_print->get_max_HP() << "  飢餓度：" << now_print->get_hungry() << "/15  口渴度：" << now_print->get_thirsty() << "/15\n";
			for (int o = 0; o < now_print->get_trick_num(); o++) {
				if (now_print->get_trick(o)->get_bigORsmall() == 0) {
					cout << "  大招：" << setw(8) << right << now_print->get_trick(o)->get_name() << "：" << setw(7) << left << attribute_list[now_print->get_trick(o)->get_attribute()] << "攻擊力：" << now_print->get_trick(o)->get_attack() << endl;
				}
				else if (now_print->get_trick(o)->get_bigORsmall() == 1) {
					cout << "  小招：" << setw(8) << right << now_print->get_trick(o)->get_name() << "：" << setw(7) << left << attribute_list[now_print->get_trick(o)->get_attribute()] << "攻擊力：" << now_print->get_trick(o)->get_attack() << endl;
				}
			}
			i++;
			now_print = now_print->get_next_ptr();
		}
		else {
			break;
		}
	}
	
}
string human::get_name() {
	return name;
}
my_pokemon* human::get_my_pokemon(int index) {//return 指標：指向你要的my_pokemon
	my_pokemon* now = my_pokemon_ptr;
	for (int a = 0; a < index; a++) {
		now = now->get_next_ptr();
	}
	return now;
}

you::you() {
	hungry = 15, thirsty = 15, badge_num = 0, tiredness = 15, money = 2000, balls = 4, now_badge_attribute = 18;
	add_item(&bottle);
	add_item(&red); add_item(&silver); add_item(&golden);
	add_item(&cookie); add_item(&sandwich); add_item(&spaghetti);
	add_item(&normal); add_item(&good); add_item(&hyper);
	add_item(&neutrilizer); add_item(&my_tent);
}
void you::set_location(string loc) {
	location = loc;
}
string you::get_loc() {
	return location;
}
void you::set_hungry(int value) {
	hungry += value;
	if (hungry < 0) {
		hungry = 0;
	}
	if (hungry > 15) {
		hungry = 15;
	}
}
void you::set_thirsty(int value) {
	thirsty += value;
	if (thirsty < 0) {
		thirsty = 0;
	}
	if (thirsty > 15) {
		thirsty = 15;
	}
}
void you::set_badge(int index) {
	if (index == 8) {
		now_badge_attribute = 18;
	}
	else {
		now_badge_attribute = get_one_badge(index)->get_attribute();
	}
}
void you::use_ball() {
	balls--;
}
void you::minus_tiredness(int i) {
	tiredness -= i;
	if (tiredness < 0) {
		tiredness = 0;
	}
}
void you::fill_tiredness() {
	tiredness = 15;
}
void you::plus_badgenum() {
	badge_num++;
}
void you::add_badge(badge new_badge) {
	my_badges.push_back(new_badge);
}
void you::set_money(int money_) {
	money += money_;
}
void you::add_item(consumable* new_consumable) {
	items.push_back(new_consumable);
}
void you::evolution(my_pokemon* evolution) {
	evolution->get_higher_ptr()->be_catched(true);
	evolution->get_higher_ptr()->set_next_ptr(evolution->get_next_ptr());
	evolution->set_next_ptr(NULL);
	int i = 0;
	while (get_my_pokemon(i)->get_next_ptr() != evolution) {
		i++;
	}
	get_my_pokemon(i)->set_next_ptr(evolution->get_higher_ptr());
	evolution->get_higher_ptr()->set_current_gas(evolution->get_gas());
}
int you::get_hungry() {
	return hungry;
}
int you::get_thirsty() {
	return thirsty;
}
int you::get_tiredness() {
	return tiredness;
}
int you::get_badgenum() {
	return badge_num;
}
int you::get_money() {
	return money;
}
int you::get_balls() {
	return balls;
}
int you::get_now_badge_attribute() {
	return now_badge_attribute;
}
badge* you::get_one_badge(int index) {
	badge* now = &my_badges[index];
	return now;
}
consumable* you::get_consumable(int index) {
	return items[index];
}

trainer::trainer(string nname) {
	set_name(nname);
}
void trainer::set_name(string nname) {
	human::set_name(nname);
}