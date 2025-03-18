#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <iomanip>
#include "header.h"

using namespace std;

water bottle = water("水", "可補充口渴度，持有數最多為75", 75, 75, 2);
berry red = berry("紅莓果", "可補充寶可夢飢餓度3格", 5, 3, 5);
berry silver = berry("銀莓果", "可補充寶可夢飢餓度5格", 5, 5, 10);
berry golden = berry("金莓果", "可補充寶可夢飢餓度7格", 0, 7, 20);
medicine normal = medicine("一般傷藥", "可補充寶可夢HP 30", 10, 30, 5);
medicine good = medicine("好傷藥", "可補充寶可夢HP 80", 10, 80, 10);
medicine hyper = medicine("厲害傷藥", "可補充寶可夢HP 150", 0, 150, 20);
food cookie = food("營養口糧", "可補充玩家飢餓度2格", 5, 2, 10);
food sandwich = food("三明治", "可補充玩家飢餓度5格", 5, 5, 20);
food spaghetti = food("義大利麵", "可補充玩家飢餓度8格", 0, 8, 30);
tent my_tent = tent("帳篷", "野營必備裝備", 0, 800); 
antidote neutrilizer = antidote("中和劑", "可解除寶可夢的地域受剋", 1, 10);

void consumable::set_name(string newname) {
	name = newname;
}
void consumable::set_number(int num) {
	number += num;
}
void consumable::set_direction(string direction_) {
	direction = direction_;
}
void consumable::set_price(int price_) {
	price = price_;
}
void consumable::set_effective(int value) {
	effective = value;
}
void consumable::add_num(int value) {
	number += value;
}
bool consumable::use_item(int num) {
	if (num > number) {
		cout << "物品數量不夠，請至商店購買\n\n"; return false;
	}
	else {
		number -= num; return true;
	}
}
int consumable::get_numbers() {
	return number;
}
int consumable::get_effective() {
	return effective;
}
string consumable::get_name() {
	return name;
}
string consumable::get_direction() {
	return direction;
}
int consumable::get_price() {
	return price;
}

berry::berry(string name_, string direction_, int number_, int effective, int price_) {
	set_name(name_); set_number(number_); set_effective(effective); set_direction(direction_); set_price(price_);
}
bool berry::use_item(int num) {
	if (num > get_numbers()) {
		cout << "莓果數量不夠，請至商店購買\n\n"; return false;
	}
	else {
		set_number(-num); return true;
	}
}

medicine::medicine(string name_, string direction_, int number_, int effective, int price_) {
	set_name(name_); set_number(number_); set_effective(effective); set_direction(direction_); set_price(price_);
}
bool medicine::use_item(int num) {
	if (num > get_numbers()) {
		cout << "傷藥數量不夠，請至商店購買\n\n"; return false;
	}
	else {
		set_number(-num); return true;
	}
}

food::food(string name_, string direction_, int number_, int effective, int price_) {
	set_name(name_); set_number(number_); set_effective(effective); set_direction(direction_); set_price(price_);
}
bool food::use_item(int num) {
	if (num > get_numbers()) {
		cout << "食物數量不夠，請至商店購買\n\n"; return false;
	}
	else {
		set_number(-num); return true;
	}
}

water::water(string name_, string direction_, int number_, int capacity_, int price_) {
	set_name(name_); set_number(number_); capacity = capacity_; set_direction(direction_); set_price(price_); set_effective(1);
}
bool water::use_item(int num) {
	if (num > get_numbers()) {
		cout << "水不夠多，請至商店購買\n\n"; return false;
	}
	else {
		set_number(-num); return true;
	}
}
int water::get_capacity() {
	return capacity;
}
void water::fill_water() {
	set_number(get_capacity() - get_numbers());
}

antidote::antidote(string name_, string direction_, int num_, int price_) {
	set_name(name_); set_number(num_); set_direction(direction_); set_price(price_); set_effective(1);
}
bool antidote::use_item(int num) {
	if (get_numbers() == 0) {
		cout << "中和劑數量不夠，請至商店購買\n\n"; return false;
	}
	set_number(-1); return true;
}

tent::tent(string name_, string direction_, int num_, int price_) {
	set_name(name_); set_number(num_); set_direction(direction_); set_price(price_);
}

badge::badge(string gym_, int attr) {
	badge::gym = gym_; attribute = attr;
}
int badge::get_attribute() {
	return attribute;
}
string badge::get_gym() {
	return gym;
}
void badge::print_detail() {
	cout << attribute_list[attribute] << "系徽章（" << get_gym() << "）";
}