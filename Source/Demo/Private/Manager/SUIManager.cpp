// Fill out your copyright notice in the Description page of Project Settings.

#include "SUIManager.h"
#include "Kismet/GameplayStatics.h"

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
			Widget = CreateWidget<USBaseWidget>(UGameplayStatics::GetPlayerController(GetWorld(), 0), WidgetRow->Widget.LoadSynchronous());

			if (Widget)
			{
				AllWidget.Add(Name, Widget);
				Widget->AddToViewport((int32)WidgetRow->Hierarchy);
			}
		}

		if (Widget && !Widget->IsOpen())
		{
			Widget->Open(Param);
		}
    }

	return Widget;
}

void USUIManager::CloseWidget(FName Name, FString Param)
{
	USBaseWidget **WidgetPtr = AllWidget.Find(Name);
	USBaseWidget *Widget = WidgetPtr ? *WidgetPtr : nullptr;

	if (Widget->IsOpen())
	{
		Widget->Close(Param);
	}
}

void USUIManager::Clear(FString Param)
{
	for (auto& WidgetElem : AllWidget)
	{
		USBaseWidget *Widget = WidgetElem.Value;

		if (Widget->IsOpen())
		{
			Widget->Close(Param);
		}

		Widget->RemoveFromParent();
	}

	AllWidget.Empty();
}