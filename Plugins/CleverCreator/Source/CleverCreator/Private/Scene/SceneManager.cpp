// Fill out your copyright notice in the Description page of Project Settings.

#include "SceneManager.h"

void USceneManager::Init()
{
	Super::Init();

	UE_LOG(LogTemp, Log, TEXT("SceneManager::Init"));
}

void USceneManager::Shutdown()
{
	Super::Shutdown();

	UE_LOG(LogTemp, Log, TEXT("SceneManager::Shutdown"));
}
