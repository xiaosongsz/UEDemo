// Fill out your copyright notice in the Description page of Project Settings.

#include "UIManager.h"

void UUIManager::Init()
{
	Super::Init();

	LoadTable();
}

void UUIManager::LoadTable()
{
	FString path = TEXT("/Game/Resources/Tables/UITable.UITable");
	UITable = LoadObject<UDataTable>(this, *path, NULL, LOAD_None, NULL);
	UITable->AddToRoot();
}

void UUIManager::Shutdown()
{
	Super::Shutdown();

	UITable->RemoveFromRoot();
	UITable = nullptr;
}

void UUIManager::OpenUI(FName Name)
{
	FString ContextString;
	FUITableRow *UIInfo = UITable->FindRow<FUITableRow>(Name, ContextString);
	if (UIInfo)
	{
		FText *Desc = &UIInfo->Describe;
		FName *UIName = &UIInfo->Name;
		UE_LOG(LogTemp, Log, TEXT("UUIManager::OpenUI->%s->%s"), UIName, Desc);
	}
}

void UUIManager::CloseUI(FName Name)
{
	UE_LOG(LogTemp, Log, TEXT("UUIManager::CloseUI->%s"), &Name);
}