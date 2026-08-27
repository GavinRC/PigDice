#include <iostream>

// Build your solution starting from this code.
using namespace std;
struct GameState {
    char choice;
    int turn_count = 0;
    int game_score = 0;
    int score_this_turn = 0;
    bool game_over = false;
    bool turn_over = false;
};
void takeTurn(GameState &gs);

void display_rules() {
    cout << "Let's Play PIG Dice!\n"
            "\n"
            "* See how many turns it takes you to get to 20 points.\n"
            "* Turn ends when you hold or roll a 1.\n"
            "* If you roll a 1, you lose all points for the turn.\n"
            "* If you hold, you bank all points for the turn to the game score.\n"
    << endl;
}

void playGame(GameState &gs) {
    takeTurn(gs);
}

void takeTurn(GameState &gs) {
    cout << "TURN " << gs.turn_count << endl;
}

int roll() {
    return (rand() % 6 + 1);
}

int main() {
    srand(time(0));
    GameState my_game; // instantiate a GameState object
    display_rules(); // call the display_rules function
    playGame(my_game);
    //play_game(my_game); // call the play_game function and pass the GameState object
    return 0;
}

