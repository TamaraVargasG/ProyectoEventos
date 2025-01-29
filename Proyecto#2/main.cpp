#include <SFML/Graphics.hpp> 
#include <iostream>          
#include <string> 
using namespace std;


int main() {
        
        sf::RenderWindow window(sf::VideoMode(1000, 800), "Fondo con SFML");

        
        sf::Texture backgroundTexture;
        if (!backgroundTexture.loadFromFile("fondo.jpg")) {
            return -1; 
        }

        sf::Sprite backgroundSprite;
        backgroundSprite.setTexture(backgroundTexture);

       
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
            }

         
            window.clear();

           
            window.draw(backgroundSprite);

            
            window.display();
        }

        return 0;
    
}
