/* Deadline's 2D SDL Template */
#define _DLCS_SDL 1
#include "new_pacman.h"
#define APP_NAME "Deadline's New Pacman Game"


#define EXTRALIFEBONUS 10000

#define PACMAN_NONE     0
#define PACMAN_DOT      1
#define PACMAN_POWER    2
#define PACMAN_CHERRY   3

#define PACMAN_WALL1    4
#define PACMAN_WALL2    5
#define PACMAN_WALL3    6
#define PACMAN_WALL4    7
#define PACMAN_WALL5    8
#define PACMAN_WALL6    9
#define PACMAN_WALL7    10
#define PACMAN_WALL8    11
#define PACMAN_WALL9    12
#define PACMAN_WALL10   13
#define PACMAN_WALL11   14
#define PACMAN_WALL12   15
#define PACMAN_WALL13   16
#define PACMAN_WALL14   17
#define PACMAN_WALL15   18
#define PACMAN_GHOSTGATE   19

#define PACMAN_LEFT 2
#define PACMAN_RIGHT 4
#define PACMAN_UP 8
#define PACMAN_DOWN 16

CSprite *Pacman;
CSprite *Ghost0;
CSprite *Ghost1;
CSprite *Ghost2;
CSprite *Ghost3;
CSprite *Eyes0;
CSprite *GhostBlue;
CSprite *Mouse;

int extralifecounter;
int lives;
int score;
int hiscore;
int mode;
int build_tool;
int players;
int level;
int ghostmode;

long ghostmodestarttime;
long deathmodestarttime;

#define normal 0
#define blue 1

#define start 0
#define play  1
#define build 2
#define death 3
#define gameover 4
#define levelup 5

unsigned int pacmatrix[41][33];

//CEntity *ena;
//CEntity *enb;

void CGame::UserInit() {
    zl("UserInit()");
    SDL->SpriteAdd("hank","gfx/pacman.bmp");
    //ena = new CEntity((char *)"Fred");
    //enb = new CEntity((char *)"Evil Pig");
    //ena->push_event(enb,G_ENTITY_ATTACK,va("%d",rand()%209+34),ena);
    //enb->push_event(ena,G_ENTITY_ATTACK,va("%d",rand()%209+34),enb);
}

void CGame::UserGFX() {
//  SDL->DrawMap();
    SDL->Write(10,10,(char *)" Deadline's New Pacman Game ",0);
    SDL->Write(10,24,(char *)" ABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789!@#$%^&*()[]{}\\/<>?,. Hi testing...",0);
    SDL->Write(10,38,(char *)" ABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789!@#$%^&*()[]{}\\/<>?,. Hi testing...",1);
}

void CGame::UserKeys() {
    switch(G_KEYDOWN) {

        case SDLK_SPACE:
            break;

        case SDLK_RETURN:
            if(SDL)
                if(!SDL->ToggleFullScreen())
                    G_QUIT=true;
            break;

        case SDLK_ESCAPE:
            G_QUIT=true;
            break;

        case SDLK_DOWN:
            // enb->push_event(ena,G_ENTITY_ATTACK,va((char *)"%d",rand()%10+4),0);
            break;

        case SDLK_UP:
            // ena->push_event(enb,G_ENTITY_ATTACK,va((char *)"%d",rand()%10+4),0);
            break;

        case SDLK_LEFT:
        case SDLK_RIGHT:
        case SDLK_F1:
        case SDLK_F2:
        case SDLK_F3:
        case SDLK_F4:
        case SDLK_F5:
        case SDLK_F6:
        case SDLK_F7:
        case SDLK_F8:
        case SDLK_F9:
        case SDLK_F10:
        case SDLK_F11:
        case SDLK_F12:
        case SDLK_KP_PLUS:
        case SDLK_KP_MINUS:
        default:
            break;
    }
}

int main(int argc, char *argv[]) {
    CGame *Game=new CGame((char *)APP_NAME,SGC_ALL);
    while(!Game->Loop());
    //dlcsm_delete(ena);
    //dlcsm_delete(enb);
    dlcsm_delete(Game);
    return(0);
}
