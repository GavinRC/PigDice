#ifndef PIGDICE_DIE_H
#define PIGDICE_DIE_H

class Die {
    int m_dieValue;
public:
    Die();
    void rollDie();
    int getDieValue() const;
};


#endif //PIGDICE_DIE_H
