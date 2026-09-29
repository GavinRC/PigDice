#include "DIE.h"
#include <random>

Die::Die() { // default constructor
    m_numOfSides = 6;
    m_dieValue = 0;
    rollDie();
}
void Die::rollDie() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, m_numOfSides);
    m_dieValue = dis(gen);
}

void Die::setNumberOfSides(int numberOfSides) {
    switch (numberOfSides) {
        case 2:
            m_numOfSides = 2;
            break;
        case 4:
            m_numOfSides = 4;
            break;
        case 8:
            m_numOfSides = 8;
            break;
        case 12:
            m_numOfSides = 12;
        default:
            m_numOfSides = 6;
    }
}
int Die::getDieNumber() const {
    return m_dieValue;
}

int Die::getNumberOfSides() const {
    return m_numOfSides;
}