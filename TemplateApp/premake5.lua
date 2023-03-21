outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "TemplateApp"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++20"
	staticruntime "On"

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
		"vendor/SDL2/include"
	}

	libdirs
	{
		"vendor/SDL2/lib"
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
		kind "WindowedApp"

		links
		{
			"sdl2.lib",
			"sdl2main.lib"
		}

