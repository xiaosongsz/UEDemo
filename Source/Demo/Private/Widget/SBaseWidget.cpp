// Fill out your copyright notice in the Description page of Project Settings.

#include "SBaseWidget.h"
#include "Blueprint/WidgetTree.h"

void USBaseWidget::Open(const FString &Param)
{
	WidgetTree->ForEachWidget([&Param](UWidget* Widget){
		
		USBaseWidget *ChildWidget = dynamic_cast<USBaseWidget*>(Widget);
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

		USBaseWidget *ChildWidget = dynamic_cast<USBaseWidget*>(Widget);
		if (ChildWidget)
		{
			ChildWidget->Close(Param);
		}

	});

	OnClose(Param);
}

void USBaseWidget::NativeOnInitialized()
{
    Super::NativeOnInitialized();
}

void USBaseWidget::NativePreConstruct()
{
    Super::NativePreConstruct();
}

void USBaseWidget::NativeConstruct()
{
    Super::NativeConstruct();

	EStatus = EUIStatus::Create;
	
	UE_LOG(LogTemp, Log, TEXT("USBaseWidget::NativeConstruct()"));
}

void USBaseWidget::NativeDestruct()
{
    Super::NativeDestruct();

	if (EStatus == EUIStatus::Destory)
	{
		return;
	}

	if (EStatus != EUIStatus::Close)
	{
		Close();
	}

	EStatus = EUIStatus::Destory;
}

void USBaseWidget::OnOpen(const FString &Param)
{
    EStatus = EUIStatus::Open;
    
    ReceiveOpen(Param);

	UE_LOG(LogTemp, Log, TEXT("USBaseWidget::OnOpen()"));
}

void USBaseWidget::OnClose(const FString &Param)
{
    EStatus = EUIStatus::Close;
    
    ReceiveClose(Param);

	UE_LOG(LogTemp, Log, TEXT("USBaseWidget::OnClose()"));
}

bool USBaseWidget::IsOpen()
{
    return EStatus == EUIStatus::Open;
}
