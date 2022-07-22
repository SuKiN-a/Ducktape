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

#include <Renderer/Renderer.h>

GLenum glCheckError_(const char *file, int line)
{
    GLenum errorCode;
    while ((errorCode = glGetError()) != GL_NO_ERROR)
    {
        std::string error;
        switch (errorCode)
        {
        case GL_INVALID_ENUM:
            error = "INVALID_ENUM";
            break;
        case GL_INVALID_VALUE:
            error = "INVALID_VALUE";
            break;
        case GL_INVALID_OPERATION:
            error = "INVALID_OPERATION";
            break;
        case GL_STACK_OVERFLOW:
            error = "STACK_OVERFLOW";
            break;
        case GL_STACK_UNDERFLOW:
            error = "STACK_UNDERFLOW";
            break;
        case GL_OUT_OF_MEMORY:
            error = "OUT_OF_MEMORY";
            break;
        case GL_INVALID_FRAMEBUFFER_OPERATION:
            error = "INVALID_FRAMEBUFFER_OPERATION";
            break;
        }
        std::cout << error << " | " << file << " (" << line << ")" << std::endl;
    }
    return errorCode;
}

namespace DT
{
    void Renderer::Init()
    {
        glEnable(GL_DEPTH_TEST);

        defaultShader.Load("../resources/shaders/vertex.glsl", "../resources/shaders/fragment.glsl");

        model.path = "../resources/models/backpack/backpack.obj";
        model.LoadModel(model.path);
    }

    void Renderer::Render()
    {
        // Projection and View
        Camera::view = glm::lookAt(Camera::transform.position, Camera::transform.position + Camera::transform.Forward(), glm::vec3(0.0f, 1.0f, 0.0f));

        if (isOrtho)
            Camera::projection = glm::ortho(0.f, Window::windowSize.x, 0.f, Window::windowSize.y, 0.1f, 100.0f);
        else
            Camera::projection = glm::perspective(glm::radians(fov), Window::windowSize.x / Window::windowSize.y, 0.1f, 100.0f);

        defaultShader.Use();
        defaultShader.SetMat4("projection", Camera::projection);
        defaultShader.SetMat4("view", Camera::view);

        // glm::mat4 trans = glm::mat4(1.0f);
        // defaultShader.SetMat4("model", trans);

        // for (unsigned int i = 0; i < model.meshes.size(); i++)
        //     model.meshes[i].Draw(defaultShader);

        glCheckError();
    }
}