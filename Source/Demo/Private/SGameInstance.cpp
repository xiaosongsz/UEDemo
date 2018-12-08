// Fill out your copyright notice in the Description page of Project Settings.

#include "SGameInstance.h"

/** virtual function to allow custom GameInstances an opportunity to set up what it needs */
void USGameInstance::Init()
{
	Super::Init();
}

/** Called when the game instance is started either normally or through PIE. */
void USGameInstance::OnStart()
{
	Super::OnStart();
}

/** virtual function to allow custom GameInstances an opportunity to do cleanup when shutting down */
void USGameInstance::Shutdown()
{
	Super::Shutdown();
}
