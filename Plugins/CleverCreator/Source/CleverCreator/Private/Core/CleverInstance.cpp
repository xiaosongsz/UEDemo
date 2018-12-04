// Fill out your copyright notice in the Description page of Project Settings.

#include "CleverInstance.h"

void UCleverInstance::Init()
{
	Super::Init();
}

void UCleverInstance::Shutdown()
{
	Super::Shutdown();
}

UBaseManager* UCleverInstance::GetManager(const FName &Name)
{
	return nullptr;
}
