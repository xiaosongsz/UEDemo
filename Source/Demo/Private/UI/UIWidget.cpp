// Fill out your copyright notice in the Description page of Project Settings.

#include "UIWidget.h"

void UUIWidget::OnOpen(const FString &Param)
{
	ReceiveOpen(Param);

	EStatus = EUIStatus::Open;
}

void UUIWidget::OnClose()
{
	ReceiveClose();

	EStatus = EUIStatus::Close;
}

bool UUIWidget::IsOpen()
{
    return EStatus == EUIStatus::Open;
}
