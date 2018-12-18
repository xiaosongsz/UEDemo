// Fill out your copyright notice in the Description page of Project Settings.

#include "UIManager.h"
#include "Core/CleverInstance.h"

DEFINE_LOG_CATEGORY_STATIC(UIManager, Log, All);

void UUIManager::Init()
{
	Super::Init();

	UE_LOG(UIManager, Log, TEXT("Init"));
}

void UUIManager::LoadTable()
{
	UObject *TableObject = WidgetTablePath.TryLoad();
	if (TableObject)
	{
		UDataTable *WidgetTable = Cast<UDataTable>(TableObject);

		if (WidgetTable)
		{
			FString ContextString;
			WidgetTable->ForeachRow<FWidgetTableRow>(ContextString, [this](FName Name, FWidgetTableRow Value) {
				TypeMap.Add(Value.Name, Value);
			});
		}
	}

	TableObject = GroupTablePath.TryLoad();
	if (TableObject)
	{
		UDataTable *WidgetTable = Cast<UDataTable>(TableObject);

		if (WidgetTable)
		{
			FString ContextString;
			WidgetTable->ForeachRow<FGroupTableRow>(ContextString, [this](FName Name, FGroupTableRow Value) {
				GroupMap.Add(Value.Name, Value);
			});
		}
	}
}

void UUIManager::Shutdown()
{
	Super::Shutdown();

	UE_LOG(UIManager, Log, TEXT("Shutdown"));
}

UBaseWidget* UUIManager::OpenWidget(FName Name, FString Param)
{
	UBaseWidget *Widget = FindWidget(Name);

	if (!Widget)
	{
		Widget = GetWidget(Name);

		if (Widget)
		{
			WidgetMap.Add(Name, Widget);

			uint8 Hierarchy = (uint8)Widget->GetInfo()->Hierarchy;
			uint8 ZOrder = Widget->GetInfo()->ZOrder;
			int32 RealZOrder = Hierarchy * 100 + ZOrder;
			Widget->AddToViewport(ZOrder);
		}
	}

	if (Widget)
	{
		Widget->DoOpen(Param);
	}

	return Widget;
}

UBaseWidget* UUIManager::FindWidget(FName Name)
{
	UBaseWidget *Widget = nullptr;

	UBaseWidget **WidgetPtr = WidgetMap.Find(Name);

	Widget = WidgetPtr ? *WidgetPtr : nullptr;

	return Widget;
}

void UUIManager::CloseWidget(FName Name, FString Param)
{
	UBaseWidget *Widget = FindWidget(Name);

	if (Widget)
	{
		Widget->DoClose(Param);

		Widget->RemoveFromParent();
		WidgetMap.Remove(Name);
	}
}

void UUIManager::ClearWidgets()
{
	for (TPair<FName, UBaseWidget*> Pair : WidgetMap)
	{
		FName Name = Pair.Key;
		CloseWidget(Name, "");
	}
}

void UUIManager::OpenGroup(FName Name)
{
	TArray<FGroupTableRow*> AllGroup;

	FGroupTableRow *Group = GroupMap.Find(Name);
	
	while (Group)
	{
		AllGroup.Add(Group);
		Group = GroupMap.Find(Group->ParentName);
	}

	for (FGroupTableRow *AGroup : AllGroup)
	{
		for (FGroupWidgetTableRow Widget : AGroup->Widgets)
		{
			OpenWidget(Widget.Name, Widget.Param);
		}
	}
}

void UUIManager::CloseGroup(FName Name)
{
	TArray<FGroupTableRow*> AllGroup;

	FGroupTableRow *Group = GroupMap.Find(Name);

	while (Group)
	{
		AllGroup.Add(Group);
		Group = GroupMap.Find(Group->ParentName);
	}

	for (FGroupTableRow *AGroup : AllGroup)
	{
		for (FGroupWidgetTableRow Widget : AGroup->Widgets)
		{
			CloseWidget(Widget.Name, Widget.Param);
		}
	}
}

UBaseWidget* UUIManager::GetWidget(FName Name)
{
	UBaseWidget *Widget = nullptr;

	FString ContextString;
	FWidgetTableRow *WidgetRow = TypeMap.Find(Name);

	if (WidgetRow)
	{
		Widget = CreateWidget<UBaseWidget>(GameInstance, WidgetRow->Widget.LoadSynchronous());
		Widget->SetInfo(WidgetRow);
	}

	return Widget;
}
