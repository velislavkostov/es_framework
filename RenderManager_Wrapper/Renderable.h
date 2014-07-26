#ifndef _RENDERABLE_
#define _RENDERABLE_

#include <SDL.h>
#include <SDL_image.h>
#include <string>

class Renderable{
public:
    virtual void render(SDL_Renderer*) = 0;
    virtual SDL_Rect* box() = 0;
    //virtual void update() = 0; //SDL_UpdateTexture(renderer,texture,_surface->pixels,_surface->pitch); //Update texture, based on surface
    virtual ~Renderable(){};
};


class Rectangle: public Renderable{
public:
    Rectangle();
    Rectangle(int x, int y, int w, int h);
    ~Rectangle(){SDL_FreeSurface(_surface);}
    SDL_Rect* box(){return &_box;}
    void box(int x, int y, int w, int h){_box.x = x; _box.y = y; _box.w = w; _box.h = h;}
    void color(int r, int g, int b){SDL_FillRect(_surface,nullptr,SDL_MapRGB(_surface->format,r,g,b));}
    void render(SDL_Renderer* renderer);
private:
    SDL_Texture* _texture;
    SDL_Surface* _surface;
    SDL_Rect _box;
};

class Image: public Renderable{
public:
    Image();
    Image(char* filename,int x, int y, int w, int h);
    Image(char* filename,int x, int y, int w, int h,Uint32 format,SDL_Renderer* renderer);
    void render(SDL_Renderer* renderer);
    SDL_Rect* box(){return &_box;}
    ~Image(){SDL_FreeSurface(_surface);}
private:
    SDL_Texture* _texture;
    SDL_Surface* _surface;
    SDL_Rect _box;
};

#endif // _RENDERABLE_
