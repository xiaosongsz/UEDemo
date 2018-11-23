// Fill out your copyright notice in the Description page of Project Settings.

#include "UIManager.h"
#include "Kismet/GameplayStatics.h"

void UUIManager::Init()
{
	Super::Init();

	LoadTable();
}

void UUIManager::LoadTable()
{
	FString UITablePath = TEXT("/Game/Resources/Tables/UITable.UITable");
	UITable = LoadObject<UDataTable>(this, *UITablePath);
}

void UUIManager::Shutdown()
{
	Super::Shutdown();

	UITable = nullptr;
}

void UUIManager::OpenUI(FName Name, FString Param)
{
	FString ContextString;
	FUITableRow *UIInfo = UITable->FindRow<FUITableRow>(Name, ContextString);
	if (UIInfo)
	{
        UUIWidget **WidgetPtr = UIMap.Find(Name);
        UUIWidget *Widget = WidgetPtr ? *WidgetPtr : nullptr;

		if (!Widget)
		{
			Widget = CreateWidget<UUIWidget>(UGameplayStatics::GetPlayerController(GetWorld(), 0), UIInfo->UIWidget.LoadSynchronous());

			if (Widget)
			{
				UIMap.Add(Name, Widget);
				Widget->AddToViewport((int32)UIInfo->UIHierarchy);
			}
		}

		if (Widget && !Widget->IsOpen())
		{
			Widget->OnOpen(Param);
		}
	}

	UE_LOG(LogTemp, Log, TEXT("UIManager::OpenUI->%s"), &Name);
}

void UUIManager::CloseUI(FName Name)
{
    UUIWidget **WidgetPtr = UIMap.Find(Name);
    UUIWidget *Widget = WidgetPtr ? *WidgetPtr : nullptr;

	if (Widget->IsOpen())
	{
		Widget->OnClose();
	}

	UE_LOG(LogTemp, Log, TEXT("UIManager::CloseUI->%s"), &Name);
}
