// Fill out your copyright notice in the Description page of Project Settings.

#include "SBaseManager.h"
#include "SGameInstance.h"

/** virtual function to allow custom GameInstances an opportunity to set up what it needs */
void USBaseManager::Init()
{
	this->AddToRoot();

    SGameInstance = Cast<USGameInstance>(GetOuter());
}

/** virtual function to allow custom GameInstances an opportunity to do cleanup when shutting down */
void USBaseManager::Shutdown()
{
	this->RemoveFromRoot();

	SGameInstance = nullptr;
}
