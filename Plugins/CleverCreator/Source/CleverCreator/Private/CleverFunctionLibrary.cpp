// Fill out your copyright notice in the Description page of Project Settings.

#include "CleverFunctionLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "CleverInstance.h"
#include "Scene/SceneManager.h"
#include "UI/UIManager.h"

UCleverInstance* UCleverFunctionLibrary::GetCleverInstance(const UObject* WorldContextObject)
{
	return Cast<UCleverInstance>(UGameplayStatics::GetGameInstance(WorldContextObject));
}

USceneManager* UCleverFunctionLibrary::GetSceneManager(const UObject* WorldContextObject)
{
	USceneManager *SceneManager = nullptr;

	UCleverInstance *Instance = GetCleverInstance(WorldContextObject);
	if (Instance)
	{
		SceneManager = Cast<USceneManager>(Instance->GetManager(USceneManager::StaticClass()));
	}

	return SceneManager;
}

UUIManager* UCleverFunctionLibrary::GetUIManager(const UObject* WorldContextObject)
{
	UUIManager *UIManager = nullptr;

	UCleverInstance *Instance = GetCleverInstance(WorldContextObject);
	if (Instance)
	{
		UIManager = Cast<UUIManager>(Instance->GetManager(UUIManager::StaticClass()));
	}

	return UIManager;
}