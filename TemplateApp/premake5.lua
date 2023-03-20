outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "TemplateApp" -- TODO: Rename
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++20"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/**.h",
		"src/**.cpp",
	}

	defines
	{
	}

	includedirs
	{
		"src",
		"vendor/SDL2-2.26.4/include"
	}

	libdirs
	{
		"vendor/SDL2-2.26.4/lib"
	}

	links
	{
		"winmm.lib",
		"imm32.lib",
		"version.lib",
		"setupapi.lib"
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
			"sdl2maind.lib"
		}

	filter "configurations:Release"
		defines "NDEBUG"
		runtime "Release"
		optimize "On"

		links
		{
			"sdl2.lib",
			"sdl2main.lib"
		}

