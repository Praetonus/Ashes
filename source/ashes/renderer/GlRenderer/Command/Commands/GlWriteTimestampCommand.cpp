/*
This file belongs to Ashes.
See LICENSE file in root folder.
*/
#include "Command/Commands/GlWriteTimestampCommand.hpp"

#include "Miscellaneous/GlQueryPool.hpp"

#include "ashesgl_api.hpp"

namespace ashes::gl
{
	void apply( ContextLock const & context
		, CmdWriteTimestamp const & cmd )
	{
		glLogCall( context
			, glQueryCounter
			, cmd.name
			, GL_QUERY_TYPE_TIMESTAMP );
	}

	void buildWriteTimestampCommand( VkPipelineStageFlagBits pipelineStage
		, VkQueryPool pool
		, uint32_t query
		, CmdList & list )
	{
		glLogCommand( list, "WriteTimestampCommand" );
		list.push_back( makeCmd< OpType::eWriteTimestamp >( *( get( pool )->begin() + query ) ) );
	}
}
