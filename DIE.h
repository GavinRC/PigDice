#ifndef PIGDICE_DIE_H
#define PIGDICE_DIE_H

class Die {
    int m_dieValue;
    int m_numOfSides;
public:
    Die();
    void rollDie();
    void setNumberOfSides(int numberOfSides);
    int getDieNumber() const;
    int getNumberOfSides() const;
};


#endif //PIGDICE_DIE_H
