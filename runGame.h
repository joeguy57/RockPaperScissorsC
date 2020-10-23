/*
 * Functions we will need:
 * isWinner() : Compares the score of the players and declares a winner
 * isPoint(): Decides whether user or computer gains a point
 * isValidMove(): Checks whether the user use a valid move.
 * getString(): retrieves the string of the enum constant entered
 *
 * Created By: Joseph Menezes
 * Started on: 23/09/2020
 */


#ifndef ROCKPAPERSCISSORS_RUNGAME_H
#define ROCKPAPERSCISSORS_RUNGAME_H

#define SIZE 100
#define GAME_SIZE 10
#define SCORE 3

typedef enum possibleMoves {
	ROCK , PAPER , SCISSORS , INVALID
} possibleMoves;
typedef enum possibleWins {
	USER , COMP , DRAW
} possibleWins;


 /**
  * Makes a comparison with userScore, compScore, drawScore and declares
  * the Champion or if it is a tie
  *
  * @param userScore - takes int stored in score[0] in order make comparison
  * @param compScore - takes int stored in score[1] in order to make comparison
  * @param drawScore - takes int stored in score[2] in order to make comparison
  */
void isWinner (int userScore , int compScore , int drawScore);

 /**
  * Registers the computers move and the user move once decided a point is declared
  * and added to the respected variable
  *
  * @param userMove -  enum dataType of what move the user made
  * @param compMove -  enum dataType of what move the computer made
  * @return integer identifying which player will get a point.
  */
int isPoint (possibleMoves userMove , possibleMoves compMove);

/** Takes the first character of a users input
 *  sees if the move is Valid either uppercase or lowercase
 *  Valid choice are 'R', 'r', 'p','P','s', 'S'
 * \param  userChoice
 * \return the enum value of the users choice
 */
 /**
  * Takes the first character of a users input sees if the move is Valid either uppercase or lowercase
  * Valid choice are 'R', 'r', 'p','P','s', 'S'
  * @param userChoice - first character for user input
  * @return the enum value of the users choice
  */
int isValidMove (char userChoice);

 /**
  *
  * @param moves - enum move of the particular user
  * @return string of what the constant represents
  */
const char *getString (enum possibleMoves moves)
{
	switch ( moves )
	{
		case ROCK:
			return "ROCK";
		case PAPER:
			return "PAPER";
		case SCISSORS:
			return "SCISSORS";
		default:
			return 0;
	}//switch
}//getString

#endif //ROCKPAPERSCISSORS_RUNGAME_H
