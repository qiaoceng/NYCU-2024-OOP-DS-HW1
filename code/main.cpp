#include "header.h"
#include <iostream>
#include <string>

using namespace std;

you player = you();
mission* current_mission;
city* current_city;
spot* current_spot;
bool in_rocket_battle = false;

int main() {
	build_city();
	build_mission_list();
	build_player_my_pokemon();
	build_NPC_my_pokemons();
	
	opening();
	current_mission = &missions[0][0];
	current_city = &cities[0], current_spot = cities[0].get_spot(0);

	mission1_1(); mission1_2(); mission1_3(); mission1_4(); mission1_5();
	mission2_1(); mission2_2(); mission2_3(); mission2_4();
	mission3_1(); mission3_2(); mission3_3(); mission3_4(); mission3_5();
	mission4_1(); mission4_2(); mission4_3(); mission4_4();
	mission5_1(); mission5_2(); mission5_3(); mission5_4();
	mission6_1(); mission6_2(); mission6_3(); mission6_4();
	mission7_1(); mission7_2(); mission7_3(); mission7_4(); mission7_5();
	mission8_1(); mission8_2(); mission8_3(); mission8_4();
	mission9_1(); mission9_2(); mission9_3();
	ending();
}
