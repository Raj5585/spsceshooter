//#include "SFML/Graphics.hpp"
//#include "SFML/Graphics/Text.hpp"
//#include <SFML/Window.hpp>
//#include <SFML/System.hpp>
//#include <iostream>
//#include<string>
//#include<sstream>
//#include<math.h>
//#include<vector>
//#include <SFML/OpenGL.hpp>
//using namespace sf;
//
//
//
//int main()
//{
//	Image img;
//if (!img.loadFromFile("images/covac.jpg"))
//        throw"unable to load"  ; 
//        
//Texture tex;
//tex.loadFromImage(img);
// 
//Sprite pic(tex);
//pic.setTexture(tex);
//
//srand(time(NULL));
//RenderWindow window(VideoMode(img.getSize().x, img.getSize().y),"GO Corona Go");
//window.setFramerateLimit(60);
// 
//    sf::RectangleShape rect(sf::Vector2f(200,80));
//    rect.setPosition(window.getSize().x/2- rect.getSize().x/2,50);
//    rect.setFillColor(sf::Color(225,10,20,255));
//       
//       
//    sf::RectangleShape rect1(sf::Vector2f(200,80));
//    rect1.setPosition(window.getSize().x/2- rect1.getSize().x/2,150);
//    rect1.setFillColor(sf::Color(255,200,200,255));
//    
//    
//    
//    sf::RectangleShape rect2(sf::Vector2f(200,80));
//    rect2.setPosition(window.getSize().x/2 - rect2.getSize().x/2,250);
//     rect2.setFillColor(sf::Color(205,200,250,255));
//    
//     
//       
//	Font font;
//	if(! font.loadFromFile("fonts/testfont.ttf"))
//	throw"doesn't load font";
//	
//	Text text , text1, text2;
//	text.setFont(font);
//	text.setString("COVID CARE");
//	text.setPosition(Vector2f(rect.getPosition().x+20, rect.getPosition().y+20));
//	text.setOutlineThickness(2);
//	text.setOutlineColor(Color::Red);
//	text.setColor(Color::Green);
//
//text1.setFont(font);
//	text1.setString("HELPER BOT");
//	text1.setPosition(Vector2f(rect1.getPosition().x+20, rect1.getPosition().y+20));
//	text1.setOutlineThickness(2);
//	text1.setOutlineColor(Color::Red);
//	text1.setColor(Color::Green);
//	
//	text2.setFont(font);
//	text2.setString("GAME");
//	text2.setPosition(Vector2f(rect2.getPosition().x+40, rect2.getPosition().y+20));
//	text2.setOutlineThickness(2);
//	text2.setOutlineColor(Color::Red);
//	text2.setColor(Color::Green);
//
//
////closing window
//    while (window.isOpen())
//    {
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//			if (event.type == sf::Event::Closed)
//                window.close();
//        }
        //update(move rotate)
        
//        if(Mouse::isButtonPressed(Mouse::Left)){	
//		  float mpx = sf::Mouse::getPosition(window).x;
//		  float mpy = sf::Mouse::getPosition(window).y;
//
//	
//		if(rect.getGlobalBounds().contains(mpx))
//				{
//					 rect.setFillColor(Color::Yellow);
//				}	
//        
//        }

//	bool isSpriteHover(sf::RectangleShape rect, sf::Vector2f mp) 
//        {
//                if (rect.contains(mp)){
//                return true;
//                }
//                return false;
//        }
//        bool lunch()
//        
//    sf::Vector2f mp;
//    mp.x = sf::Mouse::getPosition(window).x;
//    mp.y = sf::Mouse::getPosition(window).y;
//    
//     if(isSpriteHover(rect.getGlobalBounds(), sf::Vector2f(event.mouseButton.x, event.mouseButton.y)) == true)
//         {
//                if(event.type == sf::Event::MouseButtonReleased &&  event.mouseButton.button == sf::Mouse::Left)
//                {
//                        window.create(sf::VideoMode(400, 200),"The button worked!");
//                }
//         }
//        if(window.IsSpriteClicked(pic, Mouse::Left) )
// 		{
// 		window.clear(sf::Color::Blue);
// 		RenderWindow window(sf::VideoMode(800, 900), "Raj2",Style::Default);
// 		
// 		 while (window.isOpen())
//    	{
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//			if (event.type == sf::Event::Closed)
//                window.close();
//		 }
//		
//	}
//	return 0;
//	
//	}
		
 
//    
//        window.clear();
//        
//        //Draw  
//        window.draw(pic);
//		window.draw(rect); 
//   	  	window.draw(rect1);   
//		window.draw(rect2);  
//		window.draw(text);
//		window.draw(text1);
//		window.draw(text2);
//        window.display();
//    }
//	
//    return 0;
//}


#include "SFML/Graphics.hpp"
#include "SFML/Graphics/Text.hpp"
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include<string>
#include<sstream>
#include<math.h>
#include<vector>
#include <SFML/OpenGL.hpp>



        bool isSpriteHover(sf::FloatRect sprite, sf::Vector2f mp) 
        {
                if (sprite.contains(mp)){
                return true;
                }
                return false;
        }


int main()
{       

	Image img;
if (!img.loadFromFile("images/covac.jpg"))
        throw"unable to load"  ; 
        
Texture tex;
tex.loadFromImage(img);
 
Sprite pic(tex);
pic.setTexture(tex);

 srand(time(NULL));

        sf::RenderWindow window;
        window.create(sf::VideoMode(img.getSize().x, img.getSize().y),"My first Visual Studio window!");
        window.setFramerateLimit(60);
        
        sf::Texture texture;
        if(!texture.loadFromFile("images/raj's mask.png"))
        {
                return 1;
        }
        sf::Sprite sprite;
        sprite.setTexture(texture);

        sf::Vector2f mp;
    mp.x = sf::Mouse::getPosition(window).x;
    mp.y = sf::Mouse::getPosition(window).y;



        while(window.isOpen())
        {
                sf::Event event;
                
                while(window.pollEvent(event))
                {
                        if(event.type == sf::Event::Closed)
                                window.close();                 
                
                        if(isSpriteHover(sprite.getGlobalBounds(), sf::Vector2f(event.mouseButton.x, event.mouseButton.y)) == true)
         {
                if(event.type == sf::Event::MouseButtonReleased &&  event.mouseButton.button == sf::Mouse::Left)
                {
                        window.create(sf::VideoMode(400, 200),"The button worked!");
                }
         }
        
             }
                window.clear(sf::Color::Black);

                sprite.setPosition(sf::Vector2f(50, 300));
                
                window.draw(sprite);
                window.draw(pic);
                
                window.display();

}
        
return 0;
}

