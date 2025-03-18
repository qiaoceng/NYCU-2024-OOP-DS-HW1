#include "header.h"
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

trick::trick(string name, int attribute, int attack, int b_or_s) {
	trick::name = name, trick::attribute = attribute, trick::attack = attack, big_or_small = b_or_s;
}
void trick::set_attack(int addattack) {
	attack += addattack;
}
string trick::get_name() {
	return name;
}
int trick::get_attack() {
	return attack;
}
int trick::get_bigORsmall() {
	return big_or_small;
}
int trick::get_attribute() {
	return attribute;
}

pokemon::pokemon() {
	name = "no"; HP = 0, max_HP = 0, current_gas = 0;
	mega_ability = false, mega = false;
}
pokemon::pokemon(string name, int hp, bool mega_) {//for trainer
	pokemon::name = name;
	HP = hp, max_HP = hp, current_gas = 0;
	mega_ability = mega_, mega = false;
}
void pokemon::add_trick(trick newtrick) {
	tricks.push_back(newtrick);
}
void pokemon::add_attribute(int a) {
	attributes.push_back(a);
}
void pokemon::do_small_trick(int attack) {
	current_gas += attack * 0.8;
}
void pokemon::do_big_trick(int attack) {
	current_gas -= attack;
}
void pokemon::receive_trick(double damage) {
	set_HP(-damage);
}
void pokemon::set_name(string name_) {
	name = name_;
}
void pokemon::set_mega_ability(bool megaability_) {
	mega_ability = megaability_;
}
void pokemon::set_mega(bool mega_) {
	mega = mega_;
	if (mega_ == true) {
		for (int i = 0; i < get_trick_num(); i++) {
			if (get_trick(i)->get_bigORsmall() == 0) {
				get_trick(i)->set_attack(50);
			}
			else if (get_trick(i)->get_bigORsmall() == 1) {
				get_trick(i)->set_attack(10);
			}
		}
	}
	else {
		for (int i = 0; i < get_trick_num(); i++) {
			if (get_trick(i)->get_bigORsmall() == 0) {
				get_trick(i)->set_attack(-50);
			}
			else if (get_trick(i)->get_bigORsmall() == 1) {
				get_trick(i)->set_attack(-10);
			}
		}

	}
}
void pokemon::set_max_HP(int HP_) {
	max_HP = HP_;
}
void pokemon::set_HP(double HP_) {
	HP += HP_;
	if (HP > max_HP) {
		HP = max_HP;
	}
	else if (HP < 0) {
		HP = 0;
	}
}
void pokemon::set_current_gas(int a) {
	current_gas = a;
}
void pokemon::set_new_value(int add_HP, int add_big, int add_small) {
	max_HP += add_HP;
	HP = max_HP;
	for (int i = 0; i < get_trick_num(); i++) {
		if (get_trick(i)->get_bigORsmall() == 0) {
			get_trick(i)->set_attack(add_big);
		}
		else if (get_trick(i)->get_bigORsmall() == 1) {
			get_trick(i)->set_attack(add_small);
		}
	}
}
void pokemon::print_attribute() {
	for (int n = 0; n < get_attribute_num(); n++) {
		cout << attribute_list[*get_attribute(n)];
		if (n != get_attribute_num() - 1) {
			cout << "、";
		}
	}
}
bool pokemon::get_mega() {
	return mega;
}
bool pokemon::get_mega_ability() {
	return mega_ability;
}
double pokemon::get_HP() {
	return HP;
}
double pokemon::get_gas() {
	return current_gas;
}
int pokemon::get_max_HP() {
	return max_HP;
}
int* pokemon::get_attribute(int index) {
	return &attributes[index];
}
int pokemon::get_attribute_num() {
	return attributes.size();
}
int pokemon::get_trick_num() {
	return tricks.size();
}
trick* pokemon::get_trick(int index) {
	return &tricks[index];
}
string pokemon::get_name() {
	return name;
}

my_pokemon::my_pokemon(string name, int hp, int maxvalue, bool mega_ability_, int small, int big) {
	set_name(name); set_max_HP(hp); set_HP(hp); set_mega_ability(mega_ability_); set_mega(false);
	small_plus = small, big_plus = big;
	level = 1, max_level = maxvalue, hungry = 15, thirsty = 15, experience = 0;
	poison = false, catch_ = false;
	next_ptr = NULL, higher_ptr = NULL;
}
void my_pokemon::add_experience(int ex) {
	experience += ex;
	if (experience >= 50) {
		level_up();
	}
}
void my_pokemon::level_up() {
	level++;
	set_max_HP(get_max_HP() + 20);
	set_HP(20);
	for (int i = 0; i < get_trick_num(); i++) {
		if (get_trick(i)->get_bigORsmall() == 1) {
			get_trick(i)->set_attack(small_plus);
		}
		else {
			get_trick(i)->set_attack(big_plus);
		}
	}
	experience = 0;
	cout << "[" << get_name() << "升等了，攻擊、HP增加]"; cin.ignore();
}
void my_pokemon::set_hungry(int value) {
	hungry += value;
	if (hungry < 0) {
		hungry = 0;
	}
	if (hungry > 15) {
		hungry = 15;
	}
}
void my_pokemon::set_thirsty(int value) {
	thirsty += value;
	if (thirsty < 0) {
		thirsty = 0;
	}
	if (thirsty > 15) {
		thirsty = 15;
	}
}
void my_pokemon::set_poison(bool pois) {
	poison = pois;
}
void my_pokemon::set_next_ptr(my_pokemon* ptr) {
	next_ptr = ptr;
}
void my_pokemon::set_higher_ptr(my_pokemon* ptr) {
	higher_ptr = ptr;
}
void my_pokemon::be_catched(bool a) {
	catch_ = a;
}
bool my_pokemon::get_catch() {
	return catch_;
}
bool my_pokemon::get_poison() {
	return poison;
}
int my_pokemon::get_hungry() {
	return hungry;
}
int my_pokemon::get_thirsty() {
	return thirsty;
}
int my_pokemon::get_level() {
	return level;
}
int my_pokemon::get_max_level() {
	return max_level;
}
int my_pokemon::get_experience() {
	return experience;
}
my_pokemon* my_pokemon::get_next_ptr() {
	return next_ptr;
}
my_pokemon* my_pokemon::get_higher_ptr() {
	return higher_ptr;
}