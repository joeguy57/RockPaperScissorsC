/**
 * This program simulates a game of Rock, Paper, Scissors.
 * Here the user can input the choice made and compare it to the random choice
 * that the computer will compare it too.
 *
 * Function Descriptions and further documentation is in runGame.h
 * Created By: Joseph Menezes
 * Started on: 23/09/2020
 */

#include <stdio.h>
#include <stdlib.h>
#include "runGame.h"
#include <time.h>


void isWinner (int userScore , int compScore , int drawScore)
{
	if ( userScore < drawScore && compScore < drawScore )
	{
		printf ( "Game Over! You won %d rounds, computer won %d rounds, tied %d rounds\n IT'S A DRAW" , userScore
		         , compScore , drawScore );
	}//if
	else if ( userScore > compScore )
	{
		printf ( "Game Over! You won %d rounds, computer won %d rounds, tied %d rounds\nChampion: YOU" , userScore
		         , compScore , drawScore );
	}//else if
	else if ( userScore < compScore )
	{
		printf ( "Game Over! You won %d rounds, computer won %d rounds, tied %d rounds\nChampion: COMPUTER" , userScore
		         , compScore , drawScore );
	}//else if
}//isWinner

int isPoint (possibleMoves userMove , possibleMoves compMove)
{
	if ( userMove == compMove )
	{
		printf ( "You entered %s   Computer chose %s  TIE\n" , getString ( userMove ) , getString ( compMove ));
		return DRAW;
	}//if
	else if ((userMove == ROCK && compMove == SCISSORS) || (userMove == PAPER && compMove == ROCK) ||
	         (userMove == SCISSORS && compMove == PAPER))
	{
		printf ( "You entered %s   Computer chose %s  Winner is YOU\n" , getString ( userMove ) , getString (
				compMove ));
		return USER;
	}//else if
	else
	{
		printf ( "You entered %s  Computer chose %s  Winner is COMPUTER\n" , getString ( userMove ) , getString (
				compMove ));
		return COMP;
	}//else if
}//isPoint


int isValidMove (char userChoice)
{
	if ( userChoice == 'r' || userChoice == 'R' )
	{
		return ROCK;
	}//if
	else if ( userChoice == 's' || userChoice == 'S' )
	{
		return SCISSORS;
	}//else if
	else if ( userChoice == 'p' || userChoice == 'P' )
	{
		return PAPER;
	}//else if
	else
	{
		return INVALID;
	}//else
}//isValidMove

/**
 * runs while loop initialise the random number required
 */
int main ()
{
	//Variables
	possibleMoves userMove;
	possibleMoves compMove;
	int score[SCORE] = {0};
	//Games Size initialisation and user array set.
	int rounds = GAME_SIZE;
	char userInput[SIZE];
	//Seed for Random to be random everytime
	srand ( time (NULL));
	//Beginning static output lines
	printf ( "\nWelcome to ROCK PAPER SCISSORS game\n" );
	printf ( "-----------------------------------------------------------\n" );

	//Running the game
	while ( rounds > 0 )
	{
		compMove = (possibleMoves) (rand ( ) % 3); //Generate the Computers move
		printf ( "Please enter your choice: \"Rock\" , \"Paper\" , or \"Scissors\"" );
		scanf ( "%s" , userInput );
		userMove = (possibleMoves) isValidMove ( userInput[ 0 ] );
		if ( userMove != INVALID )
			//Need to check that input is a valid move if not prints error message and restarts the round
		{
			switch ( isPoint ( userMove , compMove ))
			{
				case USER:
					score[ USER ] += 1;
					break;
				case COMP:
					score[ COMP ] += 1;
					break;
				case DRAW:
					score[ DRAW ] += 1;
					break;
				default:
					break;
			}//switch
			printf ( "\n" );
			rounds--;
		}//if
		else
		{
			printf ( "Not sure of your selection. Try again.\n" );
		}//else
	}//while
	isWinner ( score[ USER ] , score[ COMP ] , score[ DRAW ] );
	//Running a loop until the enter character is pressed
	printf ( "\nPress [Enter] to close the terminal ..." );
	while ( getchar ( ) != '\n' );
	getchar ( );
	exit ( 0 );
}//main

