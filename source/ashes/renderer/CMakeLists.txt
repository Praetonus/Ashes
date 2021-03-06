if ( NOT DEFINED ASHES_BUILD_RENDERER_PLUGINS )
	option( ASHES_BUILD_RENDERER_PLUGINS "Build renderer plugins" ON )
endif ()

if ( ASHES_BUILD_RENDERER_PLUGINS )
	set( TARGET_INCLUDE_DIRS
		${TARGET_INCLUDE_DIRS}
		${Ashes_SOURCE_DIR}/include
	)
	set( ASHES_BUILD_PLUGINS TRUE )

	if ( NOT DEFINED ASHES_BUILD_RENDERER_VKN )
		option( ASHES_BUILD_RENDERER_VKN "Build Vulkan renderer plugin" ON )
	endif ()
	if ( ASHES_BUILD_RENDERER_VKN )
		set( ASHES_BUILD_VKN ON  )
	else ()
		set( ASHES_BUILD_VKN OFF )
	endif ()

	if ( NOT APPLE )
		if ( NOT DEFINED ASHES_BUILD_RENDERER_OGL )
			option( ASHES_BUILD_RENDERER_OGL "Build OpenGL renderer plugin" ON )
		endif ()
		if ( ASHES_BUILD_RENDERER_OGL )
			set( ASHES_BUILD_OGL ON )
		else ()
			set( ASHES_BUILD_OGL OFF )
		endif ()
	else ()
		set( ASHES_BUILD_OGL OFF )
	endif ()

	if ( WIN32 )
		if ( NOT DEFINED ASHES_BUILD_RENDERER_D3D11 )
			option( ASHES_BUILD_RENDERER_D3D11 "Build Direct3D 11 renderer plugin" ON )
		endif ()
		if ( ASHES_BUILD_RENDERER_D3D11 )
			set( ASHES_BUILD_D3D11 ON  )
		else ()
			set( ASHES_BUILD_D3D11 OFF )
		endif ()
	else ()
		set( ASHES_BUILD_D3D11 OFF )
	endif ()

	if ( NOT DEFINED ASHES_BUILD_RENDERER_TEST )
		option( ASHES_BUILD_RENDERER_TEST "Build Test renderer plugin" OFF )
	endif ()
	if ( ASHES_BUILD_RENDERER_TEST )
		set( ASHES_BUILD_TEST ON  )
	else ()
		set( ASHES_BUILD_TEST OFF )
	endif ()
else ()
	set( ASHES_BUILD_PLUGINS OFF )
endif ()

if ( ASHES_BUILD_PLUGINS )
	set( RendererDependencies
		ashes::common
		ashes::ashes
	)
	if ( ASHES_BUILD_OGL OR ASHES_BUILD_D3D11 OR ASHES_BUILD_TEST )
		add_subdirectory( RendererCommon )
		set( RendererDependencies
			${RendererDependencies}
			ashes::RendererCommon
		)
	endif ()

	if ( ASHES_BUILD_OGL )
		if ( ANDROID )
			add_definitions( -DASHES_ANDROID )
		elseif ( NOT WIN32 )
			add_definitions( -DASHES_LINUX )
			add_definitions( -DASHES_VENDOR_GL )
			option( ASHES_USE_XLIB_EGL "Use EGL with XLIB" OFF )
		endif ()
		add_subdirectory( GlRenderer )
	endif ()
	if ( ASHES_BUILD_VKN )
		add_subdirectory( VkRenderer )
	endif ()
	if ( ASHES_BUILD_D3D11 )
		add_subdirectory( D3D11Renderer )
	endif ()
	if ( ASHES_BUILD_TEST )
		add_subdirectory( TestRenderer )
	endif ()
	set( ENABLED_RENDERERS ${ENABLED_RENDERERS} PARENT_SCOPE )
endif ()
