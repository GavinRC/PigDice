#include "Turn.h"
#include <iostream>
#include "PDGame.h"
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
    std::cout << "TURN " << m_turnCount << " - Game Score: " << m_parentGame->getGameScore() << std::endl;
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

void Turn::setParentGame(PDGame* parentGame) {
    m_parentGame = parentGame;
}
