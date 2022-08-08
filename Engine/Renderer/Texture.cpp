#include "Texture.h"
#include "Renderer.h"
#include "Core/Logger.h"
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
        if (surface == nullptr)
        {
           // LOG(SDL_GetError());
            return false;
        }

        // create texture 
       m_texture = SDL_CreateTextureFromSurface(renderer.m_renderer, surface);
            
        if (m_texture == nullptr)
        {
        SDL_FreeSurface(surface);
           // LOG(SDL_GetError());
            return false;
        }
            return true;
    }

    cool::Vector2 Texture::GetSize() const
    {
        SDL_Point point;
        SDL_QueryTexture(m_texture, nullptr, nullptr, &point.x, &point.y);

        return Vector2(point.x, point.y); 
    }

}
