#ifndef PIGDICE_PDGAME_H
#define PIGDICE_PDGAME_H
#include "Turn.h"

class PDGame {
    Turn m_myTurn;
    bool m_gameOver;
    int m_gameScore;

public:
    PDGame();
    int getGameScore() const;
private:
    static void displayRules();
    void playGame();
};


#endif //PIGDICE_PDGAME_H
