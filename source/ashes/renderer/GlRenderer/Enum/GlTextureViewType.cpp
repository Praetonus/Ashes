#include "GlRendererPrerequisites.hpp"

namespace ashes::gl
{
	namespace gl3
	{
		GlTextureType convertViewType( VkImageViewType const & viewType
			, VkImageType const & imageType
			, VkSampleCountFlagBits samples )
		{
			switch ( viewType )
			{
			case VK_IMAGE_VIEW_TYPE_1D:
				return GL_TEXTURE_1D;

			case VK_IMAGE_VIEW_TYPE_2D:
				return samples > 1
					? GL_TEXTURE_2D_MULTISAMPLE
					: GL_TEXTURE_2D;

			case VK_IMAGE_VIEW_TYPE_3D:
				return GL_TEXTURE_3D;

			case VK_IMAGE_VIEW_TYPE_CUBE:
				return GL_TEXTURE_CUBE;

			case VK_IMAGE_VIEW_TYPE_1D_ARRAY:
				return GL_TEXTURE_1D_ARRAY;

			case VK_IMAGE_VIEW_TYPE_2D_ARRAY:
				return imageType == VK_IMAGE_TYPE_3D
					? GL_TEXTURE_3D
					: ( samples > 1
						? GL_TEXTURE_2D_MULTISAMPLE_ARRAY
						: GL_TEXTURE_2D_ARRAY );

			case VK_IMAGE_VIEW_TYPE_CUBE_ARRAY:
				return GL_TEXTURE_CUBE_ARRAY;

			default:
				assert( false && "Unsupported ImageViewType" );
				return GL_TEXTURE_2D;
			}
		}

		GlTextureType convertViewType( VkImageViewType const & viewType
			, VkImageType const & imageType
			, uint32_t arraySize
			, VkSampleCountFlagBits samples )
		{
			switch ( viewType )
			{
			case VK_IMAGE_VIEW_TYPE_1D:
				return arraySize > 1u
					? GL_TEXTURE_1D_ARRAY
					: GL_TEXTURE_1D;

			case VK_IMAGE_VIEW_TYPE_2D:
				return arraySize > 1u
					? ( samples > 1
						? GL_TEXTURE_2D_MULTISAMPLE_ARRAY
						: GL_TEXTURE_2D_ARRAY )
					: ( samples > 1
						? GL_TEXTURE_2D_MULTISAMPLE
						: GL_TEXTURE_2D );

			case VK_IMAGE_VIEW_TYPE_3D:
				return GL_TEXTURE_3D;

			case VK_IMAGE_VIEW_TYPE_CUBE:
				return arraySize > 6u
					? GL_TEXTURE_CUBE_ARRAY
					: GL_TEXTURE_CUBE;

			case VK_IMAGE_VIEW_TYPE_1D_ARRAY:
				return GL_TEXTURE_1D_ARRAY;

			case VK_IMAGE_VIEW_TYPE_2D_ARRAY:
				return imageType == VK_IMAGE_TYPE_3D
					? GL_TEXTURE_3D
					: ( samples > 1
						? GL_TEXTURE_2D_MULTISAMPLE_ARRAY
						: GL_TEXTURE_2D_ARRAY );

			case VK_IMAGE_VIEW_TYPE_CUBE_ARRAY:
				return GL_TEXTURE_CUBE_ARRAY;

			default:
				assert( false && "Unsupported ImageViewType" );
				return GL_TEXTURE_2D;
			}
		}
	}

	namespace gl4
	{
		std::string getName( GlTextureViewType value )
		{
			switch ( value )
			{
			case GL_TEXTURE_VIEW_1D:
				return "GL_TEXTURE_VIEW_1D";

			case GL_TEXTURE_VIEW_2D:
				return "GL_TEXTURE_VIEW_2D";

			case GL_TEXTURE_VIEW_3D:
				return "GL_TEXTURE_VIEW_3D";

			case GL_TEXTURE_VIEW_CUBE_MAP:
				return "GL_TEXTURE_VIEW_CUBE_MAP";

			case GL_TEXTURE_VIEW_1D_ARRAY:
				return "GL_TEXTURE_VIEW_1D_ARRAY";

			case GL_TEXTURE_VIEW_2D_ARRAY:
				return "GL_TEXTURE_VIEW_2D_ARRAY";

			case GL_TEXTURE_VIEW_CUBE_MAP_ARRAY:
				return "GL_TEXTURE_VIEW_CUBE_MAP_ARRAY";

			case GL_TEXTURE_VIEW_2D_MULTISAMPLE:
				return "GL_TEXTURE_VIEW_2D_MULTISAMPLE";

			case GL_TEXTURE_VIEW_2D_MULTISAMPLE_ARRAY:
				return "GL_TEXTURE_VIEW_2D_MULTISAMPLE_ARRAY";

			case GL_TEXTURE_VIEW_CUBE_MAP_POSITIVE_X:
				return "GL_TEXTURE_VIEW_CUBE_MAP_POSITIVE_X";

			case GL_TEXTURE_VIEW_CUBE_MAP_NEGATIVE_X:
				return "GL_TEXTURE_VIEW_CUBE_MAP_NEGATIVE_X";

			case GL_TEXTURE_VIEW_CUBE_MAP_POSITIVE_Y:
				return "GL_TEXTURE_VIEW_CUBE_MAP_POSITIVE_Y";

			case GL_TEXTURE_VIEW_CUBE_MAP_NEGATIVE_Y:
				return "GL_TEXTURE_VIEW_CUBE_MAP_NEGATIVE_Y";

			case GL_TEXTURE_VIEW_CUBE_MAP_POSITIVE_Z:
				return "GL_TEXTURE_VIEW_CUBE_MAP_POSITIVE_Z";

			case GL_TEXTURE_VIEW_CUBE_MAP_NEGATIVE_Z:
				return "GL_TEXTURE_VIEW_CUBE_MAP_NEGATIVE_Z";

			default:
				assert( false && "Unsupported GlTextureViewType" );
				return "GlTextureViewType_UNKNOWN";
			}
		}

		GlTextureViewType convertViewType( VkImageViewType const & viewType
			, VkImageType const & imageType
			, uint32_t arraySize
			, VkSampleCountFlagBits samples )
		{
			switch ( viewType )
			{
			case VK_IMAGE_VIEW_TYPE_1D:
				return GL_TEXTURE_VIEW_1D;

			case VK_IMAGE_VIEW_TYPE_2D:
				return samples > 1
					? GL_TEXTURE_VIEW_2D_MULTISAMPLE
					: GL_TEXTURE_VIEW_2D;

			case VK_IMAGE_VIEW_TYPE_3D:
				return GL_TEXTURE_VIEW_3D;

			case VK_IMAGE_VIEW_TYPE_CUBE:
				return GL_TEXTURE_VIEW_CUBE_MAP;

			case VK_IMAGE_VIEW_TYPE_1D_ARRAY:
				return arraySize > 1u
					? GL_TEXTURE_VIEW_1D_ARRAY
					: GL_TEXTURE_VIEW_1D;

			case VK_IMAGE_VIEW_TYPE_2D_ARRAY:
				return imageType == VK_IMAGE_TYPE_3D
					? GL_TEXTURE_VIEW_3D
					: ( samples > 1
						? ( arraySize > 1u
							? GL_TEXTURE_VIEW_2D_MULTISAMPLE_ARRAY
							: GL_TEXTURE_VIEW_2D_MULTISAMPLE )
						: ( arraySize > 1u
							? GL_TEXTURE_VIEW_2D_ARRAY
							: GL_TEXTURE_VIEW_2D ) );

			case VK_IMAGE_VIEW_TYPE_CUBE_ARRAY:
				return GL_TEXTURE_VIEW_CUBE_MAP_ARRAY;

			default:
				assert( false && "Unsupported ImageViewType" );
				return GL_TEXTURE_VIEW_2D;
			}
		}
	}
}
