#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>
#include "map.h"
#include "view.h"

using namespace sf;
using namespace std;
struct direction
{
	float dx,dy;
};
////////////////////////////////////Класс Волшебник/////////////////////////////////////////
class Player{
	private:
	float x,y;
	public:
	//координаты, скорость и направление 
	float w,h,speed;
	direction dir;
	string key;
	map<string,direction> trend;
	
	//загружаем спрайт
	string File;
	Image image;
	Texture texture;
	Sprite sprite;
	
	Player(String F, float X, float Y, float W,float H){
		dir.dx = 0.0; dir.dy = 0.0; speed = 0;
		
		File = F;
		w = W; h = H; x=X; y=Y;
		
		//Загружаем спрайт волшебника
		image.loadFromFile(File);
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		sprite.setTextureRect(sf::IntRect(510,126,w,h));
		sprite.setPosition(x,y);
		
		//устанавливаем направление движения и его скорость
		trend ["left"] = {-1,0};
		trend ["right"] = {1,0};
		trend ["up"] = {0,-1};
		trend ["down"] = {0,1};
	}
	
	void update(float time)
	{
		//изменяем координату 
		x+=trend[key].dx*time*speed;
		y+=trend[key].dy*time*speed;
		//зануляем скорость чтобы персонаж не двигался бесконечно 
		speed = 0;
		
		//меня координаты на экране
		sprite.setPosition(x,y);
	}
	float getPosX(){
		return x;
	}
	float getPosY(){
		return y;
	}
	void boundary(){
		
	}
};

int main()
{
	RenderWindow window(sf::VideoMode(640, 480), "Wizard");	
	view.reset(sf::FloatRect(0, 0, 640, 480));
	Player wizard("MazeTileset.png",50,25,20.0,20.0);
	
	
	//float CurrentFrame = 0;//хранит текущий кадр
	Clock clock;
	
	//Подгружаем спрайт для карты
	Image map_image;
	map_image.loadFromFile("MazeTileset.png");
	Texture map;
	map.loadFromImage(map_image);
	Sprite s_map;
	s_map.setTexture(map);
	createMap();
	
	//кординаты курсора 
	sf::Vector2 mausePosition = Mouse::getPosition(window);
	
	
	while (window.isOpen())	
	{
		//прошедшее время в микросекундах
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time/800;//скорость игры
		
		
		//закрыть окно
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
                //получаем координаты курсора
                //mausePosition = Mouse::getPosition(window);
                //cout << "x: " << mausePosition.x << "y: " <<  mausePosition.y << endl; 
              
		//Управдение камерой
		//changeview();
		///////////////////////////////Управление персонажем/////////////////////////////
		//идём влево
		if (Keyboard::isKeyPressed(Keyboard::A) || Keyboard::isKeyPressed(Keyboard::Left))
		{
			 wizard.key = "left";
			 wizard.speed = 0.1;
			 setCoordinateForView(wizard.getPosX(),wizard.getPosY());
	        } 
	        
	        //идём вправо
		if (Keyboard::isKeyPressed(Keyboard::D) || Keyboard::isKeyPressed(Keyboard::Right)) 
		{
			wizard.key = "right";
			wizard.speed = 0.1;
			setCoordinateForView(wizard.getPosX(),wizard.getPosY());
		} 
		
		//идём вверх
		if (Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(Keyboard::Up))
		{
			wizard.key = "up";
			wizard.speed = 0.1; 
			setCoordinateForView(wizard.getPosX(),wizard.getPosY());
		} 
		
		//идём вниз
		if (Keyboard::isKeyPressed(Keyboard::S) || Keyboard::isKeyPressed(Keyboard::Down))
		{
			wizard.key = "down";
			wizard.speed = 0.1;
			setCoordinateForView(wizard.getPosX(),wizard.getPosY());		
		} 
		
		wizard.update(time);
		
		window.setView(view);
		window.clear();
		
		////////////////////////////Pисуем крату//////////////////////////////////////;
		for(int i = 0; i < HEIGHT_MAP; ++i){
			for(int j = 0; j < WIDTH_MAP; ++j){
				s_map.setTextureRect(IntRect(gameMap[Map[i][j]].x, gameMap[Map[i][j]].y,IMG_SIZE,IMG_SIZE));
				s_map.setPosition(j*IMG_SIZE,i*IMG_SIZE);
				
				window.draw(s_map);	
			}
		}
		window.draw(wizard.sprite);//выводим спрайт на экран
		window.display();
	}
	
	return 0;
}
