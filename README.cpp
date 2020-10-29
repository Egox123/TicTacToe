#include <iostream>
#include "Header.h"


int main() {

    bool game_on = true;
    int turn = 0;
    std::string grid = reset();

    introduction();

    while (game_on) {       
        turn += 1;
        grid = playerInput(turn, grid);
        drawstatus(grid);

        if (chkWinner(grid)) { game_on = false; };
    }

    finish_game(turn);
    newRound(grid);
}
