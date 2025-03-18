#include "header.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <thread>

using namespace std;

city cities[8];

void build_city() {
	cities[0].set_city("密阿雷市", "電系城市", 5, 3);
	cities[0].add_spots(1, "密阿雷機場");
	cities[0].add_spots(1, "稜鏡塔");
	cities[0].add_spots(1, "普拉塔諾博士研究所");
	cities[0].add_spots(3, "中央廣場");
	cities[0].add_spots(4, "寶可夢中心");

	cities[1].set_city("白檀市", "蟲系城市", 5, 11);
	cities[1].add_spots(1, "四號道路森林");//收服小箭雀
	cities[1].add_spots(1, "白檀道館");
	cities[1].add_spots(2, "古木森林", "你與你的寶可夢在森林裡遇見了哲爾尼亞斯", 40);
	cities[1].add_spots(3, "毒薔薇雕像的噴泉");
	cities[1].add_spots(4, "寶可夢中心");

	cities[2].set_city("遙香市", "岩石系城市", 5, 12);
	cities[2].add_spots(1, "遙香道館");
	cities[2].add_spots(1, "十一號道路森林");//收服摔跤鷹人
	cities[2].add_spots(2, "高岩山", "你與你的寶可夢在山頂上一起看了月全食", 20);
	cities[2].add_spots(3, "岩石瀑布");
	cities[2].add_spots(4, "寶可夢中心");

	cities[3].set_city("娑羅市", "格鬥系城市", 6, 6);
	cities[3].add_spots(1, "空中飛人訓練中心");//小箭雀進化
	cities[3].add_spots(1, "精煉之塔");
	cities[3].add_spots(1, "十二號道路森林");//呱呱泡蛙進化
	cities[3].add_spots(1, "十二號道路湖畔");//收服黏黏寶
	cities[3].add_spots(3, "島中小湖");
	cities[3].add_spots(4, "寶可夢中心");

	cities[4].set_city("比翼市", "草系城市", 5, 4);
	cities[4].add_spots(1, "比翼道館");
	cities[4].add_spots(1, "十二號道路荒原");//黏黏寶進化
	cities[4].add_spots(1, "十三號道路森林");//黏美兒進化
	cities[4].add_spots(2, "山頂懸崖", "你與你的寶可夢在懸崖邊的海上看到比翼市著名的藍眼淚", 20);
	cities[4].add_spots(4, "寶可夢中心");

	cities[5].set_city("香薰市", "妖精系城市", 6, 17);
	cities[5].add_spots(1, "香薰道館");
	cities[5].add_spots(1, "瑪秀的服裝店");//翔太對戰1
	cities[5].add_spots(1, "十五號道路森林");//捕獲嗡蝠
	cities[5].add_spots(2, "古老的大樹", "你與你的寶可夢一起欣賞了百年難得的流星雨", 30);
	cities[5].add_spots(3, "老水井");
	cities[5].add_spots(4, "寶可夢中心");

	cities[6].set_city("百刻市", "超能力系城市", 6, 10);
	cities[6].add_spots(1, "阿多爾山");//火箭雀進化
	cities[6].add_spots(1, "百刻道館");
	cities[6].add_spots(1, "忍者村");//呱頭蛙進化
	cities[6].add_spots(1, "十八號道路森林");//翔太對戰2，對戰艾嵐1，嗡蝠進化
	cities[6].add_spots(2, "尖塔露營區", "你與你的寶可夢在露營區認識了許多訓練家與寶可夢，並與他們成為朋友", 20);
	cities[6].add_spots(4, "寶可夢中心");

	cities[7].set_city("映雪市", "冰系城市", 5, 5);
	cities[7].add_spots(1, "映雪道館");
	cities[7].add_spots(1, "廢棄小木屋");//對戰艾嵐2，翔太對戰3
	cities[7].add_spots(1, "森林南側山洞");
	cities[7].add_spots(3, "森林北側冰河");
	cities[7].add_spots(4, "寶可夢中心");
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
	cout << "[這是一個適合野營的地方。]\n";
	if (my_tent.get_numbers() == 0) {
		cout << "[你目前無法野營。請購買帳篷]\n";
	}
	else {
		cout << "是否要在此處野營？\n請輸入你的選擇：(1：是，2：否)";
		cin >> choose_to_camp;
		if (choose_to_camp == 1) {
			cout << "請在此處休息20秒";
			this_thread::sleep_for(chrono::seconds(20));
			player.fill_tiredness();
			player.set_hungry(-3);
			int i = 0;
			cout << endl;
			if (my_pokemon_experience != 0) {
				cout << "[" << event << "，寶可夢經驗值上升" << my_pokemon_experience << "]";
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
			my_cout("你與你的寶可夢現在都精神滿滿！請繼續旅程");
		}
	}
	main_menu();
}

water_land::water_land(string name, int catogory_) {
	set_name(name); set_catogory(catogory_);
}
void water_land::things_to_do() {
	int choose_to_fillwater;
	cout << "[這裡有好多泉水。你可以把背包裡的水補滿]\n是否要在此處補水？\n請輸入你的選擇(1：是，2：否)：";
	cin >> choose_to_fillwater;
	if (choose_to_fillwater == 1) {
		bottle.fill_water();
		my_cout("水已經補滿了");
	}
	cout << endl;
	main_menu();
}

pokemon_center::pokemon_center(string name, int catogory_) {
	set_name(name); set_catogory(catogory_);
}
void pokemon_center::things_to_do() {
	int choose_service;
	cout << "\n[喬伊小姐]：歡迎來到 " << current_city->get_name() << " 的寶可夢中心。請問需要什麼協助呢？\n";
	if (current_mission == &missions[0][4]) {
		cout << "\n    [HINT]\n    每個城市都有寶可夢中心，提供訓練家休息、購買物品、治療寶可夢等服務。\n    你的體力值已歸零，請先選擇 1.住宿一晚\n\n";
	}
	cout << "1.住宿一晚（皮幣150元）\n2.恢復寶可夢HP（皮幣200元）\n3.購買物品\n4.回到主選單\n請輸入你的選擇：";
	cin >> choose_service;
	if (choose_service == 1) {
		player.set_money(-150);
		cout << "\n[喬伊小姐]：請在此處休息20秒";
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
		my_cout("\n[喬伊小姐]：你與你的寶可夢現在都精神滿滿！請繼續旅程");
		if (current_mission == &missions[0][4]) {
			my_cout("\n    [HINT]\n    每次補充體力，玩家與寶可夢的飢餓度都會下降。如有必要請記得另外去補充飢餓度。\n    另外，除了寶可夢中心可以補充備品、提供住處，各個城市也有地方可以免費補充水分或野營。\n    順帶一提，雖然野營需要自備帳篷（可在寶可夢中心購買），但也可能遇到一些偶發事件、可提升寶可夢的經驗值喔！試著去探索看看吧");
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
		my_cout("\n[喬伊小姐]：你的寶可夢都恢復健康了！請繼續旅程");
		pokemon_center::things_to_do();
	}
	else if (choose_service == 3) {
		int choose_item = 0, number;
		cout << "\n商店販賣物品如下：\n";
		cout << "       品項名稱                      商品說明    持有數量    價格\n";
		for (int i = 0; i < 12; i++) {
			cout << setw(2) << i + 1 << "." << setw(12) << player.get_consumable(i)->get_name() << setw(30) << player.get_consumable(i)->get_direction() << setw(12) << player.get_consumable(i)->get_numbers() << setw(8) << player.get_consumable(i)->get_price() << endl;
		}
		cout << "13.    離開商店\n";
		while (choose_item != 13) {
			cout << "\n你擁有的皮幣：" << player.get_money() << endl;
			cout << "請輸入你要購買的物品：";
			cin >> choose_item;
			if (choose_item == 13) {
				break;
			}
			cout << "請輸入購買數量：";
			cin >> number;
			player.get_consumable(choose_item - 1)->add_num(number);
			player.set_money(-player.get_consumable(choose_item - 1)->get_price() * number);
			cout << "你已獲得 " << player.get_consumable(choose_item - 1)->get_name() << " " << player.get_consumable(choose_item - 1)->get_numbers() << " 個\n";
			cout << "是否繼續購物？(是:1，否:2)"; cin >> choose_item;
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
	//1:main，2:camp，3:water，4:center
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