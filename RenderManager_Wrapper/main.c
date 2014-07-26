#include <stdio.h>
#include "RenderManager_Wrapper.h"
#include <SDL.h>

/* RenderManager_Wrapper Test Unit */

int main(int argc,char* argv[]){
    SDL_Window* win = NULL;
    SDL_Renderer* ren = NULL;
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_CreateWindowAndRenderer(0,0,SDL_WINDOW_FULLSCREEN_DESKTOP,&win,&ren);

    CRenderManager* rm = RenderManager_new(ren);
    SDL_Event event;
    //Simple boolean enumerator
    typedef enum{false,true} boo;
    boo running = true;
    while(running){
        if(SDL_WaitEvent(&event)){
            switch(event.key.keysym.scancode){
                case SDL_SCANCODE_ESCAPE:
                    running = false;
                break;

                default:
                    RenderManager_render(rm);
                    printf("Rendering\n");
                break;
            }
        }
    }

    return 0;
}
