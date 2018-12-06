// Fill out your copyright notice in the Description page of Project Settings.

#include "UIManager.h"

void UUIManager::Init()
{
	Super::Init();

	UE_LOG(LogTemp, Log, TEXT("UIManager::Init"));
}

void UUIManager::Shutdown()
{
	Super::Shutdown();

	UE_LOG(LogTemp, Log, TEXT("UIManager::Shutdown"));
}
