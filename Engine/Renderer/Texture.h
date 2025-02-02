/*
Ducktape | An open source C++ 2D & 3D game engine that focuses on being fast, and powerful.
Copyright (C) 2022 Aryan Baburajan

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.

In case of any further questions feel free to contact me at
the following email address:
aryanbaburajan2007@gmail.com
*/

#pragma once

#include <string>
#include <stdexcept>
#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <utils/stb_image.h>

#include <Core/Serialization.h>

namespace DT
{
    /**
     * @brief Texture class for loading and using texture or image.
     */
    class Texture
    {
    public:
        int width;                ///< @brief Width of the image/texture.
        int height;               ///< @brief Height of the image/texture.
        int nrChannels;           
        unsigned int id;          ///< @brief Unique id of the texture.
        bool loaded = false;      ///< @brief Whether the texture is loaded or not.
        std::string type; // TOFIX: Switch to enums
        std::filesystem::path path;         ///< @brief Path to the image/texture file.

        Texture() = default;

        /**
         * @brief Create a new Texture class
         * @param _path path to the texture/image to be loaded
         * @param _type type flag for the texture
         */
        Texture(std::filesystem::path _path, std::string _type);

        /**
         * @brief  deletes the texture
         */
        void Delete();
    };
    
    SERIALIZE(Texture, type, path); // TODO: Switch to Resource ID once Resource System has been implemented
}