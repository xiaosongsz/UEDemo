// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseWidget.h"
#include "Blueprint/WidgetTree.h"
#include "UI/UIManager.h"
#include "CleverFunctionLibrary.h"

DEFINE_LOG_CATEGORY_STATIC(BaseWidget, Log, All);

void UBaseWidget::DoOpen(const FString &Param)
{
	WidgetTree->ForEachWidget([&Param](UWidget* Widget) {

		UBaseWidget *ChildWidget = Cast<UBaseWidget>(Widget);
		if (ChildWidget)
		{
			ChildWidget->DoOpen(Param);
		}
	});

	NativeOpen(Param);
}

void UBaseWidget::DoClose(const FString &Param)
{
	WidgetTree->ForEachWidget([&Param](UWidget* Widget) {

		UBaseWidget *ChildWidget = Cast<UBaseWidget>(Widget);
		if (ChildWidget)
		{
			ChildWidget->DoClose(Param);
		}
	});

	NativeClose(Param);
}

void UBaseWidget::Close(const FString &Param)
{
	UUIManager *UIManager = UCleverFunctionLibrary::GetUIManager(GetWorld());
	if (UIManager)
	{
		UIManager->CloseWidget(GetInfo()->Name, Param);
	}
}

EWidgetState UBaseWidget::GetState()
{
	return State;
}

void UBaseWidget::SetInfo(const FWidgetTableRow *WidgetTableRow)
{
	Info = WidgetTableRow;
}

const FWidgetTableRow* UBaseWidget::GetInfo()
{
	if (!Info)
	{
		Info = GetRoot()->Info;
	}

	return Info;
}

UBaseWidget* UBaseWidget::GetCreator()
{
	if (!Creator)
	{
		Creator = Cast<UBaseWidget>(GetOuter()->GetOuter());
	}

	return Creator;
}

UBaseWidget* UBaseWidget::GetRoot()
{
	if (!Root)
	{
		if (GetCreator())
		{
			Root = Creator->GetRoot();
		}
		else
		{
			Root = this;
		}
	}

	return Root;
}

void UBaseWidget::NativeConstruct()
{
	State = EWidgetState::Construct;

	UE_LOG(BaseWidget, Log, TEXT("NativeConstruct"));
}

void UBaseWidget::NativeDestruct()
{
	State = EWidgetState::Destruct;

	UE_LOG(BaseWidget, Log, TEXT("NativeDestruct"));
}

void UBaseWidget::NativeOpen(const FString &Param)
{
	State = EWidgetState::Open;

	OnOpen(Param);

	UE_LOG(BaseWidget, Log, TEXT("NativeOpen"));
}

void UBaseWidget::NativeClose(const FString &Param)
{
	State = EWidgetState::Close;

	OnClose(Param);

	UE_LOG(BaseWidget, Log, TEXT("NativeClose"));
}
