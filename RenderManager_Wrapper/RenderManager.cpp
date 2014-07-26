#include "RenderManager.h"

void RenderManager::add_object(Renderable* renderable){
    if(renderable) add_list.push_back(renderable);
}

void RenderManager::remove_object(Renderable* renderable){
    if(renderable) remove_list.push_back(renderable);
}

void RenderManager::render(){
    std::vector<Renderable*>::iterator _begin, _end, _elem;
    _begin = content.begin();
    _end = content.end();
    while(!remove_list.empty()){
        _elem = std::find(_begin,_end,remove_list.front());
        if(_elem != _end) {
            content.erase(_elem);
        }
        else if(!add_list.empty()){
            //Search add_list for the item
            std::list<Renderable*>::iterator i;
            i = std::find(add_list.begin(),add_list.end(),remove_list.front());
            if(i != add_list.end()){
                add_list.remove((*i));
            }
        }
        //Pop the remove list no matter if the element was found
        //So we avoid slow downs by checking for invalid objects
        remove_list.pop_front();
    }
    _begin = content.begin();

    while(add_list.size() > 0){
        content.push_back(add_list.front());
        add_list.pop_front();
    }

    SDL_RenderClear(_renderer);
    last_render_time = SDL_GetTicks();
    for(; _begin != _end && content.size() > 0;_begin++){
        (*_begin)->render(_renderer);
    }
    SDL_RenderPresent(_renderer);
    last_render_time  = SDL_GetTicks() - last_render_time;
}
