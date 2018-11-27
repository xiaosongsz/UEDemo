// Fill out your copyright notice in the Description page of Project Settings.

#include "SGameStatics.h"
#include "SGameInstance.h"
#include "Kismet/GameplayStatics.h"

USGameInstance* USGameStatics::GetSGameInstance(const UObject* WorldContextObject)
{
	return Cast<USGameInstance>(UGameplayStatics::GetGameInstance(WorldContextObject));
}

USUIManager* USGameStatics::GetUIManager(const UObject* WorldContextObject)
{
	return USGameStatics::GetSGameInstance(WorldContextObject)->GetUIManager();
}
