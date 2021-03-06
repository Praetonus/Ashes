/*
This file belongs to Ashes.
See LICENSE file in root folder
*/
#pragma once

#include "renderer/GlRenderer/Command/Commands/GlCommandBase.hpp"

#include "renderer/GlRenderer/Enum/GlAttachmentPoint.hpp"
#include "renderer/GlRenderer/Enum/GlAttachmentType.hpp"
#include "renderer/GlRenderer/Enum/GlFilter.hpp"
#include "renderer/GlRenderer/Enum/GlImageAspectFlag.hpp"

namespace ashes::gl
{
	//*************************************************************************

	template<>
	struct CmdConfig< OpType::eBlitFramebuffer >
	{
		static Op constexpr value = { OpType::eBlitFramebuffer, 11u };
	};

	template<>
	struct alignas( uint64_t ) CmdT< OpType::eBlitFramebuffer >
	{
		inline CmdT( int32_t srcL
			, int32_t srcT
			, int32_t srcR
			, int32_t srcB
			, int32_t dstL
			, int32_t dstT
			, int32_t dstR
			, int32_t dstB
			, uint32_t mask
			, uint32_t filter )
			: cmd{ { OpType::eBlitFramebuffer, sizeof( CmdT ) / sizeof( uint32_t ) } }
			, srcL{ srcL }
			, srcT{ srcT }
			, srcR{ srcR }
			, srcB{ srcB }
			, dstL{ dstL }
			, dstT{ dstT }
			, dstR{ dstR }
			, dstB{ dstB }
			, mask{ mask }
			, filter{ filter }
		{
		}

		Command cmd;
		int32_t srcL;
		int32_t srcT;
		int32_t srcR;
		int32_t srcB;
		int32_t dstL;
		int32_t dstT;
		int32_t dstR;
		int32_t dstB;
		uint32_t mask;
		uint32_t filter;
	};
	using CmdBlitFramebuffer = CmdT< OpType::eBlitFramebuffer >;

	void apply( ContextLock const & context
		, CmdBlitFramebuffer const & cmd );

	//*************************************************************************

	void buildBlitImageCommand( ContextStateStack & stack
		, VkDevice device
		, VkImage srcImage
		, VkImage dstImage
		, VkImageBlit region
		, VkFilter filter
		, CmdList & list
		, VkImageViewArray & views );

	//*************************************************************************
}
