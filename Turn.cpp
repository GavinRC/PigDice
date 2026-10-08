#include "Turn.h"
#include <iostream>
Turn::Turn() {
    m_turnCount = 1;
    m_scoreThisTurn = 0;
    m_turnOver = false;
    m_choice = 'h';
}

int Turn::getTurnCount() const {
    return m_turnCount;
}

int Turn::getScoreThisTurn() const {
    return m_scoreThisTurn;
}

void Turn::takeTurn() {
    std::string response;
    std::cout << "TURN " << m_turnCount << " - Game Score: " << 0 <<std::endl; // TODO: Use a ptr to get game score instead of 0
    while (m_turnOver == false) {
        std::cout << "roll or hold? (r/h): ";
        std::cin >> response;
        if (response == "r") {
            roll();
        } else if (response == "h") {
            m_turnOver = true;
        }
    }
    std::cout << "Score Banked This Turn: " << m_scoreThisTurn << "\n" << std::endl;
    // gs.game_score += gs.score_this_turn; TODO: move this into PDGame
    // resetTurnOver(); // TODO: move this into PDGame
}

void Turn::resetTurnOver() {
    m_turnOver = false;
    m_turnCount++;
    resetScoreThisTurn();
}

void Turn::resetScoreThisTurn() {
    m_scoreThisTurn = 0;
}

void Turn::roll() {
    m_myDie.rollDie();
    int randomNumber = m_myDie.getDieValue();
    std::cout << "Die: " << randomNumber;
    if (randomNumber == 1) {
        std::cout << "\nTurn over. No score." << std::endl;
        m_turnOver = true;
        resetScoreThisTurn();
        return;
    }
    m_scoreThisTurn += randomNumber;
    std::cout << " - Running score this turn: " << m_scoreThisTurn << std::endl;
}
