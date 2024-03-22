#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>
#include <vector>
#define N 14

using namespace std;

const int HEIGHT_MAP = 10;
const int WIDTH_MAP = 15;
const int IMG_SIZE = 96;
const int BANS = 4;
const int STATE = N;


struct patern{
	public:
	int x,y;
	bool left,right,up,down;
};

//Состояние 
struct idMap{
	int id;
	int i,j;
};

struct bans{
	int id_bkg;
	bool left,right,up,down;
};
//creat patern of map
std::map<int,patern>gameMap{
	{ 0,{  0,  0, true, true, true, true}},
	{ 1,{128,  0, true,false, true, true}},
	{ 2,{256,  0,false, true, true, true}},
	{ 3,{384,  0,false,false, true, true}},
	{ 4,{  0,384, true, true,false,false}},
	{ 5,{  0,128, true, true, true,false}},
	{ 6,{  0,256, true, true,false, true}},
	{ 7,{256,128,false, true, true,false}},
	{ 8,{256,256,false, true,false, true}},
	{ 9,{128,128, true,false, true,false}},
	{10,{128,256, true,false,false, true}},
	{11,{384,128,false,false, true,false}},
	{12,{384,256,false,false,false, true}},
	{13,{256,384,false, true,false,false}},
	{14,{128,384, true,false,false,false}},
	{15,{384,384,false,false,false,false}},
};

//Массив всех состояний
vector<idMap> tileMap[HEIGHT_MAP][WIDTH_MAP]; 

//creat Map
int Map [HEIGHT_MAP][WIDTH_MAP];
void createMap(); 
void createItems();
void createItem(vector<idMap> (&));
void constraintsBorders();
void fillItems();

/*
gameMap[0] = cross;
gameMap[1] = torleft;
gameMap[2] = torright;
gameMap[3] = strightvert;
gameMap[4] = strighthoriz;
gameMap[5] = torup;
gameMap[6] = tordown;
gameMap[7] = cornerLD;
gameMap[8] = cornerLU;
gameMap[9] = cornerRD;
gameMap[10] = cornerRU;
gameMap[11] = culdesacdown;
gameMap[12] = culdesacup;
gameMap[13] = culdesacleft;
gameMap[14] = culdesacright;
gameMap[15] = empty;
*/
