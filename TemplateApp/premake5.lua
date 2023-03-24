outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "TemplateApp"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++20"
	staticruntime "Off"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/**.h",
		"src/**.cpp",
	}

	includedirs
	{
		"src",
		"vendor/SDL2/include",
		"vendor/SDL2_image/include",
		"vendor/SDL2_ttf/include",
		"vendor/SDL2_mixer/include",
		"vendor/SDL2_gpu/include"
	}

	libdirs
	{
		"vendor/SDL2/lib",
		"vendor/SDL2_image/lib",
		"vendor/SDL2_ttf/lib",
		"vendor/SDL2_mixer/lib",
		"vendor/SDL2_gpu/lib"
	}

	links
	{
		"winmm.lib",
		"imm32.lib",
		"version.lib",
		"setupapi.lib",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		defines "DEBUG"
		runtime "Debug"
		symbols "On"

		links
		{
			"sdl2d.lib",
			"sdl2maind.lib",
			"sdl2_imaged.lib",
			"sdl2_ttfd.lib",
			"sdl2_mixerd.lib",
			"sdl2_gpud.lib"
		}

	filter "configurations:Release"
		defines "NDEBUG"
		runtime "Release"
		optimize "On"
		kind "WindowedApp"

		links
		{
			"sdl2.lib",
			"sdl2main.lib",
			"sdl2_image.lib",
			"sdl2_ttf.lib",
			"sdl2_mixer.lib",
			"sdl2_gpu.lib"
		}

