//CW KT Tic Tac Toe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char board_setup[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8'};

//CW This funciton checks to see if a player/computer move is a valid move
int checkLegalMove(int location){
    if (board_setup[location] != 'X' && board_setup[location] != 'O'){
        return 1;
    } else{
        return 0;
    }
}

//KT This function allows the player to select a location to move and updates that value in board_setup
int playerMove(){
    int store_player_move;
    printf("Choose a spot (0-8): ");
    scanf("%d", &store_player_move);
    if (checkLegalMove(store_player_move) == 1){
        board_setup[store_player_move] = 'X';
        return 0;
    } else {
        return 1;
    }
}

//CW This function allows the computer to randomly choose a location to move and updates that value in boatd_setup
int computerMove(){
    srand(time(NULL));
    int store_computer_move = (rand() % 9);
   if (checkLegalMove(store_computer_move) == 1){
    board_setup[store_computer_move] = 'O';
    return 0;
   } else{
    return 1;
   }
}

//KT the setup of the board
void printGameBoard(){
    printf(" %c | %c | %c \n", board_setup[0], board_setup[1], board_setup[2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board_setup[3], board_setup[4], board_setup[5]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board_setup[6], board_setup[7], board_setup[8]);
    printf(" \n");
}

void printWinner(char location){
    if (location == 'X'){
        printf("You win!\n");
    } else {
        printf("Computer wins.");
    }
}
//CW and KT This code checks if a win state or a tie has been reached
int checkWinner(){
    if (board_setup[0] == board_setup[1] == board_setup[2]){
        printWinner(board_setup[0]);
        return 0;
    } else if (board_setup[0] == board_setup[4] == board_setup[8]){
        printWinner(board_setup[0]);
        return 0;
    } else if (board_setup[0] == board_setup[3] == board_setup[6]){ 
        printWinner(board_setup[0]);
        return 0;
    } else if (board_setup[1] == board_setup[4] == board_setup[7]){
        printWinner(board_setup[2]);
        return 0;
    } else if (board_setup[2] == board_setup[5] == board_setup[8]){
        printWinner(board_setup[2]);
        return 0;
    } else if (board_setup[2] == board_setup[4] == board_setup[6]){
        printWinner(board_setup[2]);
        return 0;
    } else if (board_setup[3] == board_setup[4] == board_setup[5]){
        printWinner(board_setup[3]);
        return 0;
    } else if (board_setup[6] == board_setup[7] == board_setup[8]){
        printWinner(board_setup[6]);
        return 0;
    }else if (board_setup[0] != '0' && board_setup[1] != '1' && board_setup[2] != '2' && board_setup[3] != '3' && board_setup[4] != '4' && board_setup[5] != '5' && board_setup[6] != '6' && board_setup[7] != '7' && board_setup[8] != '8'){
        printf("Cat's Game...");
        return 0;
    } else{
        return 1;
    }
}

int main(){
    while (checkWinner() == 1){
        printGameBoard();
        while(playerMove() == 1){
        }
        if (checkWinner() == 0){
            break;
        }
        while (computerMove() == 1){
        }
    }
    printGameBoard();
    
    printf("END LINE");
    return 0;
}