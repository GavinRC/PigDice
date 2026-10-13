//
// Created by gavin on 10/6/2026.
//

#ifndef PIGDICE_TURN_H
#define PIGDICE_TURN_H
#include "DIE.h"
class PDGame;
class Turn {
    int m_turnCount;
    int m_scoreThisTurn;
    bool m_turnOver;
    char m_choice;
    Die m_myDie;
    PDGame* m_parentGame = nullptr;
public:
    Turn();
    int getTurnCount() const;
    int getScoreThisTurn() const;
    void takeTurn();
    void resetTurnOver();
    void resetScoreThisTurn();
    void setParentGame(PDGame* parentGame);
private:
    void roll();
};


#endif //PIGDICE_TURN_H
