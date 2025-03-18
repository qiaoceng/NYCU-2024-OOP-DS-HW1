#include "header.h"
#include <iostream>
#include <vector>

using namespace std;

my_pokemon Pikachu = my_pokemon("皮卡丘", 500, 10, false, 4, 9);
my_pokemon Froakie = my_pokemon("呱呱泡蛙", 100, 5, false, 2, 7); my_pokemon Frogadier = my_pokemon("呱頭蛙", 250, 10, false, 3, 8); my_pokemon Greninja = my_pokemon("甲賀忍蛙", 500, 10, false, 4, 9);
my_pokemon Fletchling = my_pokemon("小箭雀", 100, 5, false, 2, 7); my_pokemon Fletchinder = my_pokemon("火箭雀", 250, 10, false, 3, 8); my_pokemon Talonflame = my_pokemon("烈箭鷹", 500, 10, false, 4, 9);
my_pokemon Hawlucha = my_pokemon("摔跤鷹人", 250, 20, false, 3, 8);
my_pokemon Goomy = my_pokemon("黏黏寶", 100, 5, false, 2, 7); my_pokemon Sliggoo = my_pokemon("黏美兒", 250, 10, false, 3, 8); my_pokemon Goodra = my_pokemon("黏美露龍", 500, 10, false, 4, 9);
my_pokemon Noibat = my_pokemon("嗡蝠", 100, 5, false, 2, 7); my_pokemon Noivern = my_pokemon("音波龍", 250, 20, false, 3, 8);

trainer Viola = trainer("碧歐拉"); pokemon Surskit = pokemon("溜溜糖球", 200, false); pokemon Vivillon = pokemon("彩粉蝶", 600, false);
trainer Chakra = trainer("查克拉"); pokemon Onix = pokemon("大岩蛇", 400, false); pokemon Tyrunt = pokemon("寶寶暴龍", 200, false);
trainer Korrina = trainer("可爾妮");  pokemon Mienfoo = pokemon("功夫鼬", 200, false);  pokemon Machoke = pokemon("豪力", 300, false);  pokemon Lucario= pokemon("路卡利歐", 590, true);
trainer Ramos = trainer("福爺");  pokemon Jumpluff = pokemon("毽子棉", 600, false);  pokemon Weepinbell = pokemon("口呆花", 330, false);  pokemon Gogoat = pokemon("坐騎山羊", 650, false);
trainer Clemont = trainer("希特隆"); pokemon Bunnelby = pokemon("掘掘兔", 100, false); pokemon Heliolisk = pokemon("光電傘蜥", 390, false); pokemon Luxray = pokemon("倫琴貓", 610, false);
trainer Valerie = trainer("瑪秀");  pokemon Spritzee = pokemon("粉香香", 230, false);  pokemon Sylveon = pokemon("仙子伊布", 430, false);
trainer Olympia = trainer("午時花"); pokemon female_Meowstic = pokemon("母超能妙喵", 500, false); pokemon male_Meowstic = pokemon("公超能妙喵", 500, false);
trainer Wulfric= trainer("德撫"); pokemon Abomasnow = pokemon("暴雪王", 680, true); pokemon Avalugg = pokemon("冰岩怪", 480, false); pokemon Bergmite = pokemon("冰寶", 200, false);

trainer Rocket = trainer("火箭隊"); pokemon Inkay = pokemon("栗烏賊", 150, false); pokemon Pumpkaboo = pokemon("南瓜精", 180, false); pokemon Wobbuffet = pokemon("果然翁", 400, false);
trainer Nami = trainer("娜米"); pokemon Nami_Talonflame = pokemon("烈箭鷹", 500, false);
trainer Saizo = trainer("狡猾天狗假面"); pokemon Barbaracle = pokemon("龜足巨鎧", 300, false);
trainer Heidayu = trainer("蒙面人"); pokemon Heidayu_Bisharp = pokemon("劈斬司令", 500, false);
trainer Ahe = trainer("阿朋"); pokemon Altaria = pokemon("七夕青鳥", 500, false);
trainer Alain = trainer("艾嵐"); pokemon Tyranitar = pokemon("班基拉斯", 630, false); pokemon Weavile = pokemon("瑪狃拉", 580, false); pokemon Bisharp = pokemon("劈斬司令", 600, false); pokemon Unfezant = pokemon("高傲雉雞", 550, false); pokemon Metagross = pokemon("巨金怪", 640, false); pokemon Charizard = pokemon("噴火龍", 690, true);
trainer Sawyer = trainer("翔太"); pokemon Treecko = pokemon("木守宮", 150, false);   pokemon Sceptile = pokemon("蜥蜴王", 550, false); pokemon Slurpuff = pokemon("胖甜妮", 250, false);
pokemon Bagon = pokemon("寶貝龍", 150, false); pokemon Shelgon = pokemon("甲殼龍", 400, false); pokemon Salamence = pokemon("暴飛龍", 650, false); pokemon Clawitzer = pokemon("鋼炮臂蝦", 500, false);
pokemon Honedge = pokemon("獨劍鞘", 150, false); pokemon Doublade = pokemon("雙劍鞘", 350, false); pokemon Aegislash = pokemon("堅盾劍怪", 600, false); pokemon Slaking = pokemon("請假王", 700, false);

pokemon Grumpig = pokemon("噗噗豬", 250, false); pokemon Moltres = pokemon("火焰鳥", 10000, false); 

string attribute_list[18] = { "一般","火","水","電","草","冰","格鬥","毒","地面","飛行","超能力","蟲","岩石","幽靈","龍","惡","鋼","妖精" };
//0:一般  1:火  2:水  3:電  4:草  5:冰  6:格鬥  7:毒  8:地面  9:飛行
//10:超能力  11:蟲  12:岩石  13:幽靈  14:龍  15:惡  16:鋼  17:妖精

double attribute_conflict_table[18][18] = {
	  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,0.8,0.5,  1,  1,0.8,  1,
	  1,0.8,0.8,  1,1.2,1.2,  1,  1,  1,  1,  1,1.2,0.8,  1,0.8,  1,1.2,  1,
	  1,1.2,0.8,  1,0.8,  1,  1,  1,1.2,  1,  1,  1,1.2,  1,0.8,  1,  1,  1,
	  1,  1,1.2,0.8,0.8,  1,  1,  1,0.5,1.2,  1,  1,  1,  1,0.8,  1,  1,  1,
	  1,0.8,1.2,  1,0.8,  1,  1,0.8,1.2,0.8,  1,0.8,1.2,  1,0.8,  1,0.8,  1,
	  1,0.8,0.8,  1,1.2,0.8,  1,  1,1.2,1.2,  1,  1,  1,  1,1.2,  1,0.8,  1,
	1.2,  1,  1,  1,  1,1.2,  1,0.8,  1,0.8,0.8,0.8,1.2,0.5,  1,1.2,1.2,0.8,
	  1,  1,  1,  1,1.2,  1,  1,0.8,0.8,  1,  1,  1,0.8,0.8,  1,  1,0.5,1.2,
	  1,1.2,  1,1.2,0.8,  1,  1,1.2,  1,0.5,  1,0.8,1.2,  1,  1,  1,1.2,  1,
	  1,  1,  1,0.8,1.2,  1,1.2,  1,  1,  1,  1,1.2,0.8,  1,  1,  1,0.8,  1,
	  1,  1,  1,  1,  1,  1,1.2,1.2,  1,  1,0.8,  1,  1,  1,  1,0.5,0.8,  1,
	  1,0.8,  1,  1,1.2,  1,0.8,0.8,  1,0.8,1.2,  1,  1,0.8,  1,1.2,0.8,0.8,
	  1,1.2,  1,  1,  1,1.2,0.8,  1,0.8,1.2,  1,1.2,  1,  1,  1,  1,0.8,  1,
	0.5,  1,  1,  1,  1,  1,  1,  1,  1,  1,1.2,  1,  1,1.2,  1,0.8,  1,  1,
	  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,1.2,  1,0.8,0.5,
	  1,  1,  1,  1,  1,  1,0.8,  1,  1,  1,1.2,  1,  1,1.2,  1,0.8,  1,0.8,
	  1,0.8,0.8,0.8,  1,1.2,  1,  1,  1,  1,  1,  1,1.2,  1,  1,  1,0.8,1.2,
	  1,0.8,  1,  1,  1,  1,1.2,0.8,  1,  1,  1,  1,  1,  1,1.2,1.2,0.8,  1
};

void build_player_my_pokemon() {
	Pikachu.add_attribute(3); Pikachu.be_catched(true);
	Pikachu.add_trick(trick("鐵尾", 16, 45, 1)); Pikachu.add_trick(trick("電球", 3, 47, 1));
	Pikachu.add_trick(trick("十萬伏特", 3, 135, 0)); Pikachu.add_trick(trick("電光一閃", 3, 120, 0));
	player.set_my_pokemon_ptr(&Pikachu);

	Froakie.add_attribute(2);
	Froakie.add_trick(trick("泡沫", 2, 8, 1)); Froakie.add_trick(trick("影分身", 0, 10, 1)); 
	Froakie.add_trick(trick("水之波動", 2, 27, 0)); Froakie.add_trick(trick("拍擊", 0, 25, 0));
	Pikachu.set_next_ptr(&Froakie);

	Frogadier.add_attribute(2);
	Frogadier.add_trick(trick("居合斬", 0, 27, 1)); Frogadier.add_trick(trick("泡沫", 2, 23, 1));
	Frogadier.add_trick(trick("水之波動", 2, 77, 0)); Frogadier.add_trick(trick("燕返", 9, 80, 0));
	Froakie.set_higher_ptr(&Frogadier);

	Greninja.add_attribute(2); Greninja.add_attribute(15);
	Greninja.add_trick(trick("居合斬", 0, 49, 1)); Greninja.add_trick(trick("泡沫", 2, 45, 1));
	Greninja.add_trick(trick("水手裡劍", 2, 139, 0)); Greninja.add_trick(trick("燕返", 9, 125, 0));
	Frogadier.set_higher_ptr(&Greninja);

	Fletchling.add_attribute(0); Fletchling.add_attribute(9);
	Fletchling.add_trick(trick("影分身", 0, 10, 1)); Fletchling.add_trick(trick("啄擊", 9, 11, 1));
	Fletchling.add_trick(trick("鋼翼", 16, 24, 0)); Fletchling.add_trick(trick("旋風刀", 0, 27, 0));
	Froakie.set_next_ptr(&Fletchling);

	Fletchinder.add_attribute(1); Fletchinder.add_attribute(9);
	Fletchinder.add_trick(trick("啄擊", 9, 24, 1)); Fletchinder.add_trick(trick("旋風刀", 0, 26, 1));
	Fletchinder.add_trick(trick("蓄能焰襲", 1, 82, 0)); Fletchinder.add_trick(trick("鋼翼", 16, 71, 0));
	Fletchling.set_higher_ptr(&Fletchinder);

	Talonflame.add_attribute(1); Talonflame.add_attribute(9);
	Talonflame.add_trick(trick("旋風刀", 0, 44, 1)); Talonflame.add_trick(trick("蓄能焰襲", 1, 46, 1));
	Talonflame.add_trick(trick("勇鳥猛攻", 9, 136, 0)); Talonflame.add_trick(trick("噴射火焰", 1, 124, 0));
	Fletchinder.set_higher_ptr(&Talonflame);

	Hawlucha.add_attribute(6); Hawlucha.add_attribute(9);
	Hawlucha.add_trick(trick("空手劈", 6, 24, 1)); Hawlucha.add_trick(trick("飛膝踢", 6, 26, 1));
	Hawlucha.add_trick(trick("飛身重壓", 6, 83, 0)); Hawlucha.add_trick(trick("十字剪", 11, 72, 0));
	Fletchling.set_next_ptr(&Hawlucha);

	Goomy.add_attribute(14);
	Goomy.add_trick(trick("祈雨", 2, 8, 1)); Goomy.add_trick(trick("龍之吐息", 14, 10, 1));
	Goomy.add_trick(trick("克制", 0, 27, 0));
	Hawlucha.set_next_ptr(&Goomy);

	Sliggoo.add_attribute(14);
	Sliggoo.add_trick(trick("祈雨", 2, 23, 1)); Sliggoo.add_trick(trick("龍之吐息", 14, 26, 1));
	Sliggoo.add_trick(trick("克制", 0, 80, 0));
	Goomy.set_higher_ptr(&Sliggoo);

	Goodra.add_attribute(14);
	Goodra.add_trick(trick("祈雨", 2, 43, 1)); Goodra.add_trick(trick("龍之吐息", 14, 46, 1));
	Goodra.add_trick(trick("龍之波動", 14, 134, 0)); Goodra.add_trick(trick("冰凍光線", 5, 125, 0));
	Sliggoo.set_higher_ptr(&Goodra);

	Noibat.add_attribute(9); Noibat.add_attribute(14);
	Noibat.add_trick(trick("超音波", 0, 11, 1)); Noibat.add_trick(trick("撞擊", 0, 8, 1));
	Noibat.add_trick(trick("雜技", 9, 24, 0)); Noibat.add_trick(trick("爆音波", 0, 26, 0));
	Goomy.set_next_ptr(&Noibat);

	Noivern.add_attribute(9); Noivern.add_attribute(14);
	Noivern.add_trick(trick("撞擊", 0, 23, 1)); Noivern.add_trick(trick("雜技", 9, 26, 1));
	Noivern.add_trick(trick("爆音波", 0, 73, 0)); Noivern.add_trick(trick("龍爪", 14, 82, 0));
	Noibat.set_higher_ptr(&Noivern);
}
void build_NPC_my_pokemons() {
	//碧歐拉
	Surskit.add_attribute(5); Surskit.add_attribute(11);
	Surskit.add_trick(trick("黏黏網", 11, 24, 1)); Surskit.add_trick(trick("泡沫", 2, 20, 1));
	Surskit.add_trick(trick("冰凍光束", 5, 51, 0)); Surskit.add_trick(trick("信號光束", 11, 68, 0));
	Vivillon.add_attribute(9); Vivillon.add_attribute(11);
	Vivillon.add_trick(trick("起風", 9, 68, 1)); Vivillon.add_trick(trick("催眠粉", 4, 54, 1));
	Vivillon.add_trick(trick("陽光烈焰", 4, 159, 0)); Vivillon.add_trick(trick("精神強念", 10, 141, 0));

	//查克拉
	Onix.add_attribute(8); Onix.add_attribute(12);
	Onix.add_trick(trick("鐵尾", 16, 39, 1)); Onix.add_trick(trick("岩切", 12, 33, 1));
	Onix.add_trick(trick("加農光砲", 16, 95, 0)); Onix.add_trick(trick("岩石封鎖", 12, 74, 0));
	Tyrunt.add_attribute(12); Tyrunt.add_attribute(14);
	Tyrunt.add_trick(trick("鋼翼", 16, 22, 1)); Tyrunt.add_trick(trick("龍尾", 14, 19, 1));
	Tyrunt.add_trick(trick("岩石封鎖", 12, 45, 0)); Tyrunt.add_trick(trick("流星群", 14, 63, 0));

	//可爾妮
	Mienfoo.add_attribute(6);
	Mienfoo.add_trick(trick("飛膝踢", 6, 20, 1)); Mienfoo.add_trick(trick("高速星星", 0, 17, 1));
	Mienfoo.add_trick(trick("連環巴掌", 0, 50, 0)); Mienfoo.add_trick(trick("雜技", 9, 60, 0));
	Machoke.add_attribute(6);
	Machoke.add_trick(trick("劈瓦", 6, 30, 1)); Machoke.add_trick(trick("下旋踢", 6, 37, 1));
	Machoke.add_trick(trick("真氣彈", 6, 88, 0)); Machoke.add_trick(trick("真氣彈", 6, 88, 0));
	Lucario.add_attribute(6);
	Lucario.add_trick(trick("金屬音", 16, 50, 1)); Lucario.add_trick(trick("增強拳", 6, 65, 1));
	Lucario.add_trick(trick("波導彈", 6, 153, 0)); Lucario.add_trick(trick("鼓棒亂打", 8, 126, 0));

	//福爺
	Jumpluff.add_attribute(4); Jumpluff.add_attribute(9);
	Jumpluff.add_trick(trick("晴天", 1, 20, 1)); Jumpluff.add_trick(trick("種子機關槍", 4, 22, 1));
	Jumpluff.add_trick(trick("棉花", 4, 52, 0)); Jumpluff.add_trick(trick("棉花", 4, 52, 0));
	Weepinbell.add_attribute(4); Weepinbell.add_attribute(7);
	Weepinbell.add_trick(trick("打草結", 4, 35, 1)); Weepinbell.add_trick(trick("摔打", 0, 30, 1));
	Weepinbell.add_trick(trick("飛葉快刀", 4, 77, 0)); Weepinbell.add_trick(trick("毒粉", 7, 95, 0));
	Gogoat.add_attribute(4); 
	Gogoat.add_trick(trick("打草結", 4, 60, 1)); Gogoat.add_trick(trick("藤鞭", 4, 55, 1));
	Gogoat.add_trick(trick("飛葉快刀", 4, 110, 0)); Gogoat.add_trick(trick("寄生種子", 4, 140, 0));

	//希特隆
	Bunnelby.add_attribute(0);
	Bunnelby.add_trick(trick("連環巴掌", 0, 15, 1)); Bunnelby.add_trick(trick("挖洞", 8, 17, 1));
	Bunnelby.add_trick(trick("泥巴噴射", 8, 30, 0)); Bunnelby.add_trick(trick("瘋狂伏特", 3, 33, 0));
	Heliolisk.add_attribute(0); Heliolisk.add_attribute(3);
	Heliolisk.add_trick(trick("閃光", 0, 28, 1)); Heliolisk.add_trick(trick("十萬伏特", 3, 35, 1));
	Heliolisk.add_trick(trick("龍尾", 14, 79, 0)); Heliolisk.add_trick(trick("廣域充電", 3, 98, 0));
	Luxray.add_attribute(3);
	Luxray.add_trick(trick("放電", 3, 52, 1)); Luxray.add_trick(trick("高速星星", 0, 63, 1));
	Luxray.add_trick(trick("電氣場地", 3, 128, 0)); Luxray.add_trick(trick("瘋狂伏特", 3, 145, 0));

	//瑪秀
	Spritzee.add_attribute(17);
	Spritzee.add_trick(trick("陀螺球", 0, 18, 1)); Spritzee.add_trick(trick("月亮之力", 17, 23, 1));
	Spritzee.add_trick(trick("魔法閃耀", 17, 64, 0)); Spritzee.add_trick(trick("戲法空間", 10, 43, 0));
	Sylveon.add_attribute(17);
	Sylveon.add_trick(trick("魅惑", 17, 50, 1)); Sylveon.add_trick(trick("衝擊", 17, 43, 1));
	Sylveon.add_trick(trick("妖精之風", 10, 107, 0)); Sylveon.add_trick(trick("妖精之風", 10, 107, 0));

	//午時花
	female_Meowstic.add_attribute(10);
	female_Meowstic.add_trick(trick("預知未來", 10, 50, 1)); female_Meowstic.add_trick(trick("電磁波", 3, 30, 1));
	female_Meowstic.add_trick(trick("惡之波動", 15, 91, 0)); female_Meowstic.add_trick(trick("精神衝擊", 10, 103, 0));
	male_Meowstic.add_attribute(10);
	male_Meowstic.add_trick(trick("幫助", 0, 32, 1)); male_Meowstic.add_trick(trick("光牆", 10, 48, 1));
	male_Meowstic.add_trick(trick("精神衝擊", 10, 117, 0)); male_Meowstic.add_trick(trick("精神衝擊", 10, 117, 0));

	//德撫
	Abomasnow.add_attribute(4); Abomasnow.add_attribute(5);
	Abomasnow.add_trick(trick("木槌", 4, 68, 1)); Abomasnow.add_trick(trick("暴風雪", 5, 73, 1));
	Abomasnow.add_trick(trick("冰凍之風", 5, 183, 0)); Abomasnow.add_trick(trick("能量球", 4, 172, 0));
	Avalugg.add_attribute(5);
	Avalugg.add_trick(trick("陀螺球", 16, 32, 1)); Avalugg.add_trick(trick("冰凍牙", 5, 40, 1));
	Avalugg.add_trick(trick("尖石攻擊", 12, 102, 0)); Avalugg.add_trick(trick("雪崩", 5, 124, 0));
	Bergmite.add_attribute(5);
	Bergmite.add_trick(trick("高速旋轉", 0, 20, 1)); Bergmite.add_trick(trick("冰凍之風", 5, 24, 1));
	Bergmite.add_trick(trick("稜角化", 0, 68, 0)); Bergmite.add_trick(trick("稜角化", 0, 68, 0));

	//火箭隊
	Inkay.add_attribute(10); Inkay.add_attribute(15);
	Inkay.add_trick(trick("撞擊", 0, 16, 1)); Inkay.add_trick(trick("煙幕", 0, 19, 1));
	Inkay.add_trick(trick("幻象光線", 10, 50, 0)); Inkay.add_trick(trick("詐欺", 15, 42, 0));
	Pumpkaboo.add_attribute(4); Pumpkaboo.add_attribute(13);
	Pumpkaboo.add_trick(trick("寄生種子", 4, 17, 1)); Pumpkaboo.add_trick(trick("暗影球", 13, 19, 1));
	Pumpkaboo.add_trick(trick("惡之波動", 15, 48, 0)); Pumpkaboo.add_trick(trick("種子炸彈", 4, 45, 0));
	Wobbuffet.add_attribute(10);
	Wobbuffet.add_trick(trick("忍耐", 0, 2, 1));
	Wobbuffet.add_trick(trick("鏡面反射", 10, 5, 0));

	//娜米
	Nami_Talonflame.add_attribute(1); Nami_Talonflame.add_attribute(9);
	Nami_Talonflame.add_trick(trick("啄擊", 9, 35, 1)); Nami_Talonflame.add_trick(trick("鋼翼", 16, 35, 1));
	Nami_Talonflame.add_trick(trick("勇鳥猛攻", 9, 140, 0)); Nami_Talonflame.add_trick(trick("大字炎爆", 1, 140, 0));

	//狡猾天狗假面
	Barbaracle.add_attribute(2); Barbaracle.add_attribute(12);
	Barbaracle.add_trick(trick("貝殼刃", 2, 27, 1)); Barbaracle.add_trick(trick("毒擊", 7, 30, 1));
	Barbaracle.add_trick(trick("擲泥", 8, 87, 0)); Barbaracle.add_trick(trick("擲泥", 8, 87, 0));

	//兵太夫
	Heidayu_Bisharp.add_attribute(15);
	Heidayu_Bisharp.add_trick(trick("十字剪", 11, 37, 1)); Heidayu_Bisharp.add_trick(trick("暗影爪", 13, 40, 1));
	Heidayu_Bisharp.add_trick(trick("大聲咆哮", 15, 113, 0)); Heidayu_Bisharp.add_trick(trick("連斬", 11, 95, 0));

	//阿朋
	Altaria.add_attribute(9); Altaria.add_attribute(14);
	Altaria.add_trick(trick("啄擊", 14, 63, 1)); Altaria.add_trick(trick("龍息", 14, 71, 1));
	Altaria.add_trick(trick("龍之波動", 14, 170, 0)); Altaria.add_trick(trick("魔法閃耀", 17, 176, 0));

	//艾嵐
	Tyranitar.add_attribute(12); Tyranitar.add_attribute(15);
	Tyranitar.add_trick(trick("咬碎", 15, 75, 1)); Tyranitar.add_trick(trick("尖石攻擊", 12, 80, 1));
	Tyranitar.add_trick(trick("惡之波動", 15, 189, 0)); Tyranitar.add_trick(trick("惡之波動", 15, 189, 0));
	Weavile.add_attribute(5); Weavile.add_attribute(15);
	Weavile.add_trick(trick("守護", 0, 61, 1)); Weavile.add_trick(trick("暗襲要害", 15, 78, 1));
	Weavile.add_trick(trick("影分身", 0, 168, 0)); Weavile.add_trick(trick("冰凍光束", 5, 187, 0));
	Bisharp.add_attribute(15); 
	Bisharp.add_trick(trick("電磁波", 3, 75, 1)); Bisharp.add_trick(trick("斷頭鉗", 0, 63, 1));
	Bisharp.add_trick(trick("鐵頭", 16, 178, 0)); Bisharp.add_trick(trick("真氣彈", 6, 184, 0));
	Unfezant.add_attribute(0); Unfezant.add_attribute(9);
	Unfezant.add_trick(trick("鋼翼", 16, 51, 1)); Unfezant.add_trick(trick("空氣斬", 9, 47, 1));
	Unfezant.add_trick(trick("勇鳥猛攻", 9, 143, 0)); Unfezant.add_trick(trick("勇鳥猛攻", 9, 143, 0));
	Metagross.add_attribute(10); Metagross.add_attribute(16);
	Metagross.add_trick(trick("精神強念", 10, 77, 1)); Metagross.add_trick(trick("金屬爪", 16, 72, 1));
	Metagross.add_trick(trick("岩崩", 12, 198, 0)); Metagross.add_trick(trick("彗星拳", 16, 209, 0));
	Charizard.add_attribute(1); Charizard.add_attribute(9);
	Charizard.add_trick(trick("噴射火焰", 1, 88, 1)); Charizard.add_trick(trick("鋼翼", 16, 85, 1));
	Charizard.add_trick(trick("龍爪", 14, 208, 0)); Charizard.add_trick(trick("閃焰衝鋒", 1, 229, 0));

	//翔太
	Treecko.add_attribute(4);
	Treecko.add_trick(trick("飛葉快刀", 4, 12, 1)); Treecko.add_trick(trick("高速移動", 10, 15, 1));
	Treecko.add_trick(trick("種子機關槍", 4, 35, 0)); Treecko.add_trick(trick("種子機關槍", 4, 35, 0));
	Sceptile.add_attribute(4);
	Sceptile.add_trick(trick("飛葉快刀", 4, 48, 1)); Sceptile.add_trick(trick("葉刃", 13, 55, 1));
	Sceptile.add_trick(trick("瘋狂植物", 4, 139, 0)); Sceptile.add_trick(trick("龍之波動", 14, 128, 0));
	Slurpuff.add_attribute(17);
	Slurpuff.add_trick(trick("迷人", 0, 24, 1)); Slurpuff.add_trick(trick("能量球", 4, 27, 1));
	Slurpuff.add_trick(trick("魔法閃耀", 17, 83, 0)); Slurpuff.add_trick(trick("噴射火焰", 1, 72, 0));
	Bagon.add_attribute(14);
	Bagon.add_trick(trick("龍之吐息", 14, 16, 1)); Bagon.add_trick(trick("頭槌", 0, 11, 1));
	Bagon.add_trick(trick("龍爪", 14, 38, 0)); Bagon.add_trick(trick("龍爪", 14, 38, 0));
	Shelgon.add_attribute(14);
	Shelgon.add_trick(trick("龍之吐息", 14, 40, 1)); Shelgon.add_trick(trick("火焰牙", 1, 34, 1));
	Shelgon.add_trick(trick("龍爪", 14, 101, 0)); Shelgon.add_trick(trick("守護", 0, 88, 0));
	Salamence.add_attribute(14);
	Salamence.add_trick(trick("龍之吐息", 14, 75, 1)); Salamence.add_trick(trick("燒盡", 1, 67, 1));
	Salamence.add_trick(trick("龍爪", 14, 181, 0)); Salamence.add_trick(trick("龍尾", 14, 172, 0));
	Clawitzer.add_attribute(2);
	Clawitzer.add_trick(trick("蟹鉗錘", 2, 35, 1)); Clawitzer.add_trick(trick("龍之波動", 14, 40, 1));
	Clawitzer.add_trick(trick("冰凍光束", 5, 118, 0)); Clawitzer.add_trick(trick("水之波動", 2, 111, 0));
	Honedge.add_attribute(13); Honedge.add_attribute(16);
	Honedge.add_trick(trick("鐵壁", 16, 16, 1)); Honedge.add_trick(trick("劈開", 0, 10, 1));
	Honedge.add_trick(trick("劍舞", 0, 34, 0)); Honedge.add_trick(trick("劍舞", 0, 34, 0));
	Doublade.add_attribute(13); Doublade.add_attribute(16);
	Doublade.add_trick(trick("鐵壁", 16, 33, 1)); Doublade.add_trick(trick("劈開", 0, 27, 1));
	Doublade.add_trick(trick("王者盾牌", 16, 96, 0)); Doublade.add_trick(trick("聖劍", 6, 93, 0));
	Aegislash.add_attribute(13); Aegislash.add_attribute(16);
	Aegislash.add_trick(trick("鐵壁", 16, 71, 1)); Aegislash.add_trick(trick("暗襲要害", 15, 68, 1));
	Aegislash.add_trick(trick("王者盾牌", 16, 187, 0)); Aegislash.add_trick(trick("聖劍", 6, 168, 0));
	Slaking.add_attribute(0);
	Slaking.add_trick(trick("偷懶", 0, 55, 1)); Slaking.add_trick(trick("臂錘", 6, 58, 1));
	Slaking.add_trick(trick("雙倍奉還", 6, 162, 0)); Slaking.add_trick(trick("雙倍奉還", 6, 162, 0));
	
	//野生寶可夢
	Moltres.add_attribute(1); Moltres.add_attribute(9);
	Moltres.add_trick(trick("噴射火焰", 1, 38, 1)); Moltres.add_trick(trick("噴射火焰", 1, 38, 1));
	Moltres.add_trick(trick("大字炎爆", 1, 120, 0)); Moltres.add_trick(trick("大字炎爆", 1, 120, 0));
	Grumpig.add_attribute(10);
	Grumpig.add_trick(trick("神通力", 10, 28, 1)); Grumpig.add_trick(trick("充電光束", 3, 24, 1));
	Grumpig.add_trick(trick("暗影球", 13, 73, 0)); Grumpig.add_trick(trick("精神強念", 10, 81, 0));
}