// Fill out your copyright notice in the Description page of Project Settings.

#include "UIWidget.h"

void UUIWidget::OnOpen(const FString &Param)
{
	ReceiveOpen(Param);

    EUIStatus = EUIStatus::Open;
}

void UUIWidget::OnClose()
{
	ReceiveClose();

	EUIStatus = EUIStatus::Close;
}

bool UUIWidget::IsOpen()
{
    return EUIStatus == EUIStatus::Open;
}
