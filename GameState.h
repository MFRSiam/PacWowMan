//
// Created by mfrfo on 11/25/2021.
//

#ifndef SFML_VCPKG_PROJ_GAMESTATE_H
#define SFML_VCPKG_PROJ_GAMESTATE_H
#include <SFML/Graphics.hpp>
class Game;
class GameState {
public:
    enum State {
        NoCoin,
        GetReady,
        Playing,
        Won,
        Lost,
        Count
    };
    explicit GameState(Game *game);
    Game* getGame() const;
    virtual void handleInput() = 0;
    virtual void insertCoin() = 0;
    virtual void pressButton() = 0;
    virtual void moveStick(sf::Vector2i direction) = 0;
    virtual void update(sf::Time delta) = 0;
    virtual void draw(sf::RenderWindow &window) = 0;

private:
    Game *m_GameState;
};

class NoCoinState : public GameState{
public:
    explicit NoCoinState(Game *game);
    void insertCoin() override;
    void pressButton() override;
    void moveStick(sf::Vector2i direction) override;
    void update(sf::Time delta) override;
    void draw(sf::RenderWindow &window) override;

};


class GetReadyState : public GameState{
public:
    GetReadyState(Game *game);
    void insertCoin();
    void pressButton();
    void moveStick(sf::Vector2i direction);
    void update(sf::Time delta);
    void draw(sf::RenderWindow &window);

};


class PlayingState : public GameState{
public:
    PlayingState(Game *game);
    void insertCoin();
    void pressButton();
    void moveStick(sf::Vector2i direction);
    void update(sf::Time delta);
    void draw(sf::RenderWindow &window);

};


class LostState : public GameState{
public:
    LostState(Game *game);
    void insertCoin();
    void pressButton();
    void moveStick(sf::Vector2i direction);
    void update(sf::Time delta);
    void draw(sf::RenderWindow &window);

};


class WonState : public GameState{
public:
    WonState(Game *game);
    void insertCoin();
    void pressButton();
    void moveStick(sf::Vector2i direction);
    void update(sf::Time delta);
    void draw(sf::RenderWindow &window);

};

#endif //SFML_VCPKG_PROJ_GAMESTATE_H
