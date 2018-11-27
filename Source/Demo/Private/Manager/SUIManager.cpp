// Fill out your copyright notice in the Description page of Project Settings.

#include "SUIManager.h"
#include "SGameInstance.h"

void USUIManager::Init()
{
    Super::Init();
    
    LoadTable();
}

void USUIManager::LoadTable()
{
    FString UITablePath = TEXT("/Game/Resources/Tables/SWidgetTable.SWidgetTable");
    WidgetTable = LoadObject<UDataTable>(this, *UITablePath);
}

void USUIManager::Shutdown()
{
    Super::Shutdown();

	Clear();
    
	WidgetTable = nullptr;
}

USBaseWidget* USUIManager::OpenWidget(FName Name, FString Param)
{
	USBaseWidget *Widget = nullptr;

    FString ContextString;
	FWidgetTableRow *WidgetRow = WidgetTable->FindRow<FWidgetTableRow>(Name, ContextString);
    if (WidgetRow)
    {
        USBaseWidget **WidgetPtr = AllWidget.Find(Name);
        Widget = WidgetPtr ? *WidgetPtr : nullptr;

		if (!Widget)
		{
			Widget = CreateWidget<USBaseWidget>(SGameInstance->GetFirstLocalPlayerController(), WidgetRow->Widget.LoadSynchronous());

			if (Widget)
			{
				Widget->SetInfo(WidgetRow);

				AllWidget.Add(Name, Widget);
				Widget->AddToViewport((int32)WidgetRow->Hierarchy);

				if (Widget->GetStatus() != EWidgetStatus::Open)
				{
					Widget->Open(Param);
				}
			}
		}
    }

	return Widget;
}

void USUIManager::CloseWidget(FName Name, FString Param)
{
	USBaseWidget **WidgetPtr = AllWidget.Find(Name);
	USBaseWidget *Widget = WidgetPtr ? *WidgetPtr : nullptr;

	if (Widget)
	{
		if (Widget->GetStatus() != EWidgetStatus::Close)
		{
			Widget->Close(Param);
		}

		AllWidget.Remove(Name);

		Widget->RemoveFromParent();
	}
}

void USUIManager::Clear(FString Param)
{
	for (auto& WidgetElem : AllWidget)
	{
		USBaseWidget *Widget = WidgetElem.Value;

		if (Widget->GetStatus() != EWidgetStatus::Close)
		{
			Widget->Close(Param);
		}

		Widget->RemoveFromParent();
	}

	AllWidget.Empty();
}