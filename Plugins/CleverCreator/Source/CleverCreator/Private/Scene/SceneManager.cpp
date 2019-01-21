// Fill out your copyright notice in the Description page of Project Settings.

#include "SceneManager.h"

DEFINE_LOG_CATEGORY_STATIC(SceneManager, Log, All);

void USceneManager::Init()
{
	Super::Init();

	UE_LOG(SceneManager, Log, TEXT("Init"));
}

void USceneManager::Shutdown()
{
	Super::Shutdown();

	UE_LOG(SceneManager, Log, TEXT("Shutdown"));
}

void USceneManager::BeginPlay()
{
	UE_LOG(SceneManager, Log, TEXT("BeginPlay"));
}