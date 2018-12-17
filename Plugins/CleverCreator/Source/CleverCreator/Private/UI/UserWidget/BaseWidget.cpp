// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseWidget.h"
#include "UI/UIManager.h"
#include "CleverFunctionLibrary.h"

DEFINE_LOG_CATEGORY_STATIC(BaseWidget, Log, All);

void UBaseWidget::DoOpen(const FString &Param)
{

}

void UBaseWidget::DoClose(const FString &Param)
{
	RemoveFromParent();
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

	UE_LOG(BaseWidget, Log, TEXT("NativeOpen"));
}

void UBaseWidget::NativeClose(const FString &Param)
{
	State = EWidgetState::Close;

	UE_LOG(BaseWidget, Log, TEXT("NativeClose"));
}
