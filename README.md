
#include <iostream>
#include "Header.h"


int player = 1;


//reset the status
std::string reset() 
{
    std::string reset = "_________";
    return reset;
}


void introduction() 
{ 

    std::cout << "Tic Tac Toe C++ Challenge\n .\n \n";    
    std::string default_status = "123456789";
    drawstatus(default_status);

    std::cout << "\n";
    std::cout << "\n";
}



std::string playerInput(int turn, std::string status) 
{
    int input;
    char mark;
    

    if (turn % 2 == 0) 
    {
        mark = 'X';
        player = 2;
    }

    else {
        mark = 'O';
    }

    std::cout << "Players " << player << " please enter a number between 1 and 9: ";
    getoverhere:
    std::cin >> input;
    if (input <1 || input >9 || status[input - 1] != '_')
    {
        std::cout << "Incorrect input.\n";
        goto getoverhere;
    }
    
    status[input - 1] = mark;
    return status;
}


void drawstatus(std::string status) 
{
    for (int k = 0; k < 9; k += 3) {
        std::cout << "|-|" << status[k] << "|-|" << status[k + 1] << "|-|" << status[k + 2] << "|-|\n";
    }
    std::cout << "\n";
}

bool chkWinner(std::string status) 
{
    for (int i = 0; i <= 9; i += 3) {
        if (status[i] == status[i + 1] && status[i + 1] == status[i + 2] && status[i] != '_') 
            return true;
        if (status[i] == status[i + 3] && status[i + 3] == status[i + 6] && status[i] != '_')  
            return true;
    }
    if (status[0] == status[4] && status[4] == status[8] && status[0] != '_') 
        return true;
    if (status[2] == status[4] && status[4] == status[6] && status[2] != '_') 
        return true;
    return false;
}


void finish_game(int turn) 
{
    std::string newRound;
    int player = 1;
    if (turn % 2 == 0) player = 2;     
    std::cout << "Player " << player << " is the winner!\n";
}

void newRound(std::string status)
{
    std::string newRoundData;
    std::cout << "Would you like to play another round? (y/n)"; std::cin >> newRoundData;
    if (newRoundData == "y" || "Y") { status == reset(); };
}
