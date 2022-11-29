workspace "MarioEngine"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "MarioEngine"
	location "MarioEngine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.22621.0"

		defines
		{
			"MARIOENGINE_PLATFORM_WINDOWS",
			"MARIOENGINE_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "MARIOENGINE_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "MARIOENGINE_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "MARIOENGINE_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"MarioEngine/vendor/spdlog/include",
		"MarioEngine/src"
	}

	links
	{
		"MarioEngine"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.22621.0"

		defines
		{
			"MARIOENGINE_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "MARIOENGINE_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "MARIOENGINE_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "MARIOENGINE_DIST"
		optimize "On"