workspace "SDLAppTemplate"
	architecture "x86_64"
	configurations { "Debug", "Release", }

include "TemplateApp"

group "Dependencies"
	include "TemplateApp/vendor/Glad"
group ""

