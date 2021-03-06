#include "Pipeline/GlPipelineCache.hpp"

namespace ashes::gl
{
	PipelineCache::PipelineCache( VkDevice device
		, VkPipelineCacheCreateInfo createInfo )
		: m_device{ device }
		, m_createInfo{ createInfo }
	{
	}

	VkResult PipelineCache::merge( VkPipelineCacheArray pipelines )
	{
		return VK_SUCCESS;
	}
}
