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
}

USUIManager* USGameInstance::GetUIManager()
{
	return UIManager;
}
