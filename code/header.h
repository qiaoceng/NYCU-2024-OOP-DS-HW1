#ifndef __header__
#define __header__
#include <iostream>
#include <vector>

using namespace std;

class consumable {
public:
	void set_name(string newname);
	void set_number(int num);
	void set_direction(string direction_);
	void set_price(int price_);
	void set_effective(int value);
	void add_num(int value);
	virtual bool use_item(int num);
	int get_numbers();
	int get_effective();
	string get_name();
	string get_direction();
	int get_price();
private:
	int number, price, effective;
	string name;
	string direction;
};
class berry :public consumable {
public:
	berry(string name_, string direction_, int number_, int effective, int price_);
	bool use_item(int num);
private:
	
};
class medicine :public consumable {
public:
	medicine(string name_, string direction_, int number_, int effective, int price_);
	bool use_item(int num);
private:
	
};
class food :public consumable {
public:
	food(string name_, string direction_, int number_, int effective, int price_);
	bool use_item(int num);
private:
	
};
class water :public consumable {
public:
	water(string name_, string direction_, int number_, int capacity_, int price_);
	int get_capacity();
	void fill_water();
	bool use_item(int num);
private:
	int capacity; //1 thirsty為1單位，number是剩的水量
};
class antidote :public consumable {
public:
	antidote(string name_, string direction_, int num_, int price_);
	bool use_item(int num);
private:
	
};
class tent :public consumable {
public:
	tent(string name_, string direction_, int num_, int price_);
private:

};
class badge {
public:
	badge(string gym, int attr);
	string get_gym();
	int get_attribute();
	void print_detail();
private:
	string gym;
	int attribute;
};

class trick {
public:
	trick(string name, int attribute, int attack, int b_or_s);
	void set_attack(int addattack);
	string get_name();
	int get_attack();
	int get_bigORsmall();
	int get_attribute();
private:
	string name;
	int attribute, attack, big_or_small;//big=0,small=1,maga_big=2,mega_small=3
};
class pokemon {
public:
	pokemon(string name, int hp, bool mega_ability_);
	pokemon();
	void add_trick(trick newtrick);
	void add_attribute(int a);
	void do_small_trick(int attack);
	void do_big_trick(int attack);
	void receive_trick(double damage);
	void set_name(string name_);
	void set_mega(bool mega_);
	void set_mega_ability(bool megaability_);
	void set_HP(double HP_);
	void set_max_HP(int HP_);
	void set_current_gas(int a);
	void set_new_value(int add_HP,int add_big,int add_small);
	void print_attribute();
	double get_HP();
	double get_gas();
	int get_max_HP();
	int* get_attribute(int index);
	int get_attribute_num();
	int get_trick_num();
	bool get_mega();
	bool get_mega_ability();
	trick* get_trick(int index);
	string get_name();
private:
	string name;
	int max_HP;
	double HP, current_gas;
	bool mega_ability, mega;
	vector <int> attributes;
	vector <trick> tricks;
};
class my_pokemon: public pokemon{
public:
	my_pokemon(string name, int hp, int maxvalue, bool mega_ability_, int small, int big);
	void add_experience(int ex);
	void level_up();
	void set_hungry(int value);
	void set_thirsty(int value);
	void set_poison(bool pois);
	void set_next_ptr(my_pokemon* ptr);
	void set_higher_ptr(my_pokemon* ptr);
	void be_catched(bool a);
	bool get_catch();
	bool get_poison();
	int get_hungry();
	int get_thirsty();
	int get_level();
	int get_max_level();
	int get_experience();
	my_pokemon* get_next_ptr();
	my_pokemon* get_higher_ptr();

private:
	int level, max_level, hungry, thirsty, experience, small_plus, big_plus;
	bool poison, catch_;
	my_pokemon* next_ptr, * higher_ptr;
};

class human {
public:
	void set_name(string newname);
	void set_my_pokemon_ptr(my_pokemon* ptr);
	void print_my_pokemon_value(pokemon* opponent);
	string get_name();
	my_pokemon* get_my_pokemon(int index);
private:
	string name;
	my_pokemon* my_pokemon_ptr;
};
class you :public human{
public:
	you();
	void set_location(string loc);
	void set_hungry(int value);
	void set_thirsty(int value);
	void set_badge(int index);
	void use_ball();
	void minus_tiredness(int i);
	void fill_tiredness();
	void plus_badgenum();
	void add_badge(badge new_badge);
	void set_money(int money_);
	void add_item(consumable* new_consumable);
	void evolution(my_pokemon* evolution);
	string get_loc();
	int get_hungry();
	int get_thirsty();
	int get_tiredness();
	int get_badgenum();
	int get_money();
	int get_balls();
	int get_now_badge_attribute();
	badge* get_one_badge(int index);
	consumable* get_consumable(int index);
private:
	string location;
	int hungry, thirsty, tiredness;
	int badge_num, money, balls;
	int now_badge_attribute;
	vector <badge> my_badges;
	vector <consumable*> items;
};
class trainer :public human {
public:
	trainer(string name);
	void set_name(string nname);
private:

};

class spot {
public:
	string get_name();
	int get_catogory();
	virtual void things_to_do() = 0;
	void set_name(string name_);
	void set_catogory(int catogory_);
private:
	string name;
	int catogory;//0=main_spot,1=camp,2=water_land,3=pokemon_center
};
class main_spot :public spot {
public:
	main_spot(string name, int catogory_);
	void things_to_do();
};
class camp :public spot {
public:
	camp(string name, string event_, int my_pokemon_experience_, int catogory_);
	camp(string name, int catogory_);
	void things_to_do();
	string event; int my_pokemon_experience;
};
class water_land :public spot {
public:
	water_land(string name, int catogory_);
	void things_to_do();
};
class pokemon_center :public spot {
public:
	pokemon_center(string name, int catogory_);
	void things_to_do();
};

class city {
public:
	void set_city(string t_name, string t_describe, int num, int attribute_);
	void add_spots(int catogory, string name_);
	void add_spots(int catogory, string name_, string event_, int my_pokemon_experience_);
	string get_describe();
	string get_name();
	spot* get_spot(int index);
	int get_spot_num();
	int get_attribute();
private:
	string describe;
	string name;
	int attribute;
	int spot_num;
	vector<spot*>spots;
};

class mission {
public:
	void set_mission(string name, string allert, city* city_, spot* spot_);
	void set_start(bool start_);
	void set_complete(bool completed);
	bool get_start();
	bool get_complete();
	city* get_city();
	spot* get_spot();
	string get_name();
	string get_allert();
private:
	string name, allert;
	bool start, complete;
	city* the_city;
	spot* the_spot;
};

extern you player;
extern mission* current_mission;
extern city* current_city;
extern spot* current_spot;
extern city cities[8];
extern mission missions[9][5];
extern string attribute_list[18];
extern double attribute_conflict_table[18][18];
extern bool in_rocket_battle;
//我的物品
extern water bottle;
extern berry red, silver, golden;
extern medicine normal, good, hyper;
extern food cookie, sandwich, spaghetti;
extern tent my_tent; extern antidote neutrilizer;
//建立寶可夢
void build_player_my_pokemon();
void build_NPC_my_pokemons();
//我的寶可夢
extern my_pokemon Pikachu;
extern my_pokemon Froakie; extern my_pokemon Frogadier; extern my_pokemon Greninja;
extern my_pokemon Fletchling; extern my_pokemon Fletchinder; extern my_pokemon Talonflame;
extern my_pokemon Hawlucha;
extern my_pokemon Goomy; extern my_pokemon Sliggoo; extern my_pokemon Goodra;
extern my_pokemon Noibat; extern my_pokemon Noivern;
//館主NPC的寶可夢
extern trainer Viola; extern pokemon Surskit; extern pokemon Vivillon;
extern trainer Chakra; extern pokemon Onix; extern pokemon Tyrunt;
extern trainer Korrina; extern pokemon Mienfoo; extern pokemon Machoke; extern pokemon Lucario;
extern trainer Ramos; extern pokemon Jumpluff; extern pokemon Weepinbell; extern pokemon Gogoat;
extern trainer Clemont; extern pokemon Bunnelby; extern pokemon Heliolisk; extern pokemon Luxray;
extern trainer Valerie; extern pokemon Spritzee; extern pokemon Sylveon;
extern trainer Olympia; extern pokemon female_Meowstic; extern pokemon male_Meowstic;
extern trainer Wulfric; extern pokemon Abomasnow; extern pokemon Avalugg; extern pokemon Bergmite;
//其他NPC的寶可夢
extern trainer Rocket; extern pokemon Wobbuffet; extern pokemon Inkay; extern pokemon Pumpkaboo;
extern trainer Nami; extern pokemon Nami_Talonflame;
extern trainer Saizo; extern pokemon Barbaracle;
extern trainer Heidayu; extern pokemon Heidayu_Bisharp;
extern trainer Ahe; extern pokemon Altaria;
extern trainer Alain; extern pokemon Tyranitar; extern pokemon Weavile; extern pokemon Bisharp; extern pokemon Unfezant; extern pokemon Metagross; extern pokemon Charizard;
extern trainer Sawyer; 
extern pokemon Treecko; extern pokemon Sceptile; extern pokemon Slurpuff;
extern pokemon Bagon; extern pokemon Shelgon; extern pokemon Salamence; extern pokemon Clawitzer;
extern pokemon Honedge; extern pokemon Doublade; extern pokemon Aegislash; extern pokemon Slaking;
//野生寶可夢
extern pokemon Grumpig; extern pokemon Florges; extern pokemon Moltres; extern pokemon Zapdos;
//mainmenu的函式
void my_cout(string sentence);
void build_city();
void build_mission_list();
void main_menu();
void print_map();
void print_profile();
void Rocket_battle();
void print_bag();
void print_my_my_pokemon();
void print_conflict_table();
void enter_mission(int a, int b);
void confirm_land_conflict();
void minus_health();
//battle的函式
bool whole_battle(int my_num, int NPC_num, trainer* NPC, pokemon* opponents[]);
void one_battle(you* player_, trainer* NPC, pokemon* opponent);
bool evolution_condition();
int print_attack_in_battle(pokemon* now_battle);
extern bool win_or_lose;
extern int availible_choose_my_pokemon_num;
extern int availible_my_pokemon_num;
extern my_pokemon* choose_one_pokemon;
//mission的函式
void opening();
void mission1_1(); void mission1_2(); void mission1_3(); void mission1_4(); void mission1_5();
void mission2_1(); void mission2_2(); void mission2_3(); void mission2_4(); 
void mission3_1(); void mission3_2(); void mission3_3(); void mission3_4(); void mission3_5();
void mission4_1(); void mission4_2(); void mission4_3(); void mission4_4();
void mission5_1(); void mission5_2(); void mission5_3(); void mission5_4(); 
void mission6_1(); void mission6_2(); void mission6_3(); void mission6_4(); 
void mission7_1(); void mission7_2(); void mission7_3(); void mission7_4(); void mission7_5();
void mission8_1(); void mission8_2(); void mission8_3(); void mission8_4(); 
void mission9_1(); void mission9_2(); void mission9_3();
void ending();
void use_my_pokemon_ball();
#endif // !__header__