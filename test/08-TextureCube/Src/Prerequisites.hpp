#pragma once

#include <Prerequisites.hpp>

namespace vkapp
{
	struct NonTexturedVertexData
	{
		utils::Vec3 position;
	};

	struct TexturedVertexData
	{
		utils::Vec4 position;
		utils::Vec2 uv;
	};

	static wxString const AppName{ common::makeName( TEST_ID, wxT( "TextureCube" ) ) };

	class RenderPanel;
	class MainFrame;
	class Application;
}
