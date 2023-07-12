#include <Windows.h>
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma comment(linker, "/EXPORT:GetFileVersionInfoA=versionOrg.GetFileVersionInfoA,@1")
#pragma comment(linker, "/EXPORT:GetFileVersionInfoByHandle=versionOrg.GetFileVersionInfoByHandle,@2")
#pragma comment(linker, "/EXPORT:GetFileVersionInfoExA=versionOrg.GetFileVersionInfoExA,@3")
#pragma comment(linker, "/EXPORT:GetFileVersionInfoExW=versionOrg.GetFileVersionInfoExW,@4")
#pragma comment(linker, "/EXPORT:GetFileVersionInfoSizeA=versionOrg.GetFileVersionInfoSizeA,@5")
#pragma comment(linker, "/EXPORT:GetFileVersionInfoSizeExA=versionOrg.GetFileVersionInfoSizeExA,@6")
#pragma comment(linker, "/EXPORT:GetFileVersionInfoSizeExW=versionOrg.GetFileVersionInfoSizeExW,@7")
#pragma comment(linker, "/EXPORT:GetFileVersionInfoSizeW=versionOrg.GetFileVersionInfoSizeW,@8")
#pragma comment(linker, "/EXPORT:GetFileVersionInfoW=versionOrg.GetFileVersionInfoW,@9")
#pragma comment(linker, "/EXPORT:VerFindFileA=versionOrg.VerFindFileA,@10")
#pragma comment(linker, "/EXPORT:VerFindFileW=versionOrg.VerFindFileW,@11")
#pragma comment(linker, "/EXPORT:VerInstallFileA=versionOrg.VerInstallFileA,@12")
#pragma comment(linker, "/EXPORT:VerInstallFileW=versionOrg.VerInstallFileW,@13")
#pragma comment(linker, "/EXPORT:VerLanguageNameA=versionOrg.VerLanguageNameA,@14")
#pragma comment(linker, "/EXPORT:VerLanguageNameW=versionOrg.VerLanguageNameW,@15")
#pragma comment(linker, "/EXPORT:VerQueryValueA=versionOrg.VerQueryValueA,@16")
#pragma comment(linker, "/EXPORT:VerQueryValueW=versionOrg.VerQueryValueW,@17")
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL WINAPI DllMain(HMODULE hModule, DWORD dwReason, PVOID pvReserved)
{
	if (dwReason == DLL_PROCESS_ATTACH)
	{
		DisableThreadLibraryCalls(hModule);
		auto hProcessAddress = reinterpret_cast<char*>(GetModuleHandleW(0));
		auto targetAddr = reinterpret_cast<char*>(hProcessAddress + 0x2109CB);
		DWORD oldProc = 0;
		VirtualProtect(reinterpret_cast<LPVOID>(targetAddr), 6, PAGE_EXECUTE_READWRITE, &oldProc);
		for (size_t i = 0; i < 6; i++)
		{
			(*(targetAddr + i)) = 0x90;
		}
		MessageBoxA(nullptr, "Patch Done~!\r\nPowered By moshui\r\n", "Success!", MB_OK);
	}
	else if (dwReason == DLL_PROCESS_DETACH)
	{
	}

	return TRUE;
}
