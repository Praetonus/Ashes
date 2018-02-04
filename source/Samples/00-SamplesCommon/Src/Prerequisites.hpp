#pragma once

#include <Core/Connection.hpp>

#include <Utils/Factory.hpp>
#include <Utils/Mat4.hpp>

#pragma warning( disable: 4996 )
#include <wx/wx.h>
#include <wx/windowptr.h>

#include <array>
#include <chrono>

namespace common
{
	static wxSize const WindowSize{ 800, 600 };
	using RendererFactory = utils::Factory< renderer::Renderer, std::string, renderer::RendererPtr >;

	static uint32_t constexpr MAX_TEXTURES = 6u;
	static uint32_t constexpr MAX_LIGHTS = 10u;

	/**
	*\~english
	*\name Loaded data.
	*\~french
	*\name Donn�es charg�es.
	*/
	/**\{*/
	struct Image
	{
		renderer::UIVec2 size;
		renderer::ByteArray data;
		renderer::PixelFormat format;
		bool opacity{ false };
	};

	struct TextureOperators
	{
		int diffuse{ 0 }; // 0 or 1
		int specular{ 0 }; // 0 or 1
		int emissive{ 0 }; // 0 or 1
		int normal{ 0 }; // 0 for none, 1 for normals, 2 for inverted normals
		uint32_t shininess{ 0 }; // 0 for none, 1 for R, 2 for G, 4 for B, 8 for A
		uint32_t opacity{ 0 }; // 0 for none, 1 for R, 2 for G, 4 for B, 8 for A
		uint32_t height{ 0 }; // 0 for none, 1 for R, 2 for G, 4 for B, 8 for A
		float fill; // align to 16 bytes.
	};

	struct MaterialData
	{
		renderer::RgbaColour diffuse;
		renderer::RgbaColour specular;
		renderer::RgbaColour emissive;
		float shininess{ 0.0f };
		float opacity{ 1.0f };
		uint32_t texturesCount{ 0u };
		int backFace{ 0 }; // 0 or 1
		std::array< TextureOperators, MAX_TEXTURES > textureOperators;
	};

	struct Material
	{
		MaterialData data;
		bool hasOpacity{ false };
		std::vector< Image > textures;
	};

	struct Vertex
	{
		renderer::Vec3 position;
		renderer::Vec3 normal;
		renderer::Vec3 tangent;
		renderer::Vec3 bitangent;
		renderer::Vec2 texture;
	};

	struct VertexBuffer
	{
		std::vector< Vertex > data;
		bool hasNormals{ false }; // true implies that it will also have tangents and bitangents
	};

	struct Face
	{
		uint32_t a;
		uint32_t b;
		uint32_t c;
	};

	struct IndexBuffer
	{
		std::vector< Face > data;
	};

	struct Submesh
	{
		VertexBuffer vbo;
		IndexBuffer ibo;
		std::vector< Material > materials;
	};

	using Object = std::vector< Submesh >;
	/**\}*/
	/**
	*\~english
	*\name Lighting.
	*\~french
	*\name Eclairage.
	*/
	/**\{*/
	struct Light
	{
		renderer::Vec4 colour;
		renderer::Vec4 intensities;
	};

	struct DirectionalLight
	{
		Light base;
		renderer::Vec4 direction;
	};

	struct PointLight
	{
		Light base;
		renderer::Vec4 position;
		renderer::Vec4 attenation;
	};

	struct SpotLight
	{
		PointLight base;
		renderer::Vec4 direction;
		renderer::Vec4 coeffs;// .x = cutoff, .y = exponent
	};

	struct LightsData
	{
		renderer::IVec4 lightsCount;
		DirectionalLight directionalLights[MAX_LIGHTS];
		PointLight pointLights[MAX_LIGHTS];
		SpotLight spotLights[MAX_LIGHTS];
	};
	/**\}*/
	/**
	*\~english
	*\name Rendered data.
	*\~french
	*\name Donn�es rendues.
	*/
	/**\{*/
	struct TextureNode
	{
		renderer::TexturePtr texture;
		renderer::TextureViewPtr view;
	};

	struct SubmeshNode;
	using SubmeshNodePtr = std::shared_ptr< SubmeshNode >;

	struct MaterialNode
	{
		SubmeshNodePtr submesh;
		std::vector< TextureNode > textures;
		renderer::DescriptorSetLayoutPtr layout;
		renderer::DescriptorSetPoolPtr pool;
		renderer::DescriptorSetPtr descriptorSetTextures;
		renderer::DescriptorSetPtr descriptorSetUbos;
		renderer::PipelineLayoutPtr pipelineLayout;
		renderer::PipelinePtr pipeline;
	};

	struct SubmeshNode
	{
		renderer::VertexBufferPtr< Vertex > vbo;
		renderer::VertexLayoutPtr vertexLayout;
		renderer::BufferPtr< Face > ibo;
		renderer::GeometryBuffersPtr geometryBuffers;
	};

	using ObjectNodes = std::vector< MaterialNode >;
	using SubmeshNodes = std::vector< SubmeshNodePtr >;
	/**\}*/

	renderer::ConnectionPtr makeConnection( wxWindow * window
		, renderer::Renderer const & renderer );

	class Application;
	class MainFrame;
}