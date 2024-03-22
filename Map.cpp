#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>
#include "map.h"
#include <ctime>
#include <vector>
#ifndef N
#define N 14
#endif

using namespace std; 

void createMap(); 
void printMap(vector <idMap> (&));
void createItems();
void createItem(vector<idMap> (&));
void fillItems();
void constraintsBorders();

void createMap(){
	srand(time(0));
	fillItems();
	constraintsBorders();
	createItems();
	//tileMap[HEIGHT_MAP][WIDTH_MAP].clear();
} 

///////////////////////////////Создание карты/////////////////////////////////////////////////////
void createItems(){
	 for(int i = 0; i < HEIGHT_MAP; ++i){
		for(int j = 0; j < WIDTH_MAP; ++j){
			createItem(tileMap[i][j]);
		}
	}
}

////////////////////////Огранияения на границах///////////////////////////////////////////////////
void constraintsBorders(){
	vector<idMap> tmp;
	int id;
	for(unsigned int j = 0; j < WIDTH_MAP; ++j){
		for(unsigned int k = 0; k < tileMap[0][j].size(); ++k){
			id = tileMap[0][j][k].id;
			if( gameMap[id].up == false){
				tmp.push_back(tileMap[0][j][k]);
			}
		}
		tileMap[0][j] = tmp;
		tmp.clear();
	}
	for(unsigned int j = 0; j < WIDTH_MAP; ++j){
		for(unsigned int k = 0; k < tileMap[HEIGHT_MAP-1][j].size(); ++k){
			id = tileMap[HEIGHT_MAP-1][j][k].id;
			if(gameMap[id].down == false){
				tmp.push_back(tileMap[HEIGHT_MAP-1][j][k]);
			}
		}
		tileMap[HEIGHT_MAP - 1][j] = tmp;
		tmp.clear();
	}
	for(unsigned int i = 0; i < HEIGHT_MAP; ++i){
		for(unsigned int k = 0; k < tileMap[i][0].size(); ++k){
			id = tileMap[i][0][k].id;
			if( gameMap[id].left == false){
				tmp.push_back(tileMap[i][0][k]);
			}
		}
		tileMap[i][0] = tmp;
		tmp.clear();
	}
	for(unsigned int i = 0; i < HEIGHT_MAP; ++i){
		for(unsigned int k = 0; k < tileMap[i][WIDTH_MAP-1].size(); ++k){
			id = tileMap[i][WIDTH_MAP-1][k].id;
			if(gameMap[id].right == false){
				tmp.push_back(tileMap[i][WIDTH_MAP-1][k]);
			}	
		}
		tileMap[i][WIDTH_MAP - 1] = tmp;
		tmp.clear();
	}
}
////////////////////////////////////условие ограниченй//////////////////////////////////////
void constraints(idMap (&tMap)){
	//индекс илемента
	int i = tMap.i;
	int j = tMap.j;
	vector<idMap> tmp;
	
	//////////////////////////////удалаем все невозможные значения сверху/////////////////////
	if( i != 0){
		vector<idMap> up = tileMap[i-1][j];
		for(unsigned int k = 0; k < up.size(); ++k){
			if(gameMap[up[k].id].down == gameMap[tMap.id].up){
		 		tmp.push_back(up[k]);
			}
		}
		tileMap[i-1][j] = tmp;
		tmp.clear();
	}
	
	
	/////////////////////////удалаем все невозможные значения снизу///////////////////////////
	if( i != (HEIGHT_MAP - 1)){
		vector<idMap> down = tileMap[i+1][j];
		for(unsigned int k = 0; k < down.size(); ++k){
			if(gameMap[down[k].id].up == gameMap[tMap.id].down){
			 	tmp.push_back(down[k]);
			}
		}
		tileMap[i+1][j] = tmp;
	        tmp.clear();
	}
	
				
	/////////////////////////////удалаем все невозможные значения слева///////////////////////
	if(j != 0){
		vector<idMap> left = tileMap[i][j-1];
		for(unsigned int k = 0; k < left.size(); ++k){
			if(gameMap[left[k].id].right == gameMap[tMap.id].left){
			 	tmp.push_back(left[k]);
			}
		}
		tileMap[i][j-1] = tmp;
		tmp.clear();
	}
	
	
	//удалаем все невозможные значения справа
	if( j != (WIDTH_MAP-1)){
		vector<idMap> right = tileMap[i][j+1];
		for(unsigned int k = 0; k < right.size(); ++k){
			if(gameMap[right[k].id].left == gameMap[tMap.id].right){
		 		tmp.push_back(right[k]);
			}
		}
		tileMap[i][j+1] = tmp;
		tmp.clear();
	}	
}

////////////////////////////////Выбираем состояние из возможных///////////////////////////////////
void createItem(vector<idMap> (&tMap)){ 
	int idItem = rand()%tMap.size();
	auto it = tMap[idItem];
	Map[it.i][it.j] = it.id;
	tMap.clear();
	tMap.push_back(it);
	constraints(it);
}

//////////////////////////////создаюм карту всех состояний////////////////////////////////////////
void fillItems(){
	for(int i = 0; i < HEIGHT_MAP; ++i){
		for(int j = 0; j < WIDTH_MAP; ++j){
			for(int k = 0; k <= N; ++k){
				//Заполняем всевосможными состояниями
				tileMap[i][j].push_back({k,i,j});
			}
		}
	}
}




