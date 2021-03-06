#include "GlRendererPrerequisites.hpp"

namespace ashes::gl
{
	std::string getName( GlAttachmentPoint value )
	{
		switch ( value )
		{
		case GL_ATTACHMENT_POINT_DEPTH_STENCIL:
			return "GL_DEPTH_STENCIL_ATTACHMENT";

		case GL_ATTACHMENT_POINT_COLOR0:
			return "GL_COLOR_ATTACHMENT0";

		case GL_ATTACHMENT_POINT_COLOR1:
			return "GL_COLOR_ATTACHMENT1";

		case GL_ATTACHMENT_POINT_COLOR2:
			return "GL_COLOR_ATTACHMENT2";

		case GL_ATTACHMENT_POINT_COLOR3:
			return "GL_COLOR_ATTACHMENT3";

		case GL_ATTACHMENT_POINT_COLOR4:
			return "GL_COLOR_ATTACHMENT4";

		case GL_ATTACHMENT_POINT_COLOR5:
			return "GL_COLOR_ATTACHMENT5";

		case GL_ATTACHMENT_POINT_COLOR6:
			return "GL_COLOR_ATTACHMENT6";

		case GL_ATTACHMENT_POINT_COLOR7:
			return "GL_COLOR_ATTACHMENT7";

		case GL_ATTACHMENT_POINT_COLOR8:
			return "GL_COLOR_ATTACHMENT8";

		case GL_ATTACHMENT_POINT_COLOR9:
			return "GL_COLOR_ATTACHMENT9";

		case GL_ATTACHMENT_POINT_COLOR10:
			return "GL_COLOR_ATTACHMENT10";

		case GL_ATTACHMENT_POINT_COLOR11:
			return "GL_COLOR_ATTACHMENT11";

		case GL_ATTACHMENT_POINT_COLOR12:
			return "GL_COLOR_ATTACHMENT12";

		case GL_ATTACHMENT_POINT_COLOR13:
			return "GL_COLOR_ATTACHMENT13";

		case GL_ATTACHMENT_POINT_COLOR14:
			return "GL_COLOR_ATTACHMENT14";

		case GL_ATTACHMENT_POINT_COLOR15:
			return "GL_COLOR_ATTACHMENT15";

		case GL_ATTACHMENT_POINT_DEPTH:
			return "GL_DEPTH_ATTACHMENT";

		case GL_ATTACHMENT_POINT_STENCIL:
			return "GL_STENCIL_ATTACHMENT";

		default:
			assert( false && "Unsupported GlAttachmentPoint" );
			return "GlAttachmentPoint_UNKNOWN";
		}
	}
}
