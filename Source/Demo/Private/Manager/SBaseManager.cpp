// Fill out your copyright notice in the Description page of Project Settings.

#include "SBaseManager.h"

/** virtual function to allow custom GameInstances an opportunity to set up what it needs */
void USBaseManager::Init()
{
	//AddToRoot();
}

/** virtual function to allow custom GameInstances an opportunity to do cleanup when shutting down */
void USBaseManager::Shutdown()
{
	//RemoveFromRoot();
}