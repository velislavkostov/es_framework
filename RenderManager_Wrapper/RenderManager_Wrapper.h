#ifndef _RENDERMANAGER_WRAPPER_
#define _RENDERMANAGER_WRAPPER_
#include <SDL.h>

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

typedef void CRenderManager;
CRenderManager* RenderManager_new(SDL_Renderer* renderer);
void RenderManager_render(CRenderManager* self);
void RenderManager_delete(CRenderManager* self);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _RENDERMANAGER_WRAPPER_
