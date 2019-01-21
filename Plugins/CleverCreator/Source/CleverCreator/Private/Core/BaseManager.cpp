// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseManager.h"

void UBaseManager::Init()
{
	GameInstance = Cast<UCleverInstance>(GetOuter());

	LoadTable();
}

void UBaseManager::Shutdown()
{
	GameInstance = nullptr;
}

void UBaseManager::LoadTable()
{

}
