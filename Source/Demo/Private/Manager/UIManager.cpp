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

void UUIManager::OpenUI(FName Name, FString Param)
{
	FString ContextString;
	FUITableRow *UIInfo = UITable->FindRow<FUITableRow>(Name, ContextString);
	if (UIInfo)
	{
		UUIWidget *Widget = UIMap.Find(Name);

		if (!Widget)
		{
			//Widget = LoadObject<UUIWidget>(this, );
		}

		if (!Widget->IsOpen())
		{
			Widget->OnOpen(Param);
		}

		UE_LOG(LogTemp, Log, TEXT("UIManager::OpenUI->%s"), &Name);
	}
}

void UUIManager::CloseUI(FName Name)
{
	UUIWidget *Widget = UIMap.Find(Name);

	if (Widget->IsOpen())
	{
		Widget->OnClose();
	}

	UE_LOG(LogTemp, Log, TEXT("UIManager::CloseUI->%s"), &Name);
}