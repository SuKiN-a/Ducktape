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

#include <vector>

#include <Renderer/Vertex.h>
#include <Renderer/Texture.h>
#include <Renderer/Shader.h>
#include <Core/Debug.h>
#include <Core/Serialization.h>
#include <Core/Macro.h>

namespace DT
{
    /**
     * @brief Class for drawing mesh. It also stores mesh information like vertices, textures coordinates, etc
     */
    class Mesh
    {
    public:
        std::vector<Vertex> vertices;      ///< @brief vector of Vertex objects
        std::vector<unsigned int> indices; ///< @brief vector of indices of vertices vector
        std::vector<Texture> textures;     ///< @brief vector of Texture objects

        unsigned int VBO; ///< @brief id of vertex buffer object
        unsigned int EBO; ///< @brief id of element array buffer object
        unsigned int VAO; ///< @brief id of vertex array buffer object

        /**
         * @brief Draws the mesh with given shader object
         * @param shader Shader object to use while drawing
         */
        void Draw(Shader &shader);

        /**
         * @brief sets up the VAOs (Vertex Array Objects) for the mesh
         */
        void Setup();
    };

    SERIALIZE(Mesh, vertices, indices, textures);
}