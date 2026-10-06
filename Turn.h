//
// Created by gavin on 10/6/2026.
//

#ifndef PIGDICE_TURN_H
#define PIGDICE_TURN_H
#include "DIE.h"

class Turn {
    int m_turnCount;
    int m_turnScore;
    bool m_turnOver;
    char m_choice;
    Die m_myDie;
public:
    Turn();
    //Turn(&);
    int getTurnCount();
    int getScoreThisTurn();
    void takeTurn();
    void resetTurnOver();
    void resetGameOver();
};


#endif //PIGDICE_TURN_H
