sf::Image ground;
sf::Texture bgtexture;

// load image
ground.loadFromFile("MazeTileset.png");
  	
//create texture
bgtexture.loadFromImage(ground);
	
//create sprite for background	
sf::Sprite cross;
sf::Sprite torleft;
sf::Sprite torright;
sf::Sprite strightvert;
sf::Sprite strighthoriz;
sf::Sprite torup;
sf::Sprite tordown;
sf::Sprite cornerLD;
sf::Sprite cornerLU;
sf::Sprite cornerRD;
sf::Sprite cornerRU;
sf::Sprite culdesacdown;
sf::Sprite culdesacup;
sf::Sprite culdesacleft;
sf::Sprite culdesacright;
sf::Sprite empty;
	
//set sprite for cross
cross.setTexture(bgtexture);
cross.setTextureRect(sf::IntRect(0,0,IMG_SIZE,IMG_SIZE));

//set sprite for torleft
torleft.setTexture(bgtexture);
torleft.setTextureRect(sf::IntRect(130,0,IMG_SIZE,IMG_SIZE));

//set sprite for torright
torright.setTexture(bgtexture);
torright.setTextureRect(sf::IntRect(255,0,IMG_SIZE,IMG_SIZE));
	
//set sprite for strightvertical
strightvert.setTexture(bgtexture);
strightvert.setTextureRect(sf::IntRect(385,0,IMG_SIZE,IMG_SIZE));
	
//set sprite for empty block
empty.setTexture(bgtexture);
empty.setTextureRect(sf::IntRect(510,0,IMG_SIZE,IMG_SIZE));

//set sprite for torup
torup.setTexture(bgtexture);
torup.setTextureRect(sf::IntRect(0,130,IMG_SIZE,IMG_SIZE));

//set sprite for cornerRD
cornerRD.setTexture(bgtexture);
cornerRD.setTextureRect(sf::IntRect(130,130,IMG_SIZE,IMG_SIZE));

//set sprite for cornerLD
cornerLD.setTexture(bgtexture);
cornerLD.setTextureRect(sf::IntRect(255,130,IMG_SIZE,IMG_SIZE));

//set sprite for culdesacdown
culdesacdown.setTexture(bgtexture);
culdesacdown.setTextureRect(sf::IntRect(385,130,IMG_SIZE,IMG_SIZE));

//set sprite for tordown
tordown.setTexture(bgtexture);
tordown.setTextureRect(sf::IntRect(0,255,IMG_SIZE,IMG_SIZE));

//set sprite for cornerRU
cornerRU.setTexture(bgtexture);
cornerRU.setTextureRect(sf::IntRect(130,255,IMG_SIZE,IMG_SIZE));
//set sprite for cornerLU
cornerLU.setTexture(bgtexture);
cornerLU.setTextureRect(sf::IntRect(255,255,IMG_SIZE,IMG_SIZE));

//set sprite for culdesacup
culdesacup.setTexture(bgtexture);
culdesacup.setTextureRect(sf::IntRect(385,255,IMG_SIZE,IMG_SIZE));

//set sprite for culdesacup
strighthoriz.setTexture(bgtexture);
strighthoriz.setTextureRect(sf::IntRect(0,385,IMG_SIZE,IMG_SIZE));

//set sprite for culdesacright
culdesacright.setTexture(bgtexture);
culdesacright.setTextureRect(sf::IntRect(130,385,IMG_SIZE,IMG_SIZE));

//set sprite for culdesacup
culdesacleft.setTexture(bgtexture);
culdesacleft.setTextureRect(sf::IntRect(255,385,IMG_SIZE,IMG_SIZE));

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
