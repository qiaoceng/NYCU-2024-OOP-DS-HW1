+#include "header.h"
#include <iostream>
#include <cstdlib>

using namespace std;

mission missions[9][5];

void build_mission_list() {
	missions[0][0].set_mission("1-1 啟程 卡洛斯聯盟", "選擇地圖，前往密阿雷市>>稜鏡塔", &cities[0], cities[0].get_spot(1));
	missions[0][1].set_mission("1-2 對戰 希特隆與掘掘兔", "選擇地圖，前往密阿雷市>>稜鏡塔", &cities[0], cities[0].get_spot(1));
	missions[0][2].set_mission("1-3 R是Rocket的意思", "選擇地圖，前往密阿雷市>>稜鏡塔", &cities[0], cities[0].get_spot(1));
	missions[0][3].set_mission("1-4 mega進化 普拉塔諾博士與烈咬陸鯊", "選擇地圖，前往密阿雷市>>普拉塔諾博士研究所", &cities[0], cities[0].get_spot(2));
	missions[0][4].set_mission("1-5 挑戰開始 前進白檀市", "選擇地圖，前往密阿雷市>>普拉塔諾博士研究所", &cities[0], cities[0].get_spot(2));
	missions[1][0].set_mission("2-1 呱呱泡蛙與小箭雀", "選擇地圖，前往白檀市>>四號道路森林", &cities[1], cities[1].get_spot(0));
	missions[1][1].set_mission("2-2 挑戰白檀道館 溜溜糖球與彩粉蝶", "選擇地圖，前往白檀市>>白檀道館（建議先將寶可夢的HP補滿以應對接下來的道館戰！）", &cities[1], cities[1].get_spot(1));
	missions[1][2].set_mission("2-3 密阿雷道館館主", "選擇地圖，前往密阿雷市>>稜鏡塔", &cities[0], cities[0].get_spot(1));
	missions[1][3].set_mission("2-4 挑戰遙香道館 封印岩石封鎖", "選擇地圖，前往遙香市>>遙香道館（建議先將寶可夢的HP補滿以應對接下來的道館戰！）", &cities[2], cities[2].get_spot(0));
	missions[2][0].set_mission("3-1 森林之王", "選擇地圖，前往遙香市>>十一號道路森林（建議先將寶可夢的HP補滿！）", &cities[2], cities[2].get_spot(1));
	missions[2][1].set_mission("3-2 誰能制霸空中？ 小箭雀與烈箭鷹", "選擇地圖，前往娑羅市>>空中飛人訓練中心（建議先將寶可夢的HP補滿！）", &cities[3], cities[3].get_spot(0));
	missions[2][2].set_mission("3-3 挑戰格鬥道館 mega路卡利歐", "選擇地圖，前往娑羅市>>精煉之塔（建議先將寶可夢的HP補滿以應對接下來的道館戰！）", &cities[3], cities[3].get_spot(1));
	missions[2][3].set_mission("3-4 河上飄來一名忍者？！ 三平與甲賀忍蛙", "選擇地圖，前往娑羅市>>十二號道路森林（建議先將寶可夢的HP補滿！）", &cities[3], cities[3].get_spot(2));
	missions[2][4].set_mission("3-5 忍術對決 呱呱泡蛙與龜足巨鎧", "選擇地圖，前往娑羅市>>十二號道路森林（建議先將寶可夢的HP補滿！）", &cities[3], cities[3].get_spot(2));
	missions[3][0].set_mission("4-1 從天而降的龍？", "選擇地圖，前往娑羅市>>十二號道路湖畔", &cities[3], cities[3].get_spot(3));
	missions[3][1].set_mission("4-2 荒野決鬥 戰鬥吧，黏黏寶", "選擇地圖，前往比翼市>>十二號道路荒原（建議先將寶可夢的HP補滿！）", &cities[4], cities[4].get_spot(1));
	missions[3][2].set_mission("4-3 挑戰比翼道館 細枝末節之處", "選擇地圖，前往比翼市>>比翼道館（建議先將寶可夢的HP補滿以應對接下來的道館戰！）", &cities[4], cities[4].get_spot(0));
	missions[3][3].set_mission("4-4 黏美兒會加油！", "選擇地圖，前往比翼市>>十三號道路森林", &cities[4], cities[4].get_spot(2));
	missions[4][0].set_mission("5-1 回到原點 挑戰密阿雷道館", "選擇地圖，前往密阿雷市>>稜鏡塔（建議先將寶可夢的HP補滿以應對接下來的道館戰！）", &cities[0], cities[0].get_spot(1));
	missions[4][1].set_mission("5-2 初遇翔太 三回合宿敵對戰", "選擇地圖，前往香薰市>>瑪秀的服裝店（建議先將寶可夢的HP補滿！）", &cities[5], cities[5].get_spot(1));
	missions[4][2].set_mission("5-3 挑戰香薰道館 美麗妖精的陷阱", "選擇地圖，前往香薰市>>香薰道館（建議先將寶可夢的HP補滿以應對接下來的道館戰！）", &cities[5], cities[5].get_spot(0));
	missions[4][3].set_mission("5-4 蛋裡的baby", "選擇地圖，前往香薰市>>十五號道路森林", &cities[5], cities[5].get_spot(2));
	missions[5][0].set_mission("6-1 千年一遇的赤紅傳奇 火箭雀vs火焰鳥", "選擇地圖，前往百刻市>>阿多爾山（建議先將寶可夢的HP補滿！）", &cities[6], cities[6].get_spot(0));
	missions[5][1].set_mission("6-2 挑戰百刻道館 精神力量的對決", "選擇地圖，前往百刻市>>百刻道館（建議先將寶可夢的HP補滿以應對接下來的道館戰！）", &cities[6], cities[6].get_spot(1));
	missions[5][2].set_mission("6-3 歡迎來到忍者村", "選擇地圖，前往百刻市>>忍者村（建議先將寶可夢的HP補滿！）", &cities[6], cities[6].get_spot(2));
	missions[5][3].set_mission("6-4 最終對決 你的甲賀忍蛙", "選擇地圖，前往百刻市>>忍者村（建議先將寶可夢的HP補滿！）", &cities[6], cities[6].get_spot(2));
	missions[6][0].set_mission("7-1 相同的呼吸 翔太的蜥蜴王", "選擇地圖，前往百刻市>>十八號道路森林（建議先將寶可夢的HP補滿！）", &cities[6], cities[6].get_spot(3));
	missions[6][1].set_mission("7-2 mega對決 超級噴火龍", "選擇地圖，前往百刻市>>十八號道路森林（建議先將寶可夢的HP補滿！）", &cities[6], cities[6].get_spot(3));
	missions[6][2].set_mission("7-3 憤怒的雷擊 閃電鳥與嗡蝠", "選擇地圖，前往百刻市>>十八號道路森林（建議先將寶可夢的HP補滿！）", &cities[6], cities[6].get_spot(3));
	missions[6][3].set_mission("7-4 再遇艾嵐", "選擇地圖，前往映雪市>>廢棄小木屋（建議先將寶可夢的HP補滿！）", &cities[7], cities[7].get_spot(1));
	missions[6][4].set_mission("7-5 二次對決 甲賀忍蛙與mega噴火龍", "選擇地圖，前往映雪市>>廢棄小木屋（建議先將寶可夢的HP補滿！）", &cities[7], cities[7].get_spot(1));
	missions[7][0].set_mission("8-1 宿敵的對決3", "選擇地圖，前往映雪市>>映雪道館（建議先將寶可夢的HP補滿！）", &cities[7], cities[7].get_spot(0));
	missions[7][1].set_mission("8-2 一場不尋常的對戰", "選擇地圖，前往映雪市>>映雪道館（建議先將寶可夢的HP補滿以應對接下來的道館戰！）", &cities[7], cities[7].get_spot(0));
	missions[7][2].set_mission("8-3 迷幻森林 進化的黎明", "選擇地圖，前往映雪市>>森林南側山洞", &cities[7], cities[7].get_spot(2));
	missions[7][3].set_mission("8-4 發動巨型水手裡箭 對決超級暴雪王", "選擇地圖，前往映雪市>>映雪道館（建議先將寶可夢的HP補滿以應對接下來的道館戰！）", &cities[7], cities[7].get_spot(0));
	missions[8][0].set_mission("9-1 卡洛斯聯盟 開戰", "選擇地圖，前往密阿雷市>>稜鏡塔（建議先將寶可夢的HP補滿以應對接下來的聯盟戰！）", &cities[0], cities[0].get_spot(1));
	missions[8][1].set_mission("9-2 最強挑戰者 勁敵對決", "選擇地圖，前往密阿雷市>>稜鏡塔（建議先將寶可夢的HP補滿以應對接下來的聯盟戰！）", &cities[0], cities[0].get_spot(1));
	missions[8][2].set_mission("9-3 水火不容 最後的誓言之戰", "選擇地圖，前往密阿雷市>>稜鏡塔（建議先將寶可夢的HP補滿以應對接下來的聯盟戰！）", &cities[0], cities[0].get_spot(1));
}

void mission::set_mission(string name, string allert, city* city_, spot* spot_) {
	mission::name = name, mission::allert = allert;
	start = false, complete = false;
	the_city = city_, the_spot = spot_;
}
void mission::set_start(bool start_) {
	start = start_;
}
void mission::set_complete(bool completed) {
	complete = completed;
}
city* mission::get_city() {
	return the_city;
}
spot* mission::get_spot() {
	return the_spot;
}
bool mission::get_start() {
	return start;
}
bool mission::get_complete() {
	return complete;
}
string mission::get_name() {
	return name;
}
string mission::get_allert() {
	return allert;
}