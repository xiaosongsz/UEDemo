// Fill out your copyright notice in the Description page of Project Settings.

#include "LuaManager.h"
#include "HAL/PlatformFileManager.h"
#include "Misc/Paths.h"
#include "HAL/FileManager.h"
#include "GenericPlatformFile.h"

DEFINE_LOG_CATEGORY_STATIC(LuaManager, Log, All);

// read file content
static uint8* ReadFile(IPlatformFile& PlatformFile, FString path, uint32& len) {
	IFileHandle* FileHandle = PlatformFile.OpenRead(*path);
	if (FileHandle) {
		len = (uint32)FileHandle->Size();
		uint8* buf = new uint8[len];

		FileHandle->Read(buf, len);

		// Close the file again
		delete FileHandle;

		return buf;
	}

	return nullptr;
}

void ULuaManager::Init()
{
	Super::Init();

	State.init();

	State.setLoadFileDelegate([](const char* fn, uint32& len, FString& filepath)->uint8* {

		IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();
		FString path = FPaths::ProjectContentDir();
		path += "/Lua/";
		path += UTF8_TO_TCHAR(fn);
		TArray<FString> luaExts = { UTF8_TO_TCHAR(".lua"), UTF8_TO_TCHAR(".luac") };
		for (auto& it : luaExts) {
			auto fullPath = path + *it;
			auto buf = ReadFile(PlatformFile, fullPath, len);
			if (buf) {
				fullPath = IFileManager::Get().ConvertToAbsolutePathForExternalAppForRead(*fullPath);
				filepath = fullPath;
				return buf;
			}
		}

		return nullptr;
	});
	State.doFile("Main");

	UE_LOG(LuaManager, Log, TEXT("Init"));
}

void ULuaManager::Shutdown()
{
	State.close();
}

LuaState* ULuaManager::GetState()
{
	return &State;
}