/* Deadline's 2D SDL Template */

#define _DLCS_SDL 1
#include "2D_SDL_Template.h"

#define APP_NAME "Deadline's C++ Game Template"

CEntity *ena;
CEntity *enb;

void CGame::UserInit() {
    zl("UserInit()");
    ena = new CEntity((char *)"Fred");
    enb = new CEntity((char *)"Evil Pig");
    ena->push_event(enb,G_ENTITY_ATTACK,va("%d",rand()%209+34),ena);
    enb->push_event(ena,G_ENTITY_ATTACK,va("%d",rand()%209+34),enb);
}

void CGame::UserGFX() {
//     SDL->DrawMap();
    SDL->Write(10,10,(char *)" Deadline's C++ Game Template ",0);
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
            enb->push_event(ena,G_ENTITY_ATTACK,va((char *)"%d",rand()%10+4),0);
            break;

        case SDLK_UP:
            ena->push_event(enb,G_ENTITY_ATTACK,va((char *)"%d",rand()%10+4),0);
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
    dlcsm_delete(ena);
    dlcsm_delete(enb);
    dlcsm_delete(Game);
    return(0);
}
