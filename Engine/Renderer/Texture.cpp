#include "Texture.h"
#include "Renderer.h" 
#include <SDL.h> 
#include <SDL_image.h> 

namespace cool
{
    Texture::~Texture()
    { 
        if (m_texture != NULL) SDL_DestroyTexture;
    }

    bool Texture::Create(Renderer& renderer, const std::string& filename)
    {
        // load surface 
        SDL_Surface* surface = IMG_Load(filename.c_str());

        // create texture 
        SDL_CreateTextureFromSurface(renderer.m_renderer, surface);
        SDL_FreeSurface(surface);
            
            return true;
    }

    cool::Vector2 Texture::GetSize() const
    {
        SDL_Point point;
        SDL_QueryTexture(m_texture, nullptr, nullptr,&point.x, &point.y);

        return Vector2(point.x, point.y); 
    }

}
