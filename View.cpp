#include <SFML/Graphics.hpp>
#include "view.h"
#include "map.h"
void setCoordinateForView(float x,float y){
	float tempX = x; float tempY = y;
	
	if (x < 320) tempX = 320;//убираем из вида левую сторону
	if (y < 240) tempY = 240;//верхнюю сторону
	if (y > (HEIGHT_MAP*IMG_SIZE -240)) tempY = HEIGHT_MAP*IMG_SIZE-240;//нижнюю сторону	
	if( x > (IMG_SIZE*WIDTH_MAP - 320)) tempX = IMG_SIZE*WIDTH_MAP-320;
 
	view.setCenter(tempX, tempY); //следим за игроком, передавая его координаты. 
}

void changeview(){
	
 
	if (Keyboard::isKeyPressed(Keyboard::U)) {
		//view.zoom(1.0100f); //масштабируем, уменьшение
		view.zoom(1.0006f); //тоже самое помедленнее соответственно
	}
	
 
	if (Keyboard::isKeyPressed(Keyboard::I)) {
		view.setSize(640, 480);//устанавливает размер камеры (наш исходный)
	}
 
	if (Keyboard::isKeyPressed(Keyboard::P)) {
		view.setSize(540, 380);//например другой размер
	}
 
 
	if (Keyboard::isKeyPressed(Keyboard::Q)) {
		view.setViewport(sf::FloatRect(0, 0, 0.5f, 1));//таким образом делается раздельный экран для игры на двоих. нужно только создать ещё один объект View и привязывать к нему координаты игрока 2.
	}
		
	
	
}

void viewmap(float time) { //функция для перемещения камеры по карте. принимает время sfml
	if (Keyboard::isKeyPressed(Keyboard::D)) {
		view.move(0.1*time, 0);//скроллим карту вправо 
	}
	if (Keyboard::isKeyPressed(Keyboard::S)) {
		view.move(0, 0.1*time);//скроллим карту вниз 
	}
	if (Keyboard::isKeyPressed(Keyboard::A)) {
		view.move(-0.1*time, 0);//скроллим карту влево 
	}
	if (Keyboard::isKeyPressed(Keyboard::W)) {
		view.move(0, -0.1*time);//скроллим карту вправо 
	}
}

bool checkCamera(float x,float y){
	return true;
}
