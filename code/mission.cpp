+#include "header.h"
#include <iostream>
#include <cstdlib>

using namespace std;

mission missions[9][5];

void build_mission_list() {
	missions[0][0].set_mission("1-1 �ҵ{ �d�����p��", "��ܦa�ϡA�e���K���p��>>�W���", &cities[0], cities[0].get_spot(1));
	missions[0][1].set_mission("1-2 ��� �ƯS���P������", "��ܦa�ϡA�e���K���p��>>�W���", &cities[0], cities[0].get_spot(1));
	missions[0][2].set_mission("1-3 R�ORocket���N��", "��ܦa�ϡA�e���K���p��>>�W���", &cities[0], cities[0].get_spot(1));
	missions[0][3].set_mission("1-4 mega�i�� ���Զ�ճդh�P�P�r���T", "��ܦa�ϡA�e���K���p��>>���Զ�ճդh��s��", &cities[0], cities[0].get_spot(2));
	missions[0][4].set_mission("1-5 �D�Զ}�l �e�i���ȥ�", "��ܦa�ϡA�e���K���p��>>���Զ�ճդh��s��", &cities[0], cities[0].get_spot(2));
	missions[1][0].set_mission("2-1 �K�K�w��P�p�b��", "��ܦa�ϡA�e�����ȥ�>>�|���D���˪L", &cities[1], cities[1].get_spot(0));
	missions[1][1].set_mission("2-2 �D�ԥ��ȹD�] �ȷȿ}�y�P�m����", "��ܦa�ϡA�e�����ȥ�>>���ȹD�]�]��ĳ���N�_�i�ڪ�HP�ɺ��H���ﱵ�U�Ӫ��D�]�ԡI�^", &cities[1], cities[1].get_spot(1));
	missions[1][2].set_mission("2-3 �K���p�D�]�]�D", "��ܦa�ϡA�e���K���p��>>�W���", &cities[0], cities[0].get_spot(1));
	missions[1][3].set_mission("2-4 �D�Ի����D�] �ʦL���۫���", "��ܦa�ϡA�e��������>>�����D�]�]��ĳ���N�_�i�ڪ�HP�ɺ��H���ﱵ�U�Ӫ��D�]�ԡI�^", &cities[2], cities[2].get_spot(0));
	missions[2][0].set_mission("3-1 �˪L����", "��ܦa�ϡA�e��������>>�Q�@���D���˪L�]��ĳ���N�_�i�ڪ�HP�ɺ��I�^", &cities[2], cities[2].get_spot(1));
	missions[2][1].set_mission("3-2 �֯���Q�Ť��H �p�b���P�P�b�N", "��ܦa�ϡA�e���Pù��>>�Ť����H�V�m���ߡ]��ĳ���N�_�i�ڪ�HP�ɺ��I�^", &cities[3], cities[3].get_spot(0));
	missions[2][2].set_mission("3-3 �D�Ԯ氫�D�] mega���d�Q��", "��ܦa�ϡA�e���Pù��>>��Ҥ���]��ĳ���N�_�i�ڪ�HP�ɺ��H���ﱵ�U�Ӫ��D�]�ԡI�^", &cities[3], cities[3].get_spot(1));
	missions[2][3].set_mission("3-4 �e�W�ƨӤ@�W�Ԫ̡H�I �T���P�ҶP�Ե�", "��ܦa�ϡA�e���Pù��>>�Q�G���D���˪L�]��ĳ���N�_�i�ڪ�HP�ɺ��I�^", &cities[3], cities[3].get_spot(2));
	missions[2][4].set_mission("3-5 �ԳN��M �K�K�w��P�t�����Z", "��ܦa�ϡA�e���Pù��>>�Q�G���D���˪L�]��ĳ���N�_�i�ڪ�HP�ɺ��I�^", &cities[3], cities[3].get_spot(2));
	missions[3][0].set_mission("4-1 �q�Ѧӭ����s�H", "��ܦa�ϡA�e���Pù��>>�Q�G���D����`", &cities[3], cities[3].get_spot(3));
	missions[3][1].set_mission("4-2 ��M�� �԰��a�A�H�H�_", "��ܦa�ϡA�e�����l��>>�Q�G���D�����]��ĳ���N�_�i�ڪ�HP�ɺ��I�^", &cities[4], cities[4].get_spot(1));
	missions[3][2].set_mission("4-3 �D�Ԥ��l�D�] �ӪK���`���B", "��ܦa�ϡA�e�����l��>>���l�D�]�]��ĳ���N�_�i�ڪ�HP�ɺ��H���ﱵ�U�Ӫ��D�]�ԡI�^", &cities[4], cities[4].get_spot(0));
	missions[3][3].set_mission("4-4 �H����|�[�o�I", "��ܦa�ϡA�e�����l��>>�Q�T���D���˪L", &cities[4], cities[4].get_spot(2));
	missions[4][0].set_mission("5-1 �^����I �D�ԱK���p�D�]", "��ܦa�ϡA�e���K���p��>>�W���]��ĳ���N�_�i�ڪ�HP�ɺ��H���ﱵ�U�Ӫ��D�]�ԡI�^", &cities[0], cities[0].get_spot(1));
	missions[4][1].set_mission("5-2 ��J���� �T�^�X�J�Ĺ��", "��ܦa�ϡA�e�����ȥ�>>���q���A�˩��]��ĳ���N�_�i�ڪ�HP�ɺ��I�^", &cities[5], cities[5].get_spot(1));
	missions[4][2].set_mission("5-3 �D�ԭ��ȹD�] ���R���몺����", "��ܦa�ϡA�e�����ȥ�>>���ȹD�]�]��ĳ���N�_�i�ڪ�HP�ɺ��H���ﱵ�U�Ӫ��D�]�ԡI�^", &cities[5], cities[5].get_spot(0));
	missions[4][3].set_mission("5-4 �J�̪�baby", "��ܦa�ϡA�e�����ȥ�>>�Q�����D���˪L", &cities[5], cities[5].get_spot(2));
	missions[5][0].set_mission("6-1 �d�~�@�J�������ǩ_ ���b��vs���K��", "��ܦa�ϡA�e���ʨ襫>>���h���s�]��ĳ���N�_�i�ڪ�HP�ɺ��I�^", &cities[6], cities[6].get_spot(0));
	missions[5][1].set_mission("6-2 �D�Ԧʨ�D�] �믫�O�q����M", "��ܦa�ϡA�e���ʨ襫>>�ʨ�D�]�]��ĳ���N�_�i�ڪ�HP�ɺ��H���ﱵ�U�Ӫ��D�]�ԡI�^", &cities[6], cities[6].get_spot(1));
	missions[5][2].set_mission("6-3 �w��Ө�Ԫ̧�", "��ܦa�ϡA�e���ʨ襫>>�Ԫ̧��]��ĳ���N�_�i�ڪ�HP�ɺ��I�^", &cities[6], cities[6].get_spot(2));
	missions[5][3].set_mission("6-4 �̲׹�M �A���ҶP�Ե�", "��ܦa�ϡA�e���ʨ襫>>�Ԫ̧��]��ĳ���N�_�i�ڪ�HP�ɺ��I�^", &cities[6], cities[6].get_spot(2));
	missions[6][0].set_mission("7-1 �ۦP���I�l ���Ӫ��h�i��", "��ܦa�ϡA�e���ʨ襫>>�Q�K���D���˪L�]��ĳ���N�_�i�ڪ�HP�ɺ��I�^", &cities[6], cities[6].get_spot(3));
	missions[6][1].set_mission("7-2 mega��M �W�żQ���s", "��ܦa�ϡA�e���ʨ襫>>�Q�K���D���˪L�]��ĳ���N�_�i�ڪ�HP�ɺ��I�^", &cities[6], cities[6].get_spot(3));
	missions[6][2].set_mission("7-3 ���㪺�p�� �{�q���P�佻", "��ܦa�ϡA�e���ʨ襫>>�Q�K���D���˪L�]��ĳ���N�_�i�ڪ�HP�ɺ��I�^", &cities[6], cities[6].get_spot(3));
	missions[6][3].set_mission("7-4 �A�J��P", "��ܦa�ϡA�e���M����>>�o��p��Ρ]��ĳ���N�_�i�ڪ�HP�ɺ��I�^", &cities[7], cities[7].get_spot(1));
	missions[6][4].set_mission("7-5 �G����M �ҶP�Ե�Pmega�Q���s", "��ܦa�ϡA�e���M����>>�o��p��Ρ]��ĳ���N�_�i�ڪ�HP�ɺ��I�^", &cities[7], cities[7].get_spot(1));
	missions[7][0].set_mission("8-1 �J�Ī���M3", "��ܦa�ϡA�e���M����>>�M���D�]�]��ĳ���N�_�i�ڪ�HP�ɺ��I�^", &cities[7], cities[7].get_spot(0));
	missions[7][1].set_mission("8-2 �@�����M�`�����", "��ܦa�ϡA�e���M����>>�M���D�]�]��ĳ���N�_�i�ڪ�HP�ɺ��H���ﱵ�U�Ӫ��D�]�ԡI�^", &cities[7], cities[7].get_spot(0));
	missions[7][2].set_mission("8-3 �g�۴˪L �i�ƪ�����", "��ܦa�ϡA�e���M����>>�˪L�n���s�}", &cities[7], cities[7].get_spot(2));
	missions[7][3].set_mission("8-4 �o�ʥ�������̽b ��M�W�żɳ���", "��ܦa�ϡA�e���M����>>�M���D�]�]��ĳ���N�_�i�ڪ�HP�ɺ��H���ﱵ�U�Ӫ��D�]�ԡI�^", &cities[7], cities[7].get_spot(0));
	missions[8][0].set_mission("9-1 �d�����p�� �}��", "��ܦa�ϡA�e���K���p��>>�W���]��ĳ���N�_�i�ڪ�HP�ɺ��H���ﱵ�U�Ӫ��p���ԡI�^", &cities[0], cities[0].get_spot(1));
	missions[8][1].set_mission("9-2 �̱j�D�Ԫ� �l�Ĺ�M", "��ܦa�ϡA�e���K���p��>>�W���]��ĳ���N�_�i�ڪ�HP�ɺ��H���ﱵ�U�Ӫ��p���ԡI�^", &cities[0], cities[0].get_spot(1));
	missions[8][2].set_mission("9-3 �������e �̫᪺�}������", "��ܦa�ϡA�e���K���p��>>�W���]��ĳ���N�_�i�ڪ�HP�ɺ��H���ﱵ�U�Ӫ��p���ԡI�^", &cities[0], cities[0].get_spot(1));
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