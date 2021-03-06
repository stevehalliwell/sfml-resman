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

#ifndef MANAGED_SOUND_HPP
#define MANAGED_SOUND_HPP

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include <SFML/Audio/SoundBuffer.hpp>

#include <ResourceManager/BaseResource.hpp>
#include <ResourceManager/Logger.hpp>


namespace rm
{
    ////////////////////////////////////////////////////////////
    /// \brief An inherited resource class for SFML sound types
    /// 
    /// This class handles an SFML sound resource type, with specific
    /// implementation for loading, unloading and reloading.
    ////////////////////////////////////////////////////////////
    
    class ManagedSound : public BaseResource
    {
    public:
        
        ////////////////////////////////////////////////////////////
        /// \brief Default Constructor
        /// 
        /// Normally called by rm::ResourceFactory
        ////////////////////////////////////////////////////////////
        ManagedSound();
        
        ////////////////////////////////////////////////////////////
        /// \brief  Destructor
        /// 
        /// Standard destructor
        ////////////////////////////////////////////////////////////
        ~ManagedSound();
        
        ////////////////////////////////////////////////////////////
        /// \brief Loads the SFML Sound resource
        /// 
        /// Invoked when rm::ResourceManager::singleton::load() is called
        ////////////////////////////////////////////////////////////
        bool load() override;
        
        ////////////////////////////////////////////////////////////
        /// \brief Unloads the SFML Sound resource, 
        /// but doesn't remove the instance of this class from rm::ResourceManager
        /// 
        /// Invoked when rm::ResourceManager::singleton::unload() is called
        ////////////////////////////////////////////////////////////
        bool unload() override;
        
        ////////////////////////////////////////////////////////////
        /// \brief Force reloads the SFML Sound resource
        /// 
        /// Invoked when rm::ResourceManager::singleton::reload() is called
        ////////////////////////////////////////////////////////////
        bool reload() override;
        
        ////////////////////////////////////////////////////////////
        /// \brief Returns the resource type of this instance
        ////////////////////////////////////////////////////////////
        static std::string getResourceClassType();
        
        ////////////////////////////////////////////////////////////
        /// \brief Returns a pointer to the SoundBuffer 
        ////////////////////////////////////////////////////////////
        sf::SoundBuffer* getSoundBuffer();
        
    private:
    
        ////////////////////////////////////////////////////////////
        /// Member data
        ////////////////////////////////////////////////////////////
        sf::SoundBuffer* m_soundBuffer;    ///< Reference to the sound resource
    };

} // namespace rm

#endif //MANAGED_SOUND_HPP

////////////////////////////////////////////////////////////
/// \class ManagedSound
/// \ingroup
/// rm::ManagedSound is the inherited class which handles loading and unloading of 
/// SFML sf::Sound resources. rm::ManagedSound implements rm::BaseResource.
///
/// Usage example:
/// \code
/// (rm::ManagedSound) rm::ResourceManager::singleton::getResource("example_sound")->getSound()->play();
/// \endcode
////////////////////////////////////////////////////////////