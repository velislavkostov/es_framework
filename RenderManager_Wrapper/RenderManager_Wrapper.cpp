#include "RenderManager.h"
#include "RenderManager_Wrapper.h"

extern "C" {
    CRenderManager* RenderManager_new(SDL_Renderer* renderer){
        RenderManager* rm = new RenderManager(renderer);
        return (CRenderManager*) rm;
    }

    void RenderManager_render(CRenderManager* self){
        RenderManager* rm = (RenderManager*) self;
        rm->render();
    }

    void RenderManager_delete(CRenderManager* self){
        RenderManager* rm = (RenderManager*) self;
        delete rm;
    }
}
