#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>

struct GameState {
    int turn_count = 1;
    int game_score = 0;
    int score_this_turn = 0;
    bool turn_over = false;
};

class Die {
    int m_value;
    int m_numberOfSides;
public:
    Die() { // default constructor
        m_numberOfSides = 6;
        m_value = 0;
    }
    Die(int numberOfSides) {
        m_numberOfSides = numberOfSides;
        m_value = 0;
    }
    void rollDie() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(1, m_numberOfSides);
        m_value = dis(gen);
    }

    void setNumberOfSides(int numberOfSides) {
        switch (numberOfSides) {
            case 4:
                m_numberOfSides = 4;
                break;
            case 6:
                m_numberOfSides = 6;
                break;
            case 8:
                m_numberOfSides = 8;
                break;
            default:
                m_numberOfSides = 6;
        }
    }
    int getDieNumber() {
        return m_value;
    }
};
static void takeTurn(GameState &gs);
static int roll();
static void playGame(GameState &gs);
static void display_rules();
static void hold(GameState &gs);

void display_rules() {
    std::cout << "Let's Play PIG Dice!\n"
            "\n"
            "* See how many turns it takes you to get to 20 points.\n"
            "* Turn ends when you hold or roll a 1.\n"
            "* If you roll a 1, you lose all points for the turn.\n"
            "* If you hold, you bank all points for the turn to the game score.\n"
    << std::endl;
}

void playGame(GameState &gs) {
    while (true) {
        takeTurn(gs);
        if (gs.game_score >= 20) {
            std::cout << "You finished with a final score of " << gs.game_score << " in " << gs.turn_count << " turns! \nThanks for playing PIG Dice!" << std::endl;
            break;
        }
        gs.turn_count++;
    }
}

void takeTurn(GameState &gs) {
    std::pmr::string response;
    std::cout << "TURN " << gs.turn_count << " - Game Score: " << gs.game_score <<std::endl;
    while (gs.turn_over == false) {
        std::cout << "roll or hold? (r/h): ";
        std::cin >> response;
        if (response == "r") {
            int randomNumber = roll();
            gs.score_this_turn += randomNumber;
            std::cout << "Die: " << randomNumber;
            if (randomNumber == 1) {
                std::cout << "\nTurn over. No score." << std::endl;
                gs.score_this_turn = 0;
                gs.turn_over = true;
            }

            std::cout << " - Running score this turn: " << gs.score_this_turn << std::endl;
        } else if (response == "h") {
            hold(gs);
        }
    }
    std::cout << "Score Banked This Turn: " << gs.score_this_turn << "\n" << std::endl;
    gs.game_score += gs.score_this_turn;
    gs.score_this_turn = 0;
    gs.turn_over = false;
}

void hold(GameState &gs) {
    gs.turn_over = true;
}

int roll() {
    srand(time(nullptr));
    return (rand() % 6) + 1;
}

int main() {
    GameState my_game;
    Die myDie;
    myDie.rollDie();
    display_rules();
    playGame(my_game);
    return 0;
}