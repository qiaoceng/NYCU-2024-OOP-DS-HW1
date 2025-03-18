#include "header.h"
#include <iostream>
#include <cstdlib>
#include <random>
#include <chrono>
#include <iomanip>

using namespace std;

void my_cout(string sentence) {
	cout << sentence;
	cin.ignore();
}

void main_menu() {
	int menu_choose = 0; bool fill_hungry_thirsty = false;
	cout << "\n主頁選單：\n";
	//判斷有沒有寶可夢數值不夠
	if (player.get_thirsty() == 0 || player.get_hungry() == 0) {
		fill_hungry_thirsty = true;
	}
	else {
		int i = 0;
		while (player.get_my_pokemon(i) != NULL) {
			if (player.get_my_pokemon(i)->get_catch() == true) {
				if (player.get_my_pokemon(i)->get_thirsty() == 0 || player.get_my_pokemon(i)->get_hungry() == 0) {
					fill_hungry_thirsty = true;
					break;
				}
				i++;
			}
			else {
				break;
			}
			
		}
	}
	if (fill_hungry_thirsty == true) {
		cout << "請補充能量或水！\n";
	}
	else if (player.get_tiredness() == 0) {
		cout << "請去寶可夢中心或找個營地休息\n";
		if (current_mission == &missions[0][4]) {
			cout << "    [HINT]\n    請選擇 地圖>>密阿雷市>>寶可夢中心\n";
		}
	}
	else {
		//地區受剋提醒
		int i = 0; bool exist = false;
		while (player.get_my_pokemon(i) != NULL) {
			if (player.get_my_pokemon(i)->get_catch() == true) {
				if (player.get_my_pokemon(i)->get_poison() == true) {
					exist = true;
					cout << player.get_my_pokemon(i)->get_name() << " ";
				}
				if (player.get_my_pokemon(i)->get_next_ptr() == NULL) {
					break;
				}
				i++;
			}
			else {
				break;
			}
		}
		
		if (exist == true) {
			cout << "被" << current_city->get_name() << "的地區屬性影響，飢餓度與口渴度消耗增加。\n\n";
		}
		cout << "主線劇情：" << current_mission->get_name() << endl;
		if (current_mission->get_complete() == false) {
			cout << "提示：" << current_mission->get_allert() << endl << endl;
		}
		if (current_mission == &missions[0][0] && missions[0][0].get_complete() == false) {
			cout << "    [HINT]\n";
			cout << "    進入地圖，你可以選擇城市及景點，在卡洛斯地區各處遊玩\n";
			cout << "    但離開目前所處的城市會扣玩家體力3點，請謹慎選擇！\n\n";
		}
		if (current_spot == current_mission->get_spot() && current_mission->get_complete() == false && fill_hungry_thirsty == false && player.get_tiredness() != 0) {
			cout << "0.進入主線\n";
		}
	}
	cout << "1.地圖\n";
	if (missions[0][0].get_complete() == true) {
		cout << "2.查看玩家檔案\n";
		if (current_mission == &missions[0][0]) {
			cout << "\n請選擇 查看玩家檔案\n";
		}
	}
	if (missions[0][2].get_complete() == true) {
		cout << "3.火箭隊雷達";
		if (player.get_tiredness() == 0) {
			cout << "(體力值太低，無法選擇)";
		}
		cout << endl;
		if (current_mission == &missions[0][2]) {
			cout << "\n請選擇 火箭隊雷達\n";
		}
	}
	if (missions[0][3].get_complete() == true) {
		cout << "4.我的背包\n";
		if (current_mission == &missions[0][3]) {
			cout << "\n請選擇 我的背包\n";
		}
	}
	if (missions[1][0].get_complete() == true) {
		cout << "5.我的寶可夢\n6.屬性剋制表\n";//可查看互剋屬性表
		if (current_mission == &missions[1][0]) {
			cout << "\n請選擇 我的寶可夢\n";
		}
	}
	if (current_mission == &missions[7][3] && missions[7][3].get_complete() == true) {
		cout << "\n請選擇 查看玩家檔案\n";
	}
	
	cout << "請輸入你的選擇：";
	cin >> menu_choose;
	if (menu_choose == 0 && current_spot == current_mission->get_spot()) {

	}
	else if (menu_choose == 1) {
		print_map();
	}
	else if (menu_choose == 2 && (missions[0][0].get_complete() == true|| current_mission == &missions[0][1])) {
		print_profile();
	}
	else if (menu_choose == 3 && missions[0][2].get_complete() == true) {
		Rocket_battle();
	}
	else if (menu_choose == 4 && missions[0][3].get_complete() == true) {
		print_bag();
	}
	else if (menu_choose == 5 && missions[1][0].get_complete() == true) {
		print_my_my_pokemon();
	}
	else if (menu_choose == 6 && missions[1][0].get_complete() == true) {
		print_conflict_table();
	}
	else {
		cout << "輸入有誤，請再試一次\n";
		main_menu();
	}
}

void print_map() {
	int mapchoose_1, mapchoose_2;
	cout << "\n你現在的位置：" << current_city->get_name() << " " << current_spot->get_name() << endl;
	cout << "城市列表：\n";
	for (int i = 0; i < 8; i++) {
		cout << i + 1 << "." << setw(8) <<right << cities[i].get_name() << " " << cities[i].get_describe() << endl;
	}
	cout << "請輸入你的選擇：";
	cin >> mapchoose_1;
	while (mapchoose_1 > 8) {
		cout << "輸入錯誤，請重新輸入你的選擇：";
		cin >> mapchoose_1;
	}
	while (&cities[mapchoose_1 - 1] != current_city && player.get_tiredness() == 0){
		cout << "體力值太低，你無法前往其他城市。請重新輸入你的選擇：";
		cin >> mapchoose_1;
	}
	if (&cities[mapchoose_1 - 1] != current_city) {
		current_city = &cities[mapchoose_1 - 1];
		confirm_land_conflict();
		player.minus_tiredness(3);
	}
	cout << "\n景點列表：\n";
	for (int i = 0; i < cities[mapchoose_1 - 1].get_spot_num(); i++) {
		cout << i + 1 << "." << cities[mapchoose_1 - 1].get_spot(i)->get_name();
		if (cities[mapchoose_1 - 1].get_spot(i)->get_catogory() == 2) {
			cout << "（此處可以野營）";
		}
		else if (cities[mapchoose_1 - 1].get_spot(i)->get_catogory() == 3) {
			cout << "（此處可以補水）";
		}
		cout << endl;
	}
	cout << "請輸入你的選擇：";
	cin >> mapchoose_2;
	while (mapchoose_2 > cities[mapchoose_1 - 1].get_spot_num()) {
		cout << "輸入錯誤，請重新輸入你的選擇：";
		cin >> mapchoose_2;
	}
	current_spot = cities[mapchoose_1 - 1].get_spot(mapchoose_2 - 1);
	cout << "\n你現在的位置：" << current_city->get_name() << " " << current_spot->get_name() << endl;
	current_spot->things_to_do();
}

void print_profile() {
	cout << "\n[玩家檔案]\n玩家名字：" << player.get_name() << endl;
	cout << "來自哪裡：" << player.get_loc() << endl;
	cout << "持有徽章：";
	if (player.get_badgenum() == 0) {
		cout << "無";
	}else {
		for (int i = 0; i < player.get_badgenum(); i++) {
			player.get_one_badge(i)->print_detail();
			if (i != player.get_badgenum() - 1)
				cout << "、";
		}
	}
	if (missions[0][3].get_complete() == true) {
		cout << "\n持有未使用寶貝球數：" << player.get_balls() << endl;
		cout << "擁有皮幣數：" << player.get_money();
	}
	cout << "\n體力：" << player.get_tiredness() << "/15  飢餓度：" << player.get_hungry() << "/15  口渴度：" << player.get_thirsty() << "/15";
	cin.ignore();
	if (current_mission == &missions[0][0]) {
		my_cout("\n\n  [HINT]\n  這裡可以查看你的個人數值。\n  另外，每進行一關主線或進行一次對戰，體力、飢餓度、口渴度就會減少5。\n  稍後會再說明補充的方法。");
		current_mission = &missions[0][1];
	}
	if (missions[7][3].get_complete() == true) {
		if (current_mission == &missions[7][3]) {
			my_cout("\n\n  [HINT]\n  這裡可以選擇要配戴的徽章\n  若自己的寶可夢與徽章屬性相同，受到的攻擊會減少。\n  若對手的寶可夢屬性與徽章屬性相同，受到的攻擊會增加");
			current_mission = &missions[7][4];
		}
		int badge_choose;
		cout << "\n是否要更換配戴的徽章？（是：1，否：0）：";cin >> badge_choose;
		if (badge_choose == 1) {
			int badge_choose2;
			for (int i = 0; i < player.get_badgenum(); i++) {
				cout << i + 1 << "."; player.get_one_badge(i)->print_detail(); cout << endl;
			}
			cout << "9.不配戴徽章\n";
			cout << "請選擇要配戴的徽章：";
			cin >> badge_choose2;
			player.set_badge(badge_choose2 - 1);
		}
	}
	my_cout("\nenter to comtinue");
	main_menu();
}

void Rocket_battle() {
	int available_my_pokemon_num = 1;
	in_rocket_battle = true;
	cin.ignore();
	cout << "\n[火箭隊雷達]\n";
	unsigned seed = chrono::system_clock::now().time_since_epoch().count();
	default_random_engine generator(seed);
	uniform_int_distribution<int> distribution(0, 4);
	int rand_line = distribution(generator);
	if (rand_line == 0) {
		my_cout("[你]：是誰？");
		my_cout("[武藏]：既然你誠心誠意地問了「是誰？」");
		my_cout("[小次郎]：我就大發慈悲地回答你");
	}
	else if (rand_line == 1) {
		my_cout("[你]：什麼？");
		my_cout("[武藏]：既然你誠心誠意地問了「什麼？」");
		my_cout("[小次郎]：我就大發慈悲地回答你");
	}
	else if (rand_line == 2) {
		my_cout("[你]：發生了什麼事？");
		my_cout("[武藏]：既然你誠心誠意地問了「發生了什麼事？」");
		my_cout("[小次郎]：我就大發慈悲地回答你");
	}
	else if (rand_line == 3) {
		my_cout("[皮卡丘]：皮卡皮卡");
		my_cout("[武藏]：既然你誠心誠意地說了「皮卡皮卡」");
		my_cout("[小次郎]：我就大發慈悲地回答你");
	}
	else if (rand_line == 4) {
		my_cout("[武藏]：就算你沒有沒有誠心誠意地發問");
		my_cout("[小次郎]：我也會大發慈悲地回答你");
	}
	my_cout("[武藏]：為了防止世界被破壞");
	my_cout("[小次郎]：為了守護世界的和平");
	my_cout("[武藏]：貫徹愛與真實的邪惡");
	my_cout("[小次郎]：可愛又迷人的反派角色");
	my_cout("[武藏]：武藏！");
	my_cout("[小次郎]：小次郎！");
	my_cout("[武藏]：我們是穿梭在宇宙間的火箭隊二人組");
	my_cout("[小次郎]：白洞，白色的明天正等著我們");
	my_cout("[喵喵]：就是這樣喵~");
	if (current_mission == &missions[0][2]) {
		my_cout("\n\n  [HINT]\n  這裡可以與火箭隊對戰，寶可夢可獲得經驗值、提升戰鬥力。\n  每進行一次對戰，玩家與寶可夢的飢餓度、口渴度、體力及寶可夢的飢餓度、口渴度就會減少3。\n  稍後會再說明補充的方法。");
		cout << endl;
		current_mission = &missions[0][3];
	}
	my_cout("\n[開始與火箭隊對戰吧]");
	int rocket_pokemon; pokemon* assign[1];
	if (missions[5][3].get_complete() == true) {
		uniform_int_distribution<int> distribution2(0, 2);
		rocket_pokemon = distribution2(generator);
	}
	else {
		uniform_int_distribution<int> distribution2(0, 1);
		rocket_pokemon = distribution2(generator);
	}
	if (rocket_pokemon == 0) {
		assign[0] = &Inkay;
	}
	else if (rocket_pokemon == 1) {
		assign[0] = &Pumpkaboo;
	}
	else {
		assign[0] = &Wobbuffet;
	}
	bool win_or_loose = whole_battle(1, 1, &Rocket, assign);
	if (win_or_loose == true) {
		my_cout("[你已獲得獎勵：紅莓果*5，皮幣*100]");
		player.get_consumable(1)->add_num(5);
		player.set_money(100);
		player.set_thirsty(-3);
		player.set_hungry(-3);
		player.minus_tiredness(3);
	}
	else {
		my_cout("\n[再接再厲吧！]");
	}
	in_rocket_battle = false;
	main_menu();
}

void print_bag() {
	int choose_item = 0, num, who=1;
	bool use = true;
	cout << "\n[我的背包]";
	while (choose_item <= 13) {
		cout << "\n  物品名稱                       使用說明  持有數量\n";
		for (int i = 0; i < 12; i++) {
			cout << setw(2) << left << i + 1 << "." << setw(8) << right << player.get_consumable(i)->get_name() << setw(30) << right << player.get_consumable(i)->get_direction() << setw(9) << right << player.get_consumable(i)->get_numbers() << endl;
		}
		cout << "13.回到主頁\n";
		if (current_mission == &missions[0][3]) {
			cout << "\n    [HINT]\n    進入我的背包可察看你現在擁有的物品，並對玩家或寶可夢使用。\n";
			cout << "    [普拉塔諾博士]：我另外還幫你準備了2000皮幣與4顆寶貝球，現在在[個人檔案]也可以看到囉\n";
			cout << "    水壺最多可裝75格水\n    另外，若寶可夢受到城市屬性剋制，會使飢餓度與口渴度下降速度提高。使用中和劑可以解除這個屬性剋制，時效為通關一次主線劇情\n    現在先選擇 中和劑\n\n";
		}
		cout << "請選擇要使用的物品："; cin >> choose_item;
		if (choose_item == 13) {
			break;
		}
		else if (choose_item == 1) {//水
			while (who != 0) {
				cout << "\n現在選擇物品：水 數量：" << player.get_consumable(choose_item - 1)->get_numbers() << endl;
				cout << "   使用對象  口渴度\n";
				cout << "1.     玩家" << setw(5) << right << player.get_thirsty() << "/15\n";
				int i = 2;
				while (player.get_my_pokemon(i - 2) != NULL) {
					if (player.get_my_pokemon(i - 2)->get_catch() == true) {
						cout << i << "." << setw(9) << right << player.get_my_pokemon(i - 2)->get_name() << setw(5) << right << player.get_my_pokemon(i - 2)->get_thirsty() << "/15\n";
						i++;
					}
					else {
						break;
					}
				}
				cout << "0.回前一頁選擇使用物品";
				cout << "\n請輸入編號："; cin >> who;
				if (who == 0) {
					who = 1; break;
				}
				cout << "請輸入補水量（輸入1可補充1格口渴度，口渴度超過15會省略為15）："; cin >> num;
				use = player.get_consumable(choose_item - 1)->use_item(num);
				if (use == true) {
					if (who == 1) {
						player.set_thirsty(num);
					}
					else {
						player.get_my_pokemon(who - 2)->set_thirsty(num);
					}
				}
			}
		}
		else if (choose_item >= 2 && choose_item <= 4) {//莓果
			while (who != 0) {
				cout << "\n現在選擇物品：" << player.get_consumable(choose_item - 1)->get_name() << " 數量：" << player.get_consumable(choose_item - 1)->get_numbers() << endl;
				cout << "     寶可夢  飢餓度\n";
				int i = 1;
				while (player.get_my_pokemon(i - 1) != NULL) {
					if (player.get_my_pokemon(i - 1)->get_catch() == true) {
						cout << i << "." << setw(9) << right << player.get_my_pokemon(i - 1)->get_name() << setw(5) << right << player.get_my_pokemon(i - 1)->get_hungry() << "/15\n";
						i++;
					}
					else {
						break;
					}
				}
				cout << "0.回前一頁選擇使用物品";
				cout << "\n請輸入需要進食的寶可夢編號："; cin >> who;
				if (who == 0) {
					who = 1; break;
				}
				cout << "請輸入數量（飢餓度超過15會省略為15）："; cin >> num;
				use = player.get_consumable(choose_item - 1)->use_item(num);
				if (use == true) {
					player.get_my_pokemon(who - 1)->set_hungry(player.get_consumable(choose_item - 1)->get_effective() * num);
				}
			}
		}
		else if (choose_item >= 5 && choose_item <= 7) {//人類糧食
			num = 1;
			while (num != 0) {
				cout << "\n現在選擇物品：" << player.get_consumable(choose_item - 1)->get_name() << " 數量：" << player.get_consumable(choose_item - 1)->get_numbers() << endl;
				cout << "玩家飢餓度：" << player.get_hungry() << "/15\n請輸入使用數量(輸入0可回到前一頁選擇使用物品)："; 
				cin >> num;
				use = player.get_consumable(choose_item - 1)->use_item(num);
				if (use == true) {
					player.set_hungry(player.get_consumable(choose_item - 1)->get_effective() * num);
				}
			}
		}
		else if (choose_item >= 8 && choose_item <= 10) {//傷藥
			while (who != 0) {
				cout << "\n現在選擇物品：" << player.get_consumable(choose_item - 1)->get_name() << " 數量：" << player.get_consumable(choose_item - 1)->get_numbers() << endl;
				cout << "     寶可夢        HP\n";
				int i = 1;
				while (player.get_my_pokemon(i - 1) != NULL) {
					if (player.get_my_pokemon(i - 1)->get_catch() == true) {
						cout << i << "." << setw(9) << right << player.get_my_pokemon(i - 1)->get_name() << setw(6) << right << player.get_my_pokemon(i - 1)->get_HP() << "/" << setw(3) << player.get_my_pokemon(i - 1)->get_max_HP() << endl;
						i++;
					}
					else {
						break;
					}
				}
				cout << "0.回前一頁選擇使用物品";
				cout << "\n請輸入需要補HP的寶可夢編號："; cin >> who;
				if (who == 0) {
					who = 1; break;
				}
				cout << "請輸入數量（HP超過最大值會省略）："; cin >> num;
				use = player.get_consumable(choose_item - 1)->use_item(num);
				if (use == true) {
					player.get_my_pokemon(who - 1)->set_HP(player.get_consumable(choose_item - 1)->get_effective() * num);
				}
			}
		}
		else if (choose_item == 11) {//中和藥
			while (who != 0) {
				cout << "\n現在選擇物品：" << player.get_consumable(choose_item - 1)->get_name() << " 數量：" << player.get_consumable(choose_item - 1)->get_numbers() << endl;
				cout << "     寶可夢  受地區屬性剋制？\n";
				int i = 1;
				while (player.get_my_pokemon(i - 1) != NULL) {
					if (player.get_my_pokemon(i - 1)->get_catch() == true) {
						cout << i << "." << setw(9) << right << player.get_my_pokemon(i - 1)->get_name() << "              ";
						if (player.get_my_pokemon(i - 1)->get_poison() == true) {
							cout << "是\n";
						}
						else {
							cout << "否\n";
						}
						i++;
					}
					else {
						break;
					}
				}
				cout << "0.回前一頁選擇使用物品\n";
				if (current_mission == &missions[0][3]) {
					cout << "\n先選擇皮卡丘吧！\n";
					current_mission = &missions[0][4];
				}
				cout << "\n請輸入需要使用中和劑的寶可夢編號："; cin >> who;
				if (who == 0) {
					who = 1; break;
				}
				else if (player.get_my_pokemon(who - 1)->get_poison() == false) {
					cout << "無法對這隻寶可夢使用\n\n";
				}
				else {
					use = player.get_consumable(choose_item - 1)->use_item(1);
					player.get_my_pokemon(who - 1)->set_poison(false);
				}
			}
		}
		else if (choose_item == 12) {
			cout << "帳篷無法在此處使用";
		}
	}
	main_menu();
}

void print_my_my_pokemon() {
	cout << "\n[我的寶可夢]\n";
	if (current_mission == &missions[1][0]) {
		cout << "\n    [HINT]\n    這裡可以查看現有的寶可夢數值\n\n";
		current_mission = &missions[1][1];
	}
	int i = 0;
	while (player.get_my_pokemon(i) != NULL) {
		if (player.get_my_pokemon(i)->get_catch() == true) {
			cout << i + 1 << "." << player.get_my_pokemon(i)->get_name() << "(";
			player.get_my_pokemon(i)->print_attribute();
			cout << ")\n  等級：" << player.get_my_pokemon(i)->get_level() << "/" << player.get_my_pokemon(i)->get_max_level() << "  經驗值：" << player.get_my_pokemon(i)->get_experience() << "/50\n";
			cout << "  飢餓度：" << player.get_my_pokemon(i)->get_hungry() << "/15  口渴度：" << player.get_my_pokemon(i)->get_thirsty() << "/15  HP：" << player.get_my_pokemon(i)->get_HP() << "/" << player.get_my_pokemon(i)->get_max_HP() << endl;
			for (int o = 0; o < player.get_my_pokemon(i)->get_trick_num(); o++) {
				if (player.get_my_pokemon(i)->get_trick(o)->get_bigORsmall() == 0) {
					cout << "  大招：" << setw(8) << right << player.get_my_pokemon(i)->get_trick(o)->get_name() << "：" << setw(7) << left << attribute_list[player.get_my_pokemon(i)->get_trick(o)->get_attribute()] << "攻擊力：" << player.get_my_pokemon(i)->get_trick(o)->get_attack() << endl;
				}
				else if (player.get_my_pokemon(i)->get_trick(o)->get_bigORsmall() == 1) {
					cout << "  小招：" << setw(8) << right << player.get_my_pokemon(i)->get_trick(o)->get_name() << "：" << setw(7) << left << attribute_list[player.get_my_pokemon(i)->get_trick(o)->get_attribute()] << "攻擊力：" << player.get_my_pokemon(i)->get_trick(o)->get_attack() << endl;
				}
			}
			i++;
		}
		else {
			break;
		}
	}
	cin.ignore();
	my_cout("\nenter to comtinue");
	main_menu();
}

void print_conflict_table() {
	cout << "\n[屬性剋制表]\n";
	cout << "左邊是攻擊招式的屬性，上面是接招寶可夢的屬性\n";
	cout << "　　　 　一般 　　火 　　水 　　電 　　草 　　冰 　格鬥 　　毒 　地面 　飛行 超能力 　　蟲 　岩石 　幽靈 　　龍 　　惡 　　鋼 　妖精\n";
	cout << "  一般     --     --     --     --     --     --     --     --     --     --     --     --    Bad    Bad     --     --    Bad     --\n";
	cout << "    火     --    Bad    Bad     --   Good   Good     --     --     --     --     --   Good    Bad     --    Bad     --   Good     --\n";
	cout << "    水     --   Good    Bad     --    Bad     --     --     --   Good     --     --     --   Good     --    Bad     --     --     --\n";
	cout << "    電     --     --   Good    Bad    Bad     --     --     --    Bad   Good     --     --     --     --    Bad     --     --     --\n";
	cout << "    草     --    Bad   Good     --    Bad     --     --    Bad   Good    Bad     --    Bad   Good     --    Bad     --    Bad     --\n";
	cout << "    冰     --    Bad    Bad     --   Good    Bad     --     --   Good   Good     --     --     --     --   Good     --    Bad     --\n";
	cout << "  格鬥   Good     --     --     --     --   Good     --    Bad     --    Bad    Bad    Bad   Good    Bad     --   Good   Good    Bad\n";
	cout << "    毒     --     --     --     --   Good     --     --    Bad    Bad     --     --     --    Bad    Bad     --     --    Bad   Good\n";
	cout << "  地面     --   Good     --   Good    Bad     --     --   Good     --     --     --    Bad   Good     --     --     --   Good     --\n";
	cout << "  飛行     --     --     --    Bad   Good     --   Good     --     --     --     --   Good    Bad     --     --     --    Bad     --\n";
	cout << "超能力     --     --     --     --     --     --   Good   Good     --     --    Bad     --     --     --     --    Bad    Bad     --\n";
	cout << "    蟲     --    Bad     --     --   Good     --    Bad    Bad     --    Bad   Good     --     --    Bad     --   Good    Bad    Bad\n";
	cout << "  岩石     --   Good     --     --     --   Good    Bad     --    Bad   Good     --   Good     --     --     --     --    Bad     --\n";
	cout << "  幽靈    Bad     --     --     --     --     --     --     --     --     --   Good     --     --   Good     --    Bad     --     --\n";
	cout << "    龍     --     --     --     --     --     --     --     --     --     --     --     --     --     --   Good     --    Bad    Bad\n";
	cout << "    惡     --     --     --     --     --     --    Bad     --     --     --   Good     --     --   Good     --    Bad     --    Bad\n";
	cout << "    鋼     --    Bad    Bad    Bad     --   Good     --     --     --     --     --     --   Good     --     --     --    Bad   Good\n";
	cout << "  妖精     --    Bad     --     --     --     --   Good    Bad     --     --     --     --     --     --   Good   Good    Bad     --\n";
	cin.ignore();
	my_cout("\nenter to comtinue");
	main_menu();
}

void enter_mission(int a, int b) {
	while (&missions[a][b] == current_mission) {
		if (missions[a][b].get_spot() == current_spot) {
			int enter_choose = 0;
			cout << "是否開始任務？（1：是，2：否）\n請輸入你的選擇：";
			cin >> enter_choose;
			if (enter_choose == 1) {
				break;
			}
		}
		main_menu();
	}
}

void confirm_land_conflict() {//確認地域受剋性
	int i = 0;
	while (player.get_my_pokemon(i) != NULL) {
		if (player.get_my_pokemon(i)->get_catch() == true) {
			double conflict = 1;
			for (int j = 0; j < player.get_my_pokemon(i)->get_attribute_num(); j++) {
				conflict *= attribute_conflict_table[*player.get_my_pokemon(i)->get_attribute(j)][current_city->get_attribute()];
			}
			if (conflict < 1) {
				player.get_my_pokemon(i)->set_poison(true);
			}
			else {
				player.get_my_pokemon(i)->set_poison(false);
			}
			i++;
		}
		else {
			break;
		}
	}
}

void minus_health() {
	player.minus_tiredness(5);
	player.set_thirsty(-5);
	player.set_hungry(-5);
	int i = 0;
	while (player.get_my_pokemon(i) != NULL) {
		if (player.get_my_pokemon(i)->get_catch() == true) {
			player.get_my_pokemon(i)->add_experience(20);
			if (player.get_my_pokemon(i)->get_poison() == true) {
				player.get_my_pokemon(i)->set_hungry(-7);
				player.get_my_pokemon(i)->set_thirsty(-7);
			}
			else {
				player.get_my_pokemon(i)->set_hungry(-5);
				player.get_my_pokemon(i)->set_thirsty(-5);
			}
			i++;
		}
		else {
			break;
		}
	}
}