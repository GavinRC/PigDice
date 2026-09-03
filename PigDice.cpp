#include <functional>
#include <iostream>

// Build your solution starting from this code.
struct GameState {
    int turn_count = 0;
    int game_score = 0;
    int score_this_turn = 0;
    bool game_over = false;
};

static void takeTurn(GameState &gs);
static int roll();
static void playGame(GameState &gs);
static void display_rules();

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
    while (!gs.game_over) {
        takeTurn(gs);
        if (gs.game_score >= 20) {
            std::cout << "You finished with a final score of " << gs.game_score << " in " << gs.turn_count << " turns! \nThanks for playing PIG Dice!" << std::endl;
            break;
        }
    }
}

void takeTurn(GameState &gs) {
    std::pmr::string response;
    std::cout << "TURN " << gs.turn_count << " - Game Score: " << gs.game_score <<std::endl;
    while (true) {
        std::cout << "roll or hold? (r/h):";
        // getline(std::cin, response);
        std::cin >> response;
        if (response == "r") {
            int rnumber = roll();
            gs.score_this_turn += rnumber;
            std::cout << "Die: " << rnumber << " - Running score this turn: " << gs.score_this_turn <<std::endl;
            if (rnumber == 1) {
                std::cout << "Turn over. No score." << std::endl;
                gs.score_this_turn = 0;
                break;
            }
        } else if (response == "h") {
            break;
        }
    }
    std::cout << "Score Banked This Turn: " << gs.score_this_turn << "\n" << std::endl;
    gs.turn_count++;
    gs.game_score += gs.score_this_turn;
    gs.score_this_turn = 0;
}

int roll() {
    return (rand() % 6 + 1);
}

int main() {
    srand(time(nullptr));
    GameState my_game; // instantiate a GameState object
    display_rules(); // call the display_rules function
    playGame(my_game);
    //play_game(my_game); // call the play_game function and pass the GameState object
    return 0;
}

