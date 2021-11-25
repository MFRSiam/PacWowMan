//
// Created by mfrfo on 11/25/2021.
//

#include "GameState.h"

GameState::GameState(Game *game)
    :m_GameState(game){

}

NoCoinState::NoCoinState(Game *game): GameState(game){

}
Game* GameState::getGame() const {
    return m_GameState;
}
void NoCoinState::insertCoin() {

}

void NoCoinState::pressButton() {

}

void NoCoinState::moveStick(sf::Vector2i direction) {

}

void NoCoinState::update(sf::Time delta) {

}

void NoCoinState::draw(sf::RenderWindow &window) {

}

GetReadyState::GetReadyState(Game *game) : GameState(game) {

}

void GetReadyState::insertCoin() {

}

void GetReadyState::pressButton() {

}

void GetReadyState::moveStick(sf::Vector2i direction) {

}

void GetReadyState::update(sf::Time delta) {

}

void GetReadyState::draw(sf::RenderWindow &window) {

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

}

void LostState::insertCoin() {

}

void LostState::pressButton() {

}

void LostState::moveStick(sf::Vector2i direction) {

}

void LostState::update(sf::Time delta) {

}

void LostState::draw(sf::RenderWindow &window) {

}

WonState::WonState(Game *game) : GameState(game) {

}

void WonState::insertCoin() {

}

void WonState::pressButton() {

}

void WonState::moveStick(sf::Vector2i direction) {

}

void WonState::update(sf::Time delta) {

}

void WonState::draw(sf::RenderWindow &window) {

}
