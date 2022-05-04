//
// Created by teich on 04/05/2022.
//

#include <string>
#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H

const int MAX_HP = 100;
const int STARTING_FORCE = 5;
const int STARTING_LEVEL = 1;
const int STARTING_COINS = 0;
const int MAX_LEVEL = 10;

class Player{
   const char* m_name;
   int m_level;
   int m_force;
   int m_maxHP;
   int m_hp;
   int m_coins;

public:
    Player() = default;
    explicit Player(const char* name, int hp = MAX_HP, int force = STARTING_FORCE);
    Player(const Player& player) = default;
    ~Player() = default;
    Player& operator=(const Player& player) = default;

    void printInfo();
    void levelUp();
    int getLevel() const;
    void buff(int n);
    void heal(int n);
    void damage(int n);
    bool isKnockedOut() const;
    void addCoins(int n);
    bool pay(int n);
    int getAttackStrength() const;
};

#endif //EX2_PLAYER_H
