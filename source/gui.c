#include <3ds.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "gui.h"
#include "draw.h"
#include "rendering.h"

//For Background
#include "bottom_bin.h"
#include "blueround_bin.h"
#include "redround_bin.h"
#include "blue_bin.h"
#include "red_bin.h"

//For time
#define SECONDS_IN_DAY 86400
#define SECONDS_IN_HOUR 3600
#define SECONDS_IN_MINUTE 60
int time = 0;

char buffer[100];

void guiTop(int player, int p1score, int p2score)
{
	//Background
	if (player==1) gfxDrawSprite(GFX_TOP, GFX_LEFT, (u8*)blueround_bin, 240, 400, 0, 0);
	else gfxDrawSprite(GFX_TOP, GFX_LEFT, (u8*)redround_bin, 240, 400, 0, 0);

	//Prints a blue rectangle!
	drawFillRect(0, 0, 399, 17, 0, 128, 255, screenTopLeft);

    //Prints the statusBar
	gfxDrawText(GFX_TOP, GFX_LEFT, NULL, "3DS Tic Tac Toe", 5, 238 - fontDefault.height * 1);
	guiClock();

	//Prints the score
	sprintf(buffer, "%d   :   %d", p1score, p2score);
	gfxDrawText(GFX_TOP, GFX_LEFT, NULL, buffer, 183, 240 - fontDefault.height * 14);
}

void guiBottom(int game[3][3], int winner)
{
	//Draw BackGround
	gfxDrawSprite(GFX_BOTTOM, GFX_LEFT, (u8*)bottom_bin, 240, 320, 0, 0);
	gfxDrawText(GFX_BOTTOM, GFX_LEFT, NULL, "Developed by AlbertoSONIC", 85, 240 - fontDefault.height * 15);

	//Draw icons
	if (game[0][0] == 1) gfxDrawSprite(GFX_BOTTOM, GFX_LEFT, (u8*)blue_bin, 46, 46, 67, 240 - 79);
	else if (game[0][0] == 2) gfxDrawSprite(GFX_BOTTOM, GFX_LEFT, (u8*)red_bin, 46, 46, 67, 240 - 79);

	if (game[1][0] == 1) gfxDrawSprite(GFX_BOTTOM, GFX_LEFT, (u8*)blue_bin, 46, 46, 131, 240 - 79);
	else if (game[1][0] == 2) gfxDrawSprite(GFX_BOTTOM, GFX_LEFT, (u8*)red_bin, 46, 46, 131, 240 - 79);

	if (game[2][0] == 1) gfxDrawSprite(GFX_BOTTOM, GFX_LEFT, (u8*)blue_bin, 46, 46, 198, 240 - 79);
	else if (game[2][0] == 2) gfxDrawSprite(GFX_BOTTOM, GFX_LEFT, (u8*)red_bin, 46, 46, 198, 240 - 79);

	if (game[0][1] == 1) gfxDrawSprite(GFX_BOTTOM, GFX_LEFT, (u8*)blue_bin, 46, 46, 67, 240 - 150);
	else if (game[0][1] == 2) gfxDrawSprite(GFX_BOTTOM, GFX_LEFT, (u8*)red_bin, 46, 46, 67, 240 - 150);

	if (game[1][1] == 1) gfxDrawSprite(GFX_BOTTOM, GFX_LEFT, (u8*)blue_bin, 46, 46, 131, 240 - 150);
	else if (game[1][1] == 2) gfxDrawSprite(GFX_BOTTOM, GFX_LEFT, (u8*)red_bin, 46, 46, 131, 240 - 150);

	if (game[2][1] == 1) gfxDrawSprite(GFX_BOTTOM, GFX_LEFT, (u8*)blue_bin, 46, 46, 198, 240 - 150);
	else if (game[2][1] == 2) gfxDrawSprite(GFX_BOTTOM, GFX_LEFT, (u8*)red_bin, 46, 46, 198, 240 - 150);

	if (game[0][2] == 1) gfxDrawSprite(GFX_BOTTOM, GFX_LEFT, (u8*)blue_bin, 46, 46, 67, 240 - 214);
	else if (game[0][2] == 2) gfxDrawSprite(GFX_BOTTOM, GFX_LEFT, (u8*)red_bin, 46, 46, 67, 240 - 214);

	if (game[1][2] == 1) gfxDrawSprite(GFX_BOTTOM, GFX_LEFT, (u8*)blue_bin, 46, 46, 131, 240 - 214);
	else if (game[1][2] == 2) gfxDrawSprite(GFX_BOTTOM, GFX_LEFT, (u8*)red_bin, 46, 46, 131, 240 - 214);

	if (game[2][2] == 1) gfxDrawSprite(GFX_BOTTOM, GFX_LEFT, (u8*)blue_bin, 46, 46, 198, 240 - 214);
	else if (game[2][2] == 2) gfxDrawSprite(GFX_BOTTOM, GFX_LEFT, (u8*)red_bin, 46, 46, 198, 240 - 214);

	//IF THERE'S A WINNER - The winner number is inverted: 1 is red, 2 is blue
	if (winner == 1)
	{
		drawFillRect(100, 90, 210, 150, 255, 0, 0, screenBottom);
		gfxDrawText(GFX_BOTTOM, GFX_LEFT, NULL, "RED wins!", 130, 230 - fontDefault.height * 7);
		gfxDrawText(GFX_BOTTOM, GFX_LEFT, NULL, "Press UP to reset!", 110, 230 - fontDefault.height * 8);
	}
	else if (winner == 2)
	{
		drawFillRect(100, 90, 210, 150, 0, 0, 255, screenBottom);
		gfxDrawText(GFX_BOTTOM, GFX_LEFT, NULL, "BLUE wins!", 130, 230 - fontDefault.height * 7);
		gfxDrawText(GFX_BOTTOM, GFX_LEFT, NULL, "Press UP to reset!", 110, 230 - fontDefault.height * 8);
	}
}

void guiClock()
{
	u64 timeInSeconds = osGetTime() / 1000;
	u64 dayTime = timeInSeconds % SECONDS_IN_DAY;
	sprintf(buffer, "%llu:%llu:%llu", dayTime / SECONDS_IN_HOUR, (dayTime % SECONDS_IN_HOUR) / SECONDS_IN_MINUTE, dayTime % SECONDS_IN_MINUTE);

	gfxDrawText(GFX_TOP, GFX_LEFT, NULL, buffer, 350, 238 - fontDefault.height * 1);
}

void guiPopup(char* title, char* line1, char* line2, char* line3, char* button1, char* button2, bool closeonly)
{
	//Prints a dark grey rectangle!
	drawFillRect(36, 60, 272, 85, 128, 128, 128, screenBottom);
	//Prints a light grey rectangle!
	drawFillRect(36, 85, 272, 189, 160, 160, 160, screenBottom);
	//Prints text
	gfxDrawText(GFX_BOTTOM, GFX_LEFT, NULL, title, 124, 240 - fontDefault.height * 5);
	gfxDrawText(GFX_BOTTOM, GFX_LEFT, NULL, line1, 50, 245 - fontDefault.height * 7);
	gfxDrawText(GFX_BOTTOM, GFX_LEFT, NULL, line2, 50, 245 - fontDefault.height * 8);
	gfxDrawText(GFX_BOTTOM, GFX_LEFT, NULL, line3, 50, 245 - fontDefault.height * 9);
    //Prints the buttons!
	if (closeonly)
	{
        drawFillRect(107, 155, 198, 183, 192, 192, 192, screenBottom);
		gfxDrawText(GFX_BOTTOM, GFX_LEFT, NULL, button1, 130, 240 - fontDefault.height * 11);
	}
	else
	{
		drawFillRect(50, 151, 141, 179, 192, 192, 192, screenBottom);
	    drawFillRect(166, 151, 257, 179, 192, 192, 192, screenBottom);
		gfxDrawText(GFX_BOTTOM, GFX_LEFT, NULL, button1, 60, 240 - fontDefault.height * 11);
		gfxDrawText(GFX_BOTTOM, GFX_LEFT, NULL, button2, 180, 240 - fontDefault.height * 11);
	}	
}