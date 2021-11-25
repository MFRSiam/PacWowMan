//
// Created by mfrfo on 11/25/2021.
//

#include "Game.h"

Game::Game()
    :m_window(sf::VideoMode(640,480),"Bangla Man")
{
    m_gameStates[GameState::NoCoin] = new NoCoinState(this);
    m_gameStates[GameState::GetReady] = new GetReadyState(this);
    m_gameStates[GameState::Playing] = new PlayingState(this);
    m_gameStates[GameState::Won] = new WonState(this);
    m_gameStates[GameState::Lost] = new LostState(this);
    changeGameState(GameState::NoCoin);
}

Game::~Game(){
    for(GameState * gameState: m_gameStates){
        delete gameState;
    }
}

void Game::run() {
    while(m_window.isOpen()){
        sf::Event event;
        while(m_window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                m_window.close();
            }
            if(event.type == sf::Event::KeyPressed){
                if(event.key.code == sf::Keyboard::I){
                    m_CurrentState->insertCoin();
                }
                if(event.key.code == sf::Keyboard::S){
                    m_CurrentState->pressButton();
                }
                if(event.key.code == sf::Keyboard::Left){
                    m_CurrentState->moveStick(sf::Vector2i(-1,0));
                }
                if(event.key.code == sf::Keyboard::Right){
                    m_CurrentState->moveStick(sf::Vector2i(1,0));
                }
                if(event.key.code == sf::Keyboard::Up){
                    m_CurrentState->moveStick(sf::Vector2i(0,-1));
                }
                if(event.key.code == sf::Keyboard::Down){
                    m_CurrentState->moveStick(sf::Vector2i(0,1));
                }
            }
        }
        m_CurrentState->update(sf::seconds(1));
        m_window.clear();
        //Drawing Calls Here
        m_CurrentState->draw(m_window);
        m_window.display();
    }
}

void Game::changeGameState(GameState::State gameState) {
    m_CurrentState = m_gameStates[gameState];
}

