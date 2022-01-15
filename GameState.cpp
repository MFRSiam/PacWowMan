//
// Created by mfrfo on 11/25/2021.
//

#include "GameState.h"
#include "Game.h"


//Utility Functions
template <typename T>
void centerOrigin(T& drawable){
    sf::FloatRect bound = drawable.getLocalBounds();
    drawable.setOrigin(bound.width/2, bound.height/2);
}



//Implementation Functions
GameState::GameState(Game *game)
    :m_GameState(game){

}

NoCoinState::NoCoinState(Game *game): GameState(game){
    m_sprite.setTexture(game -> getLogo());
    m_sprite.setPosition(20,50);

    m_text.setFont(game->getFont());
    m_text.setString("Insert Coin");
    centerOrigin(m_text);
    m_text.setPosition(240,150);
    m_displayText = true;
}



Game* GameState::getGame() const {
    return m_GameState;
}
void NoCoinState::insertCoin() {

}

void NoCoinState::pressButton() {
    getGame()->changeGameState(GameState::GetReady);
}

void NoCoinState::moveStick(sf::Vector2i direction) {

}

void NoCoinState::update(sf::Time delta) {
    static sf::Time timeBuffer = sf::Time::Zero;
    timeBuffer += delta;
    while(timeBuffer>=sf::seconds(0.5)){
        m_displayText = !m_displayText;
        timeBuffer -= sf::seconds(1);
    }
}

void NoCoinState::draw(sf::RenderWindow &window) {
    window.draw(m_sprite);
    if(m_displayText){
        window.draw(m_text);
    }
}

GetReadyState::GetReadyState(Game *game) : GameState(game) {
    m_text.setFont(game->getFont());
    m_text.setString("Press Start When You are Ready");
    m_text.setCharacterSize(14);
    centerOrigin(m_text);
    m_text.setPosition(240,240);

}

void GetReadyState::insertCoin() {

}

void GetReadyState::pressButton() {
    getGame()->changeGameState(GameState::Playing);
}

void GetReadyState::moveStick(sf::Vector2i direction) {
    if(direction.x == -1)
        getGame()->changeGameState(GameState::Lost);
    else if(direction.x == 1)
        getGame()->changeGameState(GameState::Won);


}

void GetReadyState::update(sf::Time delta) {

}

void GetReadyState::draw(sf::RenderWindow &window) {
    window.draw(m_text);
}

PlayingState::PlayingState(Game *game) : GameState(game) {

}

void PlayingState::insertCoin() {

}

void PlayingState::pressButton() {

}

void PlayingState::moveStick(sf::Vector2i direction) {

}

void PlayingState::update(sf::Time delta) {

}

void PlayingState::draw(sf::RenderWindow &window) {

}

LostState::LostState(Game *game) : GameState(game) {
    m_text.setFont(game->getFont());
    m_text.setString("You Lost");
    m_text.setCharacterSize(42);
    centerOrigin(m_text);
    m_text.setOrigin(240,240);
    m_countDownText.setFont(game->getFont());
    m_countDownText.setCharacterSize(12);
    centerOrigin(m_countDownText);
    m_countDownText.setPosition(240,240);
}

void LostState::insertCoin() {

}

void LostState::pressButton() {

}

void LostState::moveStick(sf::Vector2i direction) {

}

void LostState::update(sf::Time delta) {
    m_countDown += delta;
    if(m_countDown.asSeconds()>=10){
        getGame()->changeGameState(GameState::NoCoin);
    }
    m_countDownText.setString("Insert A Coin To Continue..."+ std::to_string(10- static_cast<int>(m_countDown.asSeconds())));
}

void LostState::draw(sf::RenderWindow &window) {

}

WonState::WonState(Game *game) : GameState(game) {
    m_text.setFont(game->getFont());
    m_text.setString("You Won");
    m_text.setCharacterSize(42);
    centerOrigin(m_text);
    m_text.setPosition(240,240);
}

void WonState::insertCoin() {

}

void WonState::pressButton() {

}

void WonState::moveStick(sf::Vector2i direction) {

}

void WonState::update(sf::Time delta) {
    static sf::Time timeBuffer = sf::Time::Zero;
    timeBuffer += delta;
    if(timeBuffer.asSeconds()>5){
        getGame()->changeGameState(GameState::GetReady);
    }
}

void WonState::draw(sf::RenderWindow &window) {
    window.draw(m_text);
}
