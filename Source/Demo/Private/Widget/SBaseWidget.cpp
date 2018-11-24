// Fill out your copyright notice in the Description page of Project Settings.

#include "SBaseWidget.h"

void USBaseWidget::Open(const FString &Param)
{
    
}

void USBaseWidget::Close(const FString &Param)
{
    
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
}

void USBaseWidget::NativeDestruct()
{
    Super::NativeDestruct();
}

void USBaseWidget::OnOpen(const FString &Param)
{
    EStatus = EUIStatus::Open;
    
    ReceiveOpen(Param);
}

void USBaseWidget::OnClose(const FString &Param)
{
    EStatus = EUIStatus::Close;
    
    ReceiveClose(Param);
}

bool USBaseWidget::IsOpen()
{
    return EStatus == EUIStatus::Open;
}
