// Fill out your copyright notice in the Description page of Project Settings.

#include "UIManager.h"

DEFINE_LOG_CATEGORY_STATIC(UIManager, Log, All);

void UUIManager::Init()
{
	Super::Init();

	//FString UITablePath = TEXT("/Game/Resources/Tables/WidgetTable.WidgetTable");
	//WidgetTable = LoadObject<UDataTable>(this, *UITablePath);

	UE_LOG(UIManager, Log, TEXT("Init"));
}

void UUIManager::Shutdown()
{
	Super::Shutdown();

	UE_LOG(UIManager, Log, TEXT("Shutdown"));
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

UBaseWidget* UUIManager::CreateWidget(UObject *OwningObject, FName Name)
{
	return nullptr;
}
