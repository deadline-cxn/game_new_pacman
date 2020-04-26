/***************************************************************
 **   DLSTORM   Deadline's Code Storm
 **          /\
 **   ---- D/L \----
 **       \/
 **   License:      BSD
 **   Copyright:    2020
 **   File:         new_pacman.cpp
 **   Description:  New Pacman Game
 **   Author:       Seth Parson aka Deadline
 **   Twitter:      @Sethcoder
 **   Website:      www.sethcoder.com
 **   Email:        defectiveseth@gmail.com
 **
 ***************************************************************/
#define _DLCS_SDL      1
#define _DLCS_APP_NAME "Deadline's New Pacman Game"
#include "new_pacman.h"
CGame *Game;

#define EXTRALIFEBONUS   10000
#define PACMAN_NONE      0
#define PACMAN_DOT       1
#define PACMAN_POWER     2
#define PACMAN_CHERRY    3
#define PACMAN_WALL1     4
#define PACMAN_WALL2     5
#define PACMAN_WALL3     6
#define PACMAN_WALL4     7
#define PACMAN_WALL5     8
#define PACMAN_WALL6     9
#define PACMAN_WALL7     10
#define PACMAN_WALL8     11
#define PACMAN_WALL9     12
#define PACMAN_WALL10    13
#define PACMAN_WALL11    14
#define PACMAN_WALL12    15
#define PACMAN_WALL13    16
#define PACMAN_WALL14    17
#define PACMAN_WALL15    18
#define PACMAN_GHOSTGATE 19
#define PACMAN_LEFT      2
#define PACMAN_RIGHT     4
#define PACMAN_UP        8
#define PACMAN_DOWN      16
#define normal           0
#define blue             1
#define start            0
#define play             1
#define build            2
#define death            3
#define gameover         4
#define levelup          5
int  extralifecounter;
int  lives;
int  score;
int  hiscore;
int  mode;
int  build_tool;
int  players;
int  level;
int  ghostmode;
long ghostmodestarttime;
long deathmodestarttime;

// unsigned int pacmatrix[41][33];
// CSprite *Eyes0;
// CSprite *GhostBlue;
// CSprite *Mouse;

void CGame::UserInit() {
    bShowConsole = true;
    ConsoleLog(_DLCS_APP_NAME);
    ConsoleLog(va("%s", dlcs_get_os_version()));
    ConsoleLog("Press F12 to toggle the console.");

    ActorAdd("Pacman");
    ConsoleLog("Pacman added");
    ActorAdd("Blinky");
    ActorAdd("Pinky");
    ActorAdd("Inky");
    ActorAdd("Clyde");

    Actor("Pacman")->LoadGAFSurface("gfx/pacman1.bmp");
    Actor("Pacman")->AnimationAdd("right");
    Actor("Pacman")->Animation("right")->FrameAdd(0, 0, 32, 32);
    Actor("Pacman")->Animation("right")->FrameAdd(32, 0, 32, 32);
    Actor("Pacman")->Animation("right")->animation_speed = 200;
    Actor("Pacman")->AnimationSet("right");

    Actor("Blinky")->LoadGAFSurface("gfx/blinky.bmp");
    Actor("Blinky")->AnimationAdd("right");
    Actor("Blinky")->Animation("right")->FrameAdd(0, 0, 32, 32);
    Actor("Blinky")->Animation("right")->FrameAdd(32, 0, 32, 32);
    Actor("Blinky")->Animation("right")->animation_speed = 200;
    Actor("Blinky")->AnimationSet("right");

    Actor("Pinky")->LoadGAFSurface("gfx/pinky.bmp");
    Actor("Inky")->LoadGAFSurface("gfx/inky.bmp");
    Actor("Clyde")->LoadGAFSurface("gfx/clyde.bmp");

    ActorMoveTo("Pacman", 100, 600);
    ActorMoveTo("Blinky", 200, 600);
    ActorMoveTo("Pinky", 300, 600);
    ActorMoveTo("Inky", 400, 600);
    ActorMoveTo("Clyde", 500, 600);

    // ena->push_event(enb,G_ENTITY_ATTACK,va("%d",rand()%209+34),ena);
    // enb->push_event(ena,G_ENTITY_ATTACK,va("%d",rand()%209+34),enb);
}

void CGame::UserGFX() {
    ActorMoveTo("Pacman", 100, 600);
    ActorDraw("Pacman");
    ActorMoveTo("Pacman", 100, 700);
    ActorDraw("Pacman");
    ActorDraw("Blinky");
    ActorDraw("Pinky");
    ActorDraw("Inky");
    ActorDraw("Clyde");
    //  SDL->DrawMap();
}

void CGame::UserMain() {
    // Wut
}

void CGame::UserKeys() {
    switch (G_KEYDOWN) {
        case SDLK_SPACE: break;

        case SDLK_RETURN:
            // if(SDL) if(!SDL->ToggleFullScreen()) G_QUIT=true;
            break;

        case SDLK_ESCAPE: G_QUIT = true; break;

        case SDLK_DOWN:
            ConsoleLog("DOWN Pressed");
            // enb->push_event(ena,G_ENTITY_ATTACK,va((char *)"%d",rand()%10+4),0);
            break;

        case SDLK_UP:
            ConsoleLog("UP Pressed");
            // ena->push_event(enb,G_ENTITY_ATTACK,va((char *)"%d",rand()%10+4),0);
            break;

        case SDLK_LEFT: ConsoleLog("LEFT Pressed"); break;
        case SDLK_RIGHT: ConsoleLog("RIGHT Pressed"); break;
        case SDLK_F1: break;
        case SDLK_F2: break;
        case SDLK_F3: break;
        case SDLK_F4: break;
        case SDLK_F5: break;
        case SDLK_F6: break;
        case SDLK_F7: break;
        case SDLK_F8: break;
        case SDLK_F9: break;
        case SDLK_F10: break;
        case SDLK_F11: break;
        case SDLK_F12:
            ConsoleLog("Console Toggled");
            bShowConsole ? bShowConsole = false : bShowConsole = true;
            break;
        case SDLK_KP_PLUS:
        case SDLK_KP_MINUS:
        default: break;
    }
}

int main(int argc, char *argv[]) {
    Game = new CGame(_DLCS_APP_NAME, SGC_ALL);
    while (!Game->Loop())
        ;
    DEL(Game);
    return (0);
}
