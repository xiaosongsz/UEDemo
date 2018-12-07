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

UBaseWidget* UUIManager::OpenWidget(FName Name, FString Param)
{
	return nullptr;
}

UBaseWidget* UUIManager::FindWidget(FName Name)
{
	return nullptr;
}

void UUIManager::CloseWidget(FName Name, FString Param)
{

}

void UUIManager::OpenGroup(FName Name)
{

}

void UUIManager::CloseGroup(FName Name)
{

}

UBaseWidget* UUIManager::OpenDialog(FName Name, FString Param)
{
	return nullptr;
}

UBaseWidget* UUIManager::FindDialog(FName Name)
{
	return nullptr;
}

void UUIManager::CloseDialog(FName Name, FString Param)
{

}

UBaseWidget* UUIManager::CreateWidget(UObject *OwningObject, FName Name)
{
	return nullptr;
}
