/*
This file belongs to Renderer.
See LICENSE file in root folder
*/
#pragma once

#include <VkLib/VkLibPrerequisites.hpp>
#include <Renderer/FenceCreateFlag.hpp>

namespace vk_renderer
{
	/**
	*\brief
	*	Convertit un renderer::FenceCreateFlags en VkFenceCreateFlags.
	*\param[in] flags
	*	Le renderer::FenceCreateFlags.
	*\return
	*	Le VkFenceCreateFlags.
	*/
	VkFenceCreateFlags convert( renderer::FenceCreateFlags const & flags );
}