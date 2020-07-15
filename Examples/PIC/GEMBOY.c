/*
 * File:   GEMBOY.c
 * Author: Saul
 *
 * Created on 13 de junio de 2018, 07:30 PM
 */

//what is this: is just a simple pong game :) controlled by a keypad
// working in pic 16f877a
// CONFIG

#pragma config FOSC = HS   // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF  // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF   // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF   // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF   // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF    // Flash Program Memory Code Protection bit (Code protection off)

#include <xc.h>

#define OLED_LOAD_DEFAULT_FONT
#include <uOledLib.h>

typedef struct
{
    uint8_t x, y;
} vector2;

//variables
uint8_t VerticalPosPlayer1;
uint8_t VerticalPosPlayer2;
uint8_t Score1, Score2;
vector2 BallPos, Aceleration;
uint8_t EleccionMenu;
uint8_t shouldDrawMenu;

const uint8_t pelota[] = {0x99, 0x3c, 0x73, 0x76, 0x3C, 0x99};

const uint8_t plate[] = {0XFF, 0XFF, 0X55, 0XFF, 0XFF, 0XD5};

const uint8_t plate2[] = {0X55, 0XFF, 0XFF, 0XD5, 0XFF, 0XFF};

//all renderer drawable things goes here
void DrawableArrow(uint8_t x, uint8_t y)
{
    uOLED_gotoxy(y, x);
    uOLED_DrawString(">");
    uOLED_ResetCoords();
}

//Esta funcion solo borra lo que habia en el caracter, deberia de ser parte del driver
void Menu()
{
    uOLED_gotoxy(1, 32);
    uOLED_DrawString("1 PLAYER");
    uOLED_ResetCoords();
    uOLED_gotoxy(2, 32);
    uOLED_DrawString("2 PLAYER");
    uOLED_ResetCoords();
    uOLED_gotoxy(3, 15);
    uOLED_DrawString(" CREDITS =3");
    uOLED_ResetCoords();
    DrawableArrow(15, 1);
}

void Credits()
{
    uOLED_ResetCoords();
    uOLED_DrawString("Saul acvs =3");
    while (1);
}

char GetButtonPressed()
{
    switch (PORTBbits)
    {
    case PORTBbits_t.RB0:
        return '1';
    case PORTBbits_t.RB1:
        return '2';
    case PORTBbits_t.RB2:
        return '3';
    case PORTBbits_t.RB3:
        return '4';
    }
}

//every thing that should be logic code must be looped and designed for that =3
void MenuLogic()
{
    //trabamos la ejecucion
    char key = GetButtonPressed();
    if (key == '1' && EleccionMenu > 1)
    {
        uOLED_CleanChar(15, EleccionMenu);
        EleccionMenu--;
        DrawableArrow(15, EleccionMenu);
    }
    else if (key == '2' && EleccionMenu < 3)
    {
        uOLED_CleanChar(15, EleccionMenu);
        EleccionMenu++;
        DrawableArrow(15, EleccionMenu);
    }
    else if (key == '3')
        shouldDrawMenu = 0;
}

void DrawScores()
{
    uOLED_gotoxy(0, 0);
    uOLED_DrawString("p1: ");
    // char tmp1= '0'+Score1;
    uOLED_Putchar('0' + Score1);
    uOLED_ResetCoords();
    uOLED_gotoxy(0, 90);
    //char tmp2= '0'+Score2;
    uOLED_DrawString("p2: ");
    uOLED_Putchar('0' + Score2);
    uOLED_ResetCoords();
}

void CleanUpRenderedScores()
{
    uint8_t col = 0;
    uOLED_gotoxy(0, 0);
    for (col = 0; col < 127; col++)
        uOLED_Send(0x00, 0);
    uOLED_ResetCoords();
}

void resetMatch()
{
    BallPos.x = 50;
    BallPos.y = 3;
    Aceleration.x = -1;
    Aceleration.y = -1;
    VerticalPosPlayer1 = 3;
    VerticalPosPlayer2 = 3;
}

void player1winner()
{
    Score1++;
    uOLED_ClearDisplay();
    DrawScores();
    resetMatch();
}

void player2winner()
{
    Score2++;
    uOLED_ClearDisplay();
    DrawScores();
    resetMatch();
}

void ConfigurePorts()
{
    TRISB = 0X00001111;
}

void MovePlayer(char *keyPressed, const char up, const char down, uint8_t *value)
{
    if (*keyPressed == up && VerticalPosPlayer1 > 2)
        *value--;
    else if (*keyPressed == down && VerticalPosPlayer1 < 6)
        *value++;
}

void main(void)
{
    EleccionMenu = 1;
    shouldDrawMenu = 1;
    ConfigurePorts();

    uOLED_Initialize();
    uOLED_ClearDisplay();
    Menu();
    while (1)
    {
        if (shouldDrawMenu)
            MenuLogic();
        else
        {
            uOLED_ClearDisplay();
            resetMatch();
            switch (EleccionMenu)
            {
            case 1: //one player
                uOLED_ResetCoords();
                uOLED_DrawString("not implemented");
                while (1)
                    ;
                break;
            case 2:
                DrawScores();
                while (1) //solamente para que no repita toda la iteracion anterior
                {
                    //Check the input for both players
                    if ((PORTB & 0X00001111) != 0) //THIS CHECKS FOR INPUT CHANGES
                    {
                        uOLED_DrawSprite(4, VerticalPosPlayer1, 0, 6, 2, 1, 1);
                        uOLED_DrawSprite(122, VerticalPosPlayer2, 0, 6, 2, 1, 1);
                        //for player 1
                        char keyprss = GetButtonPressed();
                        MovePlayer(keyprss, '1', '2', VerticalPosPlayer1);
                        MovePlayer(keyprss, '3', '4', VerticalPosPlayer2);
                    }
                    //All redraw things goes here
                    uOLED_DrawSprite(BallPos.x, BallPos.y, 0, 6, 6, 0, 1);
                    uOLED_DrawSprite(4, VerticalPosPlayer1, plate, 6, 2, 1, 0);
                    uOLED_DrawSprite(122, VerticalPosPlayer2, plate2, 6, 2, 1, 0);
                    //check colision for player 1
                    if (BallPos.x < 5 && (BallPos.y >= VerticalPosPlayer1 && BallPos.y <= VerticalPosPlayer1 + 1))
                        Aceleration.x = 1;
                    else if (BallPos.x > 116 && (BallPos.y >= VerticalPosPlayer2 && BallPos.y <= VerticalPosPlayer2 + 1))
                        Aceleration.x = -1;
                    else
                    {
                        //condicion de victoria
                        if (BallPos.x + 1 > 127)
                            player1winner();
                        else if (BallPos.x <= 1)
                            player2winner();
                    }
                    //Do the calcs for the ball and colision detection
                    BallPos.x += Aceleration.x;
                    BallPos.y += BallPos.x % 10 == 0 ? Aceleration.y : 0;
                    //dibujamos la bola despues de calcular su nueva
                    uOLED_DrawSprite(BallPos.x, BallPos.y, pelota, 6, 6, 0, 0);
                    if (BallPos.y + 1 > 7)
                        Aceleration.y = -1;
                    else if (BallPos.y <= 1)
                        Aceleration.y = 1;
                }
                break;
            case 3: //credits
                Credits();
                break;
            }
        }
    }
    while (1)
        ;
}
