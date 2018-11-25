// Fill out your copyright notice in the Description page of Project Settings.

#include "SGameInstance.h"
#include "Manager/SUIManager.h"


/** virtual function to allow custom GameInstances an opportunity to set up what it needs */
void USGameInstance::Init()
{
	Super::Init();

	UIManager = NewObject<USUIManager>(this);
	if (UIManager)
	{
		UIManager->Init();
	}

	UE_LOG(LogTemp, Log, TEXT("USGameInstance::Init()"));
}

/** Called when the game instance is started either normally or through PIE. */
void USGameInstance::OnStart()
{
	Super::OnStart();

	UE_LOG(LogTemp, Log, TEXT("USGameInstance::OnStart()"));
}

/** virtual function to allow custom GameInstances an opportunity to do cleanup when shutting down */
void USGameInstance::Shutdown()
{
	Super::Shutdown();

	if (UIManager)
	{
		UIManager->Shutdown();
		UIManager = nullptr;
	}

	UE_LOG(LogTemp, Log, TEXT("USGameInstance::Shutdown()"));
}

USUIManager* USGameInstance::GetUIManager()
{
	return UIManager;
}
