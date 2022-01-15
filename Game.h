//
// Created by mfrfo on 11/25/2021.
//

#ifndef SFML_VCPKG_PROJ_GAME_H
#define SFML_VCPKG_PROJ_GAME_H
#include <SFML/Graphics.hpp>
#include <fmt/core.h>
#include <array>
#include "GameState.h"

class Game{
public:
    Game();
    ~Game();
    void run();
    void changeGameState(GameState::State gameState);
    sf::Font& getFont();
    sf::Texture& getLogo();
    sf::Texture& getTexture();
private:
    sf::RenderWindow m_window;
    GameState* m_CurrentState;
    std::array<GameState* , GameState::Count> m_gameStates;
    sf::Font m_font;
    sf::Texture m_logo;
    sf::Texture m_texture;
};


#endif //SFML_VCPKG_PROJ_GAME_H
