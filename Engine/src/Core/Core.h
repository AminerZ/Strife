#pragma once
#ifdef HOS_PLATFORM_WINDOWS
	#ifdef HOS_BUILD_DLL
		#define HOS_API __declspec(dllexport)
	#else
		#define HOS_API __declspec(dllimport)
	#endif
#else
	#error Hands of Strife only supports Windows!
#endif