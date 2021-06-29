#include "SFML/Graphics.hpp"
#include "SFML/Graphics/Text.hpp"
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include<string>
#include<sstream>
#include<math.h>
#include<vector>
using namespace sf;

class Bullet{
public:
	Sprite shape;
	Bullet(Texture *texture, Vector2f pos){
		this->shape.setTexture(*texture);
		this->shape.setScale(0.2,0.2);
		this->shape.setPosition(pos);
	}

~Bullet(){ }
	
};

class Player{
public:
	Sprite shape;
   Texture *texture;	
	std::vector<Bullet> bullets;
	
	Player(Texture *texture){
	this->texture = texture;
	this-> shape.setTexture(*texture);
	this->shape.setScale(0.7,0.7);
	}	
	~Player(){	}	
};
class Enemy{
public:
	Sprite shape;
	Texture *texture;
	Enemy(Texture *texture, RenderWindow &window){
		this->texture = texture;
		this->shape.setTexture(*texture);
		this->shape.setScale(0.1,0.1);
		this->shape.setPosition(window.getSize().x- this->shape.getGlobalBounds().width , rand()% int(window.getSize().y - this->shape.getGlobalBounds().height));
	}	
};

int main()
{
	srand(time(NULL));
	RenderWindow window(VideoMode(1400,1000),"GO Corona Go");
	window.setFramerateLimit(60);
	
	
	Font font;
	if(! font.loadFromFile("fonts/testfont.ttf"))
		throw"doesn't load font";
	
	Texture playertex;
	if(!playertex.loadFromFile("images/spaceship.png"))
		throw "couldnot load picture"; 	
	
	Texture enemytex;
	//playertex.setScale(Vector2f(0.1,0.1));
	if(!enemytex.loadFromFile("images/alien.png"))
		throw "couldnot load picture"; 	
		
	Texture bullettex;
	if(!bullettex.loadFromFile("images/misile.png"))
		throw "couldnot load picture"; 	
		
		///background
		Image img;
		if(!img.loadFromFile("images/img.jpg"))
		throw "couldnot load picture"; 	
		Texture tex;
		tex.loadFromImage(img);

  		Sprite pic(tex);
		pic.setTexture(tex);
		pic.setScale(Vector2f(5,5));
		
		
	
	//score	
	int score =0;
  Text text, gameover;
  text.setFont(font);
  text.setColor(Color::Red);
	text.setPosition(10,10);

 gameover.setFont(font);
 gameover.setString("Game over");
 gameover.setStyle(Text::Bold);
 gameover.setColor(Color::Red);
 gameover.setPosition(window.getSize().x/2,window.getSize().y/2);

	  //init player
	Player player(&playertex);
	int shoottime =12;
	//int	keytime = 1;
	int enemyspan =30;
	int maskspan = 100;
	
	
		//lifebar
		int life =10;
	RectangleShape lb;
	lb.setFillColor(Color::Green);
	lb.setPosition(window.getSize().x/2,10);
	
 //init corona or enemy
	std::vector<Enemy> enemies;
	
	//mask
	Texture m;
	Sprite mask;
	mask.setScale(Vector2f(0.5,0.5)); 
	if(!m.loadFromFile("images/repair.png"))
	  	throw "couldnot load picture";
	
	mask.setTexture(m);
	std::vector<Sprite> masks;
	
	while(window.isOpen())
	{
		
		Event event;
		
		while(window.pollEvent(event))
		{
		if (event.type == Event::Closed)
               window.close();
       
			if(event.KeyPressed && event.key.code == Keyboard::Escape)
			window.close();	
		}

  if(life > 0)
  {
		//update
		//player_update
		//if(keytime <1)
		//	keytime++;
			
			if( Keyboard::isKeyPressed(Keyboard::W)){  //keytime == 1 &&
			//	keytime ==0;
				player.shape.move(0,-10);
			}
			if( Keyboard::isKeyPressed(Keyboard::S)){
				//keytime ==0;
				player.shape.move(0,10);
			}
			
		if(player.shape.getPosition().y > window.getSize().y - player.shape.getGlobalBounds().height){
		player.shape.setPosition(0, window.getSize().y - player.shape.getGlobalBounds().height);
		}
		if(player.shape.getPosition().y < 0 ){
			player.shape.setPosition(0, 0);
		}
		
		//update bullets
		if(shoottime < 12)
		     shoottime++;
		 
		if(Mouse::isButtonPressed(Mouse::Left) && shoottime >=12 )
		{
				player.bullets.push_back(Bullet(&bullettex,player.shape.getPosition()));
			     shoottime = 0;
		
		}
		
		
		for(size_t i=0 ; i<player.bullets.size();i++)
		{
			//move bullets
			player.bullets[i].shape.move(20.f ,0.f);
			
			
			if(player.bullets[i].shape.getPosition().x >= window.getSize().x){
				player.bullets.erase(player.bullets.begin() + i);
				break;
			}
			
			/////collision of corona and bullet/sanitizer
			for(int k = 0 ; k<enemies.size();k++)
			{
			if(player.bullets[i].shape.getGlobalBounds().intersects(enemies[k].shape.getGlobalBounds()))
				{
					enemies.erase(enemies.begin() + k );
					player.bullets.erase(player.bullets.begin() + i);
					score++;
					break;
				}	
			}
		}
		//update score
	 std::stringstream ss;
	 ss << score<<std::endl;
	 std:: string newString = ss.str();
	 text.setString("score:"  + newString);
		
		
		//update covid or enemy
		//update covids
		if(enemyspan < 30)
			enemyspan++;
			
			if(enemyspan >= 30 ){
			enemies.push_back(Enemy(&enemytex, window));
			enemyspan = 0;
		}
	
		for(int i = 0; i< enemies.size(); i++){
			enemies[i].shape.move(-10,0);
			
			if(enemies[i].shape.getPosition().x <= 0 ){
		 		enemies.erase(enemies.begin() + i );
		 		life--;
		 		break;
			 }
			 if(enemies[i].shape.getGlobalBounds().intersects(player.shape.getGlobalBounds()) ){
			 	life --;
		 		enemies.erase(enemies.begin() + i );
		 		break;
		 		 //player damage
			 }	
				 			 
		}
		
		///mask update
		if(maskspan < 100)
		maskspan++;
			 
		if(maskspan >= 100 ){
			mask.setPosition(window.getSize().x- mask.getGlobalBounds().width , rand()% int(window.getSize().y - mask.getGlobalBounds().height));
			masks.push_back(Sprite(mask));
			maskspan = 0;
		}
		for(int i = 0; i< masks.size(); i++){
			masks[i].move(-15,0);
			
				if(masks[i].getPosition().x <= 0 ){
		 		masks.erase(masks.begin() + i );
		 		break;
			}
			if(masks[i].getGlobalBounds().intersects(player.shape.getGlobalBounds()) ){
				if(life<10)
			 		life ++;
		 		masks.erase(masks.begin() + i );
		 		break;
			 }	
	}
		
			
	
	//lifebar update
	  lb.setSize(Vector2f( life * 20 , 20)); 
			if(lb.getSize().x <= 100){
			 lb.setFillColor(Color::Red);
			 } if(lb.getSize().x > 100)
			    lb.setFillColor(Color::Green);
			

	}
		window.clear();
		//draw-------------------------------------------
		window.draw(pic);
		
		//player
		window.draw(player.shape);
		
		//sanitizer
		for(int i =0 ; i<player.bullets.size(); i++)
		{
			window.draw(player.bullets[i].shape);
		}
		//enemies/corona
		for(int i =0 ; i<enemies.size(); i++)
		{
			window.draw(enemies[i].shape);
		}
		//mask
		for(int i =0 ; i<masks.size(); i++)
		{
			window.draw(masks[i]);
		}
		window.draw(text);
		window.draw(lb);
		if(lb.getSize().x <= 0){
			 window.draw(gameover);
			 }
			 
		
		window.display();
	
	}
	
	return 0;	
}
