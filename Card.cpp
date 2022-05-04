//
// Created by teich on 04/05/2022.
//
#include "Card.h"
#include <iostream>
using std::cout;
using std::endl;
const char* LINE_DIVIDER  = "------------------------";


Card::Card(CardType type, const CardStats &stats) {
    m_effect = type;
    m_stats = stats;
}

void Card::applyEncounter(Player &player) const {
    switch (m_effect) {
        case CardType::Battle :
            if(player.getAttackStrength() >= m_stats.force){
                player.levelUp();
                player.addCoins(m_stats.loot);
                cout << "The player defeated the monster and won the loot! Hooray !" << endl;
                cout << LINE_DIVIDER << endl;
            }
            else{
                player.damage(m_stats.hpLossOnDefeat);
                cout << "The player loss to the monster and lost health points! Boo !" << endl;
                cout << LINE_DIVIDER << endl;
            }
            break;
        case CardType::Buff :
            if (player.pay(m_stats.cost)){
                player.buff(m_stats.buff);
            }
            break;
        case CardType::Heal :
            if (player.pay(m_stats.cost)){
                player.heal(m_stats.heal);
            }
            break;
        case CardType::Treasure :
            player.addCoins(m_stats.loot);
            break;
    }
}

void Card::printInfo() const {
    switch (m_effect) {
        case CardType::Battle :
            printBattleCardInfo(m_stats);
            break;
        case CardType::Buff :
            printBuffCardInfo(m_stats);
            break;
        case CardType::Heal :
            printHealCardInfo(m_stats);
            break;
        case CardType::Treasure :
            printTreasureCardInfo(m_stats);
            break;
    }
}
