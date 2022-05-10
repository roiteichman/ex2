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

public:

    /*
     * C'tor of Player class
     *
     * @param name - The name of the player.
     * @param hp - The amount of the health point of the player, default is MAX_HP
     * @param force - The amount of the force of the player, default is STARTING_FORCE
     * @return
     *      A new Player.
    */
    explicit Player(const char* name, int hp = MAX_HP, int force = STARTING_FORCE);


    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    Player(const Player&) = default;
    ~Player() = default;
    Player& operator=(const Player& other_player) = default;


    /*
     * printInfo - print the info of the player: Name, Level, Force, HP, Coins
     *
     * @param
     * @return
     *      void
    */
    void printInfo();


    /*
     * levelUp - increase the level of the player by 1
     *
     * @param
     * @return
     *      void
    */
    void levelUp();


    /*
     * getLevel
     *
     * @param
     * @return
     *      the current level of the player
    */
    int getLevel() const;


    /*
     * buff - increase the force of the player by n
     *
     * @param -
     * @return
     *      void
    */
    void buff(int n);


    /*
     * heal - increase the health points of the player by the argument n
     *
     * @param
     * @return
     *      void
    */
    void heal(int n);


    /*
     * damage - decrease the health points of the player by the argument n
     *
     * @param
     * @return
     *      void
    */
    void damage(int n);


    /*
     * isKnockedOut - check the level of the health point of the player
     *
     * @param
     * @return
     *      true - if the health point of the player = 0
     *      false - else
    */
    bool isKnockedOut() const;


    /*
     * addCoins - increase the amount of the coins of the player by the argument n
     *
     * @param
     * @return
     *      void
    */
    void addCoins(int n);


    /*
     * pay - check if the player has enough coins to make payment
     *
     * @param
     * @return
     *      true - if he has
     *      false - if he has not
    */
    bool pay(int n);


    /*
     * getAttackStrength -
     *
     * @param
     * @return
     *      AttackStrength = level + force
     *
    */
    int getAttackStrength() const;

private:
    const char* m_name;
    int m_maxHP;
    int m_hp;
    int m_force;
    int m_level;
    int m_coins;

};

#endif //EX2_PLAYER_H
