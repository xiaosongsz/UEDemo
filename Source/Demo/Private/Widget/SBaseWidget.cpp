// Fill out your copyright notice in the Description page of Project Settings.

#include "SBaseWidget.h"
#include "Blueprint/WidgetTree.h"
#include "SGameInstance.h"
#include "Manager/SUIManager.h"

void USBaseWidget::SetInfo(FWidgetTableRow* WidgetInfo)
{
	this->WidgetInfo = WidgetInfo;
}

FWidgetTableRow* USBaseWidget::GetInfo()
{
	if (!WidgetInfo)
	{
		WidgetInfo = GetRoot()->WidgetInfo;
	}

	return WidgetInfo;
}

USBaseWidget* USBaseWidget::GetRoot()
{
	if (!Root)
	{
		USBaseWidget *Creator = Cast<USBaseWidget>(GetOuter()->GetOuter());

		if (Creator)
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

void USBaseWidget::Open(const FString &Param)
{
	WidgetTree->ForEachWidget([&Param](UWidget* Widget){
		
		USBaseWidget *ChildWidget = Cast<USBaseWidget>(Widget);
		if (ChildWidget)
		{
			ChildWidget->Open(Param);
		}
		
	});

	OnOpen(Param);
}

void USBaseWidget::Close(const FString &Param)
{
	WidgetTree->ForEachWidget([&Param](UWidget* Widget) {

		USBaseWidget *ChildWidget = Cast<USBaseWidget>(Widget);
		if (ChildWidget)
		{
			ChildWidget->Close(Param);
		}

	});

	OnClose(Param);
}

void USBaseWidget::NativeConstruct()
{
    Super::NativeConstruct();

	WidgetStatus = EWidgetStatus::Construct;

	//UE_LOG(LogTemp, Log, TEXT("USBaseWidget::NativeConstruct() %s"), *GetFName().ToString());
}

void USBaseWidget::NativeDestruct()
{
    Super::NativeDestruct();

	if (WidgetStatus == EWidgetStatus::Destruct)
	{
		return;
	}

	if (WidgetStatus != EWidgetStatus::Close)
	{
		Close();
	}

	WidgetStatus = EWidgetStatus::Destruct;

	//UE_LOG(LogTemp, Log, TEXT("USBaseWidget::NativeDestruct() %s"), *GetFName().ToString());
}

void USBaseWidget::OnOpen(const FString &Param)
{
	WidgetStatus = EWidgetStatus::Open;
    
    ReceiveOpen(Param);
}

void USBaseWidget::OnClose(const FString &Param)
{
	WidgetStatus = EWidgetStatus::Close;
    
    ReceiveClose(Param);
}

EWidgetStatus USBaseWidget::GetStatus()
{
	return WidgetStatus;
}

void USBaseWidget::CloseWidget(const FString &Param)
{
	FWidgetTableRow *WidgetInfo = GetInfo();
	if (WidgetInfo)
	{
		GetGameInstance<USGameInstance>()->GetUIManager()->CloseWidget(WidgetInfo->Name, Param);
	}
}