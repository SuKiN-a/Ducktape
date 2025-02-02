#pragma once

#include <Panels/Panel.h>
#include <Components/Camera.h>
#include <Components/Transform.h>
#include <Components/Tag.h>
#include <Components/DirectionalLight.h>
#include <Components/MeshRenderer.h>
#include <Components/PointLight.h>
#include <Scene/Entity.h>

namespace DT
{
	class InspectorPanel : public Panel
	{
	public:
		void Update(Engine &engine) override;
		const char* GetWindowName() override;

	private:
		void RenderAddComponentMenu(Engine &engine);
		const char* windowName = "Inspector";
		Entity selectedEntity;
		bool openAddComponentMenu = false;
		std::string addComponentInput;
	};
}