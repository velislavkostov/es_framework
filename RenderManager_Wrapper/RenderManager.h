#ifndef _RENDERMANAGER_
#define _RENDERMANAGER_

#ifdef __cplusplus

#include <vector>
#include <list>
#include <algorithm>
#include "Renderable.h"
#include <time.h>

class RenderManager{
    public:
        RenderManager(SDL_Renderer* renderer){if(renderer) _renderer = renderer;}
        void render();
        void add_object(Renderable* renderable);
        void remove_object(Renderable* renderable);
        int object_count(){return content.size();}
        Uint32 render_time(){return last_render_time;}
    private:
        SDL_Renderer* _renderer;
        Uint32 last_render_time;
        std::vector<Renderable*> content;
        std::list<Renderable*> remove_list;
        std::list<Renderable*> add_list;

};

#endif // __cplusplus

#endif // _RENDERMANAGER_
