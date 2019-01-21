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

ULuaManager* UCleverFunctionLibrary::GetLuaManager(const UObject* WorldContextObject)
{
	return GetCleverInstance(WorldContextObject)->GetLuaManager();
}

USceneManager* UCleverFunctionLibrary::GetSceneManager(const UObject* WorldContextObject)
{
	return GetCleverInstance(WorldContextObject)->GetSceneManager();
}

UUIManager* UCleverFunctionLibrary::GetUIManager(const UObject* WorldContextObject)
{
	return GetCleverInstance(WorldContextObject)->GetUIManager();
}