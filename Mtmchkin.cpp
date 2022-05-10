//
// Created by teich on 04/05/2022.
//

#include "Mtmchkin.h"

Mtmchkin::Mtmchkin(const char *playerName, const Card *cardsArray, int numOfCards):
    m_player(Player(playerName)),
    m_cardsArray(cardsArray),
    m_numOfCards(numOfCards),
    m_gameStatus(GameStatus::MidGame),
    m_currentCard(cardsArray[0]),
    m_currentIndex(0)
{}

void Mtmchkin::playNextCard() {
    m_currentCard.printInfo();
    m_currentCard.applyEncounter(m_player);
    m_player.printInfo();
    m_currentCard = m_cardsArray[++m_currentIndex%m_numOfCards];
    updateStatus(m_gameStatus);

}
bool Mtmchkin::isOver(){
    return (m_player.isKnockedOut() || m_player.getLevel()==MAX_LEVEL);
}


GameStatus Mtmchkin::getGameStatus() const {
    return m_gameStatus;
}


void Mtmchkin::updateStatus(GameStatus gameStatus) {
    if (m_player.isKnockedOut()){
        m_gameStatus = GameStatus::Loss;
    }
    else if(m_player.getLevel()==MAX_LEVEL) {
        m_gameStatus = GameStatus::Win;
    }
}


