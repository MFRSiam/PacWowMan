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
    //virtual void handleInput() = 0;
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

private:
    sf::Text m_text;
    sf::Sprite m_sprite;
    bool m_displayText;
};


class GetReadyState : public GameState{
public:
    explicit GetReadyState(Game *game);
    void insertCoin() override;
    void pressButton() override;
    void moveStick(sf::Vector2i direction) override;
    void update(sf::Time delta) override;
    void draw(sf::RenderWindow &window) override;

private:
    sf::Text m_text;
};


class PlayingState : public GameState{
public:
    explicit PlayingState(Game *game);
    void insertCoin() override;
    void pressButton() override;
    void moveStick(sf::Vector2i direction) override;
    void update(sf::Time delta) override;
    void draw(sf::RenderWindow &window) override;

};


class LostState : public GameState{
public:
    explicit LostState(Game *game);
    void insertCoin() override;
    void pressButton() override;
    void moveStick(sf::Vector2i direction) override;
    void update(sf::Time delta) override;
    void draw(sf::RenderWindow &window) override;
private:
    sf::Text m_text;
    sf::Time m_countDown;
    sf::Text m_countDownText;
};


class WonState : public GameState{
public:
    explicit WonState(Game *game);
    void insertCoin() override;
    void pressButton() override;
    void moveStick(sf::Vector2i direction) override;
    void update(sf::Time delta) override;
    void draw(sf::RenderWindow &window) override;

private:
    sf::Text m_text;
};

#endif //SFML_VCPKG_PROJ_GAMESTATE_H
