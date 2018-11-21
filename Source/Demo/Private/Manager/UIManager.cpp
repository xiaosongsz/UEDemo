// Fill out your copyright notice in the Description page of Project Settings.

#include "UIManager.h"

	/** virtual function to allow custom GameInstances an opportunity to set up what it needs */
void UUIManager::Init()
{
	Super::Init();
}

/** virtual function to allow custom GameInstances an opportunity to do cleanup when shutting down */
void UUIManager::Shutdown()
{
	Super::Shutdown();
}

void UUIManager::OpenDialog(FName Name)
{
	UE_LOG(LogTemp, Log, TEXT("UUIManager::OpenDialog"));
}

void UUIManager::CloseDialog(FName Name)
{
	UE_LOG(LogTemp, Log, TEXT("UUIManager::CloseDialog"));
}