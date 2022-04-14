#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>


const float GRV(0.0001);
bool hooked(true);
float vsp(0);
float hsp(0.5);
sf::RectangleShape player = sf::RectangleShape();
float xHook(750);
int gameScore(0);

int main() {
    sf::RenderWindow window(sf::VideoMode(1500, 500), "Square Jump 2022 Edition (FREE!)");

    player.setFillColor(sf::Color::Cyan);
    player.setSize(sf::Vector2<float>(50, 50));
    player.setPosition(sf::Vector2<float>(window.getSize().x / 2, window.getSize().y / 2));

    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::KeyPressed) {
                switch (event.key.code) {
                case sf::Keyboard::Space:
                    hooked = !hooked;
                    if (!hooked) {
                        vsp = -0.1;
                    } else {
                        xHook = player.getPosition().x;
                        hsp = hsp > 0 ? 0.5 : -0.5;
                    }
                default:
                    break;
                }
            }
        }

        if (hooked) {
            vsp = 0;
            hsp -= player.getPosition().x > xHook ? 0.001 : -0.001;
        } else {
            vsp += GRV;
        }

        player.setPosition(sf::Vector2<float>(player.getPosition().x + hsp, player.getPosition().y + vsp));
        player.setPosition(sf::Vector2<float>(player.getPosition().x - 0.1, player.getPosition().y));
        xHook -= 0.1;

        window.clear();
        window.draw(player);
        window.display();
        
        gameScore++;

        if (player.getPosition().x < 0 || player.getPosition().y > 500 || player.getPosition().y < 0) {
            std::cout << "////////////////////////////\nYour score was: " << gameScore << "\n////////////////////////////";
            window.close();
        }
    }

    std::cout << "\n\nthis sucks balls lmao";

    return 0;
}