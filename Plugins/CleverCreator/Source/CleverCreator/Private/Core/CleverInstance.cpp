// Fill out your copyright notice in the Description page of Project Settings.

#include "CleverInstance.h"
#include "Scene/SceneManager.h"
#include "UI/UIManager.h"
#include "Lua/LuaManager.h"

void UCleverInstance::Init()
{
	Super::Init();

	AddManager(ULuaManager::StaticClass());

	AddManager(USceneManager::StaticClass());

	AddManager(UUIManager::StaticClass());
}

void UCleverInstance::Shutdown()
{
	Super::Shutdown();

	for (auto &Elem : ManagerMap)
	{
		UBaseManager* Manager = Elem.Value;
		Manager->Shutdown();
	}

	ManagerMap.Empty();
}

void UCleverInstance::AddManager(UClass *ManagerClass)
{
	FString NameString = ManagerClass->GetName();
	FName Name = FName(*NameString);
	UBaseManager** ManagerPtr = ManagerMap.Find(Name);
	if (!ManagerPtr)
	{
		UBaseManager *Manager = NewObject<UBaseManager>(this, ManagerClass);
		Manager->Init();
		ManagerMap.Add(Name, Manager);
	}
}

UBaseManager* UCleverInstance::GetManager(UClass *ManagerClass)
{
	FString NameString = ManagerClass->GetName();
	FName Name = FName(*NameString);
	return *ManagerMap.Find(Name);
}

UBaseManager* UCleverInstance::GetManager(const FName &Name)
{
	return *ManagerMap.Find(Name);
}
