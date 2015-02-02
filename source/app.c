#include <3ds.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "app.h"
#include "draw.h"
#include "input.h"
#include "rendering.h"
#include "gui.h"

//BLUE == player 1
//RED == player 2

//Vars
int player = 1;
int mode = 0;
int sound = 0;

//Score
int p1score = 0;
int p2score = 0;
int winner = 0;

//Popups
bool resetPopup = false;
bool prova = false;

//Game array
int game[3][3];

//Variable reset
void variableReset()
{
	int y;
	int x;
	player = 1;
	for (y = 0; y < 3; y++)
	{
		for (x = 0; x < 3; x++)
		{
			game[x][y] = 0;
		}
	}
	winner = 0;
}

void app()
{
	//RESET POPUP
	if (input & KEY_UP) resetPopup = true;
	//If you tap yes then it resets 
	if ((((posX >= 50 && posX <= 141) && (posY >= 151 && posY <= 179)) || input & KEY_A) && resetPopup == true)
	{
		variableReset();
		resetPopup = false;
	}
	//If you tap No
	if ((((posX >= 167 && posX <= 257) && (posY >= 151 && posY <= 179)) || input & KEY_B) && resetPopup == true)
	{
		resetPopup = false;
	}


	//APP CODE (Only if there isn't a winner

	if (winner == 0)
	{
		//TOUCH INPUT CHECK
		if ((posX >= 64 && posX <= 122) && (posY >= 26 && posY <= 84))
		{
			if (game[0][0] == 0)
			{
				game[0][0] = player;
				nextPlayer();
			}
		}
		else if ((posX >= 128 && posX <= 190) && (posY >= 26 && posY <= 84))
		{
			if (game[1][0] == 0)
			{
				game[1][0] = player;
				nextPlayer();
			}
		}
		else if ((posX >= 195 && posX <= 257) && (posY >= 26 && posY <= 84))
		{
			if (game[2][0] == 0)
			{
				game[2][0] = player;
				nextPlayer();
			}
		}
		else if ((posX >= 64 && posX <= 122) && (posY >= 89 && posY <= 155))
		{
			if (game[0][1] == 0)
			{
				game[0][1] = player;
				nextPlayer();
			}
		}
		else if ((posX >= 128 && posX <= 190) && (posY >= 89 && posY <= 155))
		{
			if (game[1][1] == 0)
			{
				game[1][1] = player;
				nextPlayer();
			}
		}
		else if ((posX >= 195 && posX <= 257) && (posY >= 89 && posY <= 155))
		{
			if (game[2][1] == 0)
			{
				game[2][1] = player;
				nextPlayer();
			}
		}
		else if ((posX >= 64 && posX <= 122) && (posY >= 162 && posY <= 219))
		{
			if (game[0][2] == 0)
			{
				game[0][2] = player;
				nextPlayer();
			}
		}
		else if ((posX >= 128 && posX <= 190) && (posY >= 162 && posY <= 219))
		{
			if (game[1][2] == 0)
			{
				game[1][2] = player;
				nextPlayer();
			}
		}
		else if ((posX >= 195 && posX <= 257) && (posY >= 162 && posY <= 219))
		{
			if (game[2][2] == 0)
			{
				game[2][2] = player;
				nextPlayer();
			}
		}

		//CHECK FOR A WINNER
		if (checkGameState())
		{
			winner = player;
			if (player == 1) p1score++;
			else p2score++;
		}
	}
}

void printGUI()
{
	//Prints the GUI depending on the active mode
	guiTop(player, p1score, p2score);
	guiBottom(game, winner);

	//Popup
    if (resetPopup) guiPopup("RESET", "Are you sure that you want to reset?", " ", " ", "Yes (A)", "No (B)", false);
}

void nextPlayer()
{
	if (player == 1) player = 2;
	else player = 1;
}

bool checkGameState()
{
	bool end = false;
	if ((game[0][0] == 1 && game[1][1] == 1 && game[2][2] == 1) ||
		(game[2][0] == 1 && game[1][1] == 1 && game[0][2] == 1) ||
		(game[0][0] == 1 && game[0][1] == 1 && game[0][2] == 1) ||
		(game[0][0] == 1 && game[1][0] == 1 && game[2][0] == 1) ||
		(game[2][0] == 1 && game[2][1] == 1 && game[2][2] == 1) ||
		(game[2][2] == 1 && game[1][2] == 1 && game[1][2] == 1) ||
		(game[0][1] == 1 && game[1][1] == 1 && game[1][2] == 1) ||
		(game[0][1] == 1 && game[1][1] == 1 && game[2][1] == 1) ||
		(game[0][0] == 2 && game[1][1] == 2 && game[2][2] == 2) ||
		(game[2][0] == 2 && game[1][1] == 2 && game[0][2] == 2) ||
		(game[0][0] == 2 && game[0][1] == 2 && game[0][2] == 2) ||
		(game[0][0] == 2 && game[1][0] == 2 && game[2][0] == 2) ||
		(game[2][0] == 2 && game[2][1] == 2 && game[2][2] == 2) ||
		(game[2][2] == 2 && game[1][2] == 2 && game[1][2] == 2) ||
		(game[0][1] == 2 && game[1][1] == 2 && game[1][2] == 2) ||
		(game[0][1] == 2 && game[1][1] == 2 && game[2][1] == 2)) end = true;

	return end;
}