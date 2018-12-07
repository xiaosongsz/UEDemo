// Fill out your copyright notice in the Description page of Project Settings.

#include "CleverFunctionLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "CleverInstance.h"
#include "Scene/SceneManager.h"
#include "UI/UIManager.h"

UCleverInstance* UCleverFunctionLibrary::CleverInstance;

USceneManager* UCleverFunctionLibrary::SceneManager;

UUIManager* UCleverFunctionLibrary::UIManager;

UCleverInstance* UCleverFunctionLibrary::GetCleverInstance(const UObject* WorldContextObject)
{
	if (!CleverInstance)
	{
		CleverInstance = Cast<UCleverInstance>(UGameplayStatics::GetGameInstance(WorldContextObject));
	}
	return CleverInstance;
}

USceneManager* UCleverFunctionLibrary::GetSceneManager(const UObject* WorldContextObject)
{
	if (!SceneManager)
	{
		UCleverInstance *Instance = GetCleverInstance(WorldContextObject);
		if (Instance)
		{
			SceneManager = Cast<USceneManager>(Instance->GetManager(USceneManager::StaticClass()));
		}
	}
	return SceneManager;
}

UUIManager* UCleverFunctionLibrary::GetUIManager(const UObject* WorldContextObject)
{
	if (!UIManager)
	{
		UCleverInstance *Instance = GetCleverInstance(WorldContextObject);
		if (Instance)
		{
			UIManager = Cast<UUIManager>(Instance->GetManager(UUIManager::StaticClass()));
		}
	}
	return UIManager;
}