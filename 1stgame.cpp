/*
#include "SFML/Graphics.hpp"
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>

 using namespace sf;

void Update(int &keyTime, RectangleShape &square);
void Draw(RenderWindow &window, RectangleShape &square);

int main(){
	
int keyTime = 8;
 RenderWindow window(VideoMode(600,700),"Raj_Kumar");
 	window.setFramerateLimit(60);
 	
 	RectangleShape square(Vector2f(100,100));
 	square.setPosition(window.getSize().x/2,window.getSize().y/2);
 	//square.setFillColor(Color::Red);
 
 
 	
 	while(window.isOpen()){
 		
 		
 		Event event;
 		
 	 while(window.pollEvent(event))
        {
			if (event.type == Event::Closed)
                window.close();
        
			if(event.KeyPressed && event.key.code == Keyboard::Escape)
			window.close();
			 
		 }
		  Update(keyTime,square);
		  Draw(window, square);
	 
	 }
		
	return 0;
}
 void Update(int &keyTime, RectangleShape &square){
 	if(keyTime <8)
 		keyTime++;												 //&& keyTime >=5
 		
 	if(Keyboard::isKeyPressed(Keyboard::A) && square.getPosition().x > 0 )
 	{
 		square.move(-5, 0);
 		keyTime = 0;
	 }
if(Keyboard::isKeyPressed(Keyboard::D) && square.getPosition().x <600-square.getSize().x )
 	{
 		square.move(5, 0);
 		keyTime = 0;
	 }
if(Keyboard::isKeyPressed(Keyboard::W) && square.getPosition().y > 0 )
 	{
 		square.move(0, -5);
 		keyTime = 0;
	 }
if(Keyboard::isKeyPressed(Keyboard::S) && square.getPosition().y <700-square.getSize().y)
 	{
 		square.move(0, 5);
 		keyTime = 0;
	 }
if(Mouse::isButtonPressed(Mouse::Left) )
 	{
 		square.setFillColor(Color::White);
 		
	 }
	 else
	 square.setFillColor(Color::Red);
	 
	 

//if(Mouse::isButtonPressed(Mouse::Right) )
 //	{
 //		square.setFillColor(Color::Red);
 		
//	 }
	
 }

 void Draw(RenderWindow &window, RectangleShape &square){
 	
 	//window.clear(Color::Blue);
 	if(Mouse::isButtonPressed(Mouse::Right) )
 	{
 	window.clear(Color::White);
 		
	 }
	 else
	 window.clear(Color::Blue);
 	
 	window.draw(square);
 	
 	window.display();
 	
 } 
*/


