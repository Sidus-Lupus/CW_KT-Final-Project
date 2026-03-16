//CW KT Tic Tac Toe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//KT This is an array that stores the values of all board locations
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
    printf("you are X chose spots 0-8 (0 top right, 4 center, 8 bottom left.):");
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

//KT
void printGameBoard(char loc1, char loc2, char loc3, char loc4, char loc5, char loc6, char loc7, char loc8, char loc9);
    printf(" %c | %c | %c \n", loc1 loc2 loc3);
    printf("---|---|---");
    printf(" %c | %c | %c \n");
    printf("---|---|---");
    printf(" %c | %c | %c \n");

int main(){
    printGameBoard;


    return 0;
}