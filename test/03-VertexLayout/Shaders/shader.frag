#version 450
#extension GL_KHR_vulkan_glsl : enable

layout( location = 0 ) in vec4 vtx_colour;

layout( location = 0 ) out vec4 pxl_colour;

void main()
{
  pxl_colour = vtx_colour;
}
