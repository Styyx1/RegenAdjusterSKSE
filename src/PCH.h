#pragma once
#define NOMINMAX
//_CRT_SECURE_NO_WARNINGS
#define TRUEHUD_API_COMMONLIB
#include <RE/Skyrim.h>
#include <REL/Relocation.h>
#include <SKSE/SKSE.h>

#include <SimpleIni.h>
#include <spdlog/sinks/basic_file_sink.h>

#include <ShlObj_core.h>
#include <Windows.h>
//_CRT_SECURE_NO_WARNINGS;

//#include "C:/dev/steamworks_sdk_152/sdk/public/steam/steam_api.h"
//#pragma comment(lib, "steam_api64.lib");
//#define NOMINMAX

#ifdef NDEBUG
#	include <spdlog/sinks/basic_file_sink.h>
#else
#	include <spdlog/sinks/msvc_sink.h>
#endif
#pragma warning(pop)

using namespace std::literals;

namespace logger = SKSE::log;

namespace stl
{
	template <class T>
	void write_thunk_call(std::uintptr_t a_src)
	{
		auto& trampoline = SKSE::GetTrampoline();
		SKSE::AllocTrampoline(14);

		T::func = trampoline.write_call<5>(a_src, T::thunk);
	}

}

namespace util
{
	using SKSE::stl::report_and_fail;
}

#define DLLEXPORT __declspec(dllexport)

#include "Plugin.h"
