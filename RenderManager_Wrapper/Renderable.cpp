#include "Renderable.h"

Rectangle::Rectangle(){
    _box.x = 25;
    _box.y = 25;
    _box.w = 100;
    _box.h = 25;
    _surface = SDL_CreateRGBSurface(0,_box.w,_box.h,32,0,0,0,0);
    SDL_FillRect(_surface,nullptr,SDL_MapRGB(_surface->format,255,255,255));
}

Rectangle::Rectangle(int x, int y, int w, int h){
    _box.x = x;
    _box.y = y;
    _box.w = w;
    _box.h = h;
    _surface = SDL_CreateRGBSurface(0,_box.w,_box.h,32,0,0,0,0);
    SDL_FillRect(_surface,nullptr,SDL_MapRGB(_surface->format,255,255,255));
}

void Rectangle::render(SDL_Renderer* renderer){
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer,_surface);
    SDL_RenderCopy(renderer,texture,NULL,&_box);
    SDL_DestroyTexture(texture);
}

/** IMAGE **/

Image::Image(){
    _box.x = 0;
    _box.y = 0;
    _box.w = 100;
    _box.h = 100;
    _surface = IMG_Load("\default_image.png");
}

Image::Image(char* filename,int x, int y, int w, int h){
    _box.x = x;
    _box.y = y;
    _box.w = w;
    _box.h = h;
    _surface = IMG_Load(filename);
}

Image::Image(char* filename,int x, int y, int w, int h,Uint32 format,SDL_Renderer* renderer){
    _box.x = x;
    _box.y = y;
    _box.w = w;
    _box.h = h;
    _surface = IMG_Load(filename);
    if(_surface){
        SDL_Surface* optimized = nullptr;
        optimized = SDL_ConvertSurfaceFormat(_surface,format,0);
        if(optimized){
            SDL_FreeSurface(_surface);
            _surface = optimized;
        }
        _texture = SDL_CreateTextureFromSurface(renderer,_surface);
    }
}

void Image::render(SDL_Renderer* renderer){
        SDL_Rect mouse_rect {0,0,1,1};
        SDL_GetMouseState(&mouse_rect.x,&mouse_rect.y);
        if(SDL_HasIntersection(box(),&mouse_rect)){
            SDL_SetTextureColorMod(_texture,128,128,128);
        }
        else{
            SDL_SetTextureColorMod(_texture,255,255,255);
        }
        SDL_RenderCopy(renderer,_texture,NULL,box());
        //SDL_DestroyTexture(_texture);
    //}
}
