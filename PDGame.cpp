#include "PDGame.h"
#include <iostream>

PDGame::PDGame() {
    m_gameOver = false;
    m_gameScore = 0;
    m_myTurn.setParentGame(this);
    displayRules();
    playGame();
}

void PDGame::displayRules() {
    std::cout << "Let's Play PIG Dice!\n"
            "\n"
            "* See how many turns it takes you to get to 20 points.\n"
            "* Turn ends when you hold or roll a 1.\n"
            "* If you roll a 1, you lose all points for the turn.\n"
            "* If you hold, you bank all points for the turn to the game score.\n"
    << std::endl;
}

void PDGame::playGame() {
    while (!m_gameOver) {
        m_myTurn.takeTurn();
        m_gameScore += m_myTurn.getScoreThisTurn();
        if (m_gameScore >= 20) {
            std::cout << "You finished with a final score of " << m_gameScore << " in " << m_myTurn.getTurnCount() << " turns! \nThanks for playing PIG Dice!" << std::endl;
            m_gameOver = true;
        }
        m_myTurn.resetTurnOver();
    }
}

int PDGame::getGameScore() const {
    return m_gameScore;
}