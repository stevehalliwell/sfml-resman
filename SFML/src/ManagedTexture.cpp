////////////////////////////////////////////////////////////
//
// The MIT License (MIT)
//
// Copyright (c) 2014 stevehalliwell
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include <ManagedTexture.hpp>

namespace rm
{
////////////////////////////////////////////////////////////
ManagedTexture::ManagedTexture() :
m_texture   (new sf::Texture())
{
    rm::Logger::logMessage("Texture created");
}

////////////////////////////////////////////////////////////
ManagedTexture::~ManagedTexture() 
{
    unload();
}

////////////////////////////////////////////////////////////
bool ManagedTexture::load()
{
    // Make sure a sf::Texture has actually been created
    if(!m_texture) 
    {
        m_texture = new sf::Texture();
    }

    rm::Logger::logMessage("Texture loaded ", getFilePath());

    //Attempt to load from file and return success or failure
    return m_texture->loadFromFile(getFilePath());
}

////////////////////////////////////////////////////////////
bool ManagedTexture::unload()
{
    // Release m_texture resource and null ptr
   if(isLoaded())
   {
        delete m_texture;
        m_texture = nullptr;
   }
   return true;
}

////////////////////////////////////////////////////////////
bool ManagedTexture::reload()
{
    // Reload from file path
    return load();
}

////////////////////////////////////////////////////////////
std::string ManagedTexture::getResourceClassType()
{
    return "texture";
}

////////////////////////////////////////////////////////////
sf::Texture* ManagedTexture::getTexture()
{
    return m_texture;
}

} // namespace rm