#ifndef GUI_H
#define GUI_H

void guiTop(int player, int p1score, int p2score);
void guiBottom(int game[][3], int winner);
void guiClock();
void guiPopup(char* title, char* line1, char* line2, char* line3, char* button1, char* button2, bool closeonly);


#endif
