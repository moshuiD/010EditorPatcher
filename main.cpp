////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 头文件
#include <Windows.h>
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 导出函数
#pragma comment(linker, "/EXPORT:GetFileVersionInfoA=version.GetFileVersionInfoA,@1")
#pragma comment(linker, "/EXPORT:GetFileVersionInfoByHandle=version.GetFileVersionInfoByHandle,@2")
#pragma comment(linker, "/EXPORT:GetFileVersionInfoExA=version.GetFileVersionInfoExA,@3")
#pragma comment(linker, "/EXPORT:GetFileVersionInfoExW=version.GetFileVersionInfoExW,@4")
#pragma comment(linker, "/EXPORT:GetFileVersionInfoSizeA=version.GetFileVersionInfoSizeA,@5")
#pragma comment(linker, "/EXPORT:GetFileVersionInfoSizeExA=version.GetFileVersionInfoSizeExA,@6")
#pragma comment(linker, "/EXPORT:GetFileVersionInfoSizeExW=version.GetFileVersionInfoSizeExW,@7")
#pragma comment(linker, "/EXPORT:GetFileVersionInfoSizeW=version.GetFileVersionInfoSizeW,@8")
#pragma comment(linker, "/EXPORT:GetFileVersionInfoW=version.GetFileVersionInfoW,@9")
#pragma comment(linker, "/EXPORT:VerFindFileA=version.VerFindFileA,@10")
#pragma comment(linker, "/EXPORT:VerFindFileW=version.VerFindFileW,@11")
#pragma comment(linker, "/EXPORT:VerInstallFileA=version.VerInstallFileA,@12")
#pragma comment(linker, "/EXPORT:VerInstallFileW=version.VerInstallFileW,@13")
#pragma comment(linker, "/EXPORT:VerLanguageNameA=version.VerLanguageNameA,@14")
#pragma comment(linker, "/EXPORT:VerLanguageNameW=version.VerLanguageNameW,@15")
#pragma comment(linker, "/EXPORT:VerQueryValueA=version.VerQueryValueA,@16")
#pragma comment(linker, "/EXPORT:VerQueryValueW=version.VerQueryValueW,@17")
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 入口函数
BOOL WINAPI DllMain(HMODULE hModule, DWORD dwReason, PVOID pvReserved)
{
	if (dwReason == DLL_PROCESS_ATTACH)
	{
		DisableThreadLibraryCalls(hModule);
		MessageBoxA(nullptr, "Hijack Down", "Hijack Down", MB_OK);
		auto hProcessAddress = reinterpret_cast<char*>(GetModuleHandleW(0));
		char* targetAddr = reinterpret_cast<char*>(hProcessAddress + 0x2109CB);
		DWORD oldProc = 0;
		VirtualProtect(reinterpret_cast<LPVOID>(targetAddr), 6, PAGE_EXECUTE_READWRITE, &oldProc);
		for (size_t i = 0; i < 6; i++)
		{
			(*(targetAddr + i)) = 0x90;
		}
		MessageBoxA(nullptr, "Hijack Done", "Hijack Done", MB_OK);
	}
	else if (dwReason == DLL_PROCESS_DETACH)
	{
	}

	return TRUE;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
