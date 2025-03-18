#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <iomanip>
#include "header.h"

using namespace std;

water bottle = water("��", "�i�ɥR�f���סA�����Ƴ̦h��75", 75, 75, 2);
berry red = berry("�����G", "�i�ɥR�_�i�ڰ��j��3��", 5, 3, 5);
berry silver = berry("�Ȳ��G", "�i�ɥR�_�i�ڰ��j��5��", 5, 5, 10);
berry golden = berry("�����G", "�i�ɥR�_�i�ڰ��j��7��", 0, 7, 20);
medicine normal = medicine("�@�����", "�i�ɥR�_�i��HP 30", 10, 30, 5);
medicine good = medicine("�n����", "�i�ɥR�_�i��HP 80", 10, 80, 10);
medicine hyper = medicine("�F�`����", "�i�ɥR�_�i��HP 150", 0, 150, 20);
food cookie = food("��i�f³", "�i�ɥR���a���j��2��", 5, 2, 10);
food sandwich = food("�T���v", "�i�ɥR���a���j��5��", 5, 5, 20);
food spaghetti = food("�q�j�Q��", "�i�ɥR���a���j��8��", 0, 8, 30);
tent my_tent = tent("�b�O", "���祲�Ƹ˳�", 0, 800); 
antidote neutrilizer = antidote("���M��", "�i�Ѱ��_�i�ڪ��a����g", 1, 10);

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
		cout << "���~�ƶq�����A�Цܰө��ʶR\n\n"; return false;
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
		cout << "���G�ƶq�����A�Цܰө��ʶR\n\n"; return false;
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
		cout << "���ļƶq�����A�Цܰө��ʶR\n\n"; return false;
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
		cout << "�����ƶq�����A�Цܰө��ʶR\n\n"; return false;
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
		cout << "�������h�A�Цܰө��ʶR\n\n"; return false;
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
		cout << "���M���ƶq�����A�Цܰө��ʶR\n\n"; return false;
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
	cout << attribute_list[attribute] << "�t�����]" << get_gym() << "�^";
}