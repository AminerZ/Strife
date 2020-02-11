workspace "Strife"
	architecture "x64"
	startproject "Strife"
	configurations {
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Engine"
	location "Engine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.location}/src/**.h", 
		"%{prj.location}/src/**.cpp"
	}

	includedirs {
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		defines {
			"HOS_PLATFORM_WINDOWS",
			"HOS_BUILD_DLL"
		}

		postbuildcommands {
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Strife")
		}

	filter "configurations:Debug"
		defines "HOS_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "HOS_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "HOS_DIST"
		optimize "On"

project "Strife"
	location "Strife"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h", 
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"Engine/src",
		"Engine/vendor/spdlog/include"
	}

	links {
		"Engine"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		defines {
			"HOS_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "HOS_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "HOS_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "HOS_DIST"
		optimize "On"