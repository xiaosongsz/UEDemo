// Fill out your copyright notice in the Description page of Project Settings.

#include "UIWidget.h"

void UUIWidget::OnOpen(const FString &Param)
{
	ReceiveOpen(Param);

	bIsOpen = true;
}

void UUIWidget::OnClose()
{
	ReceiveClose();

	bIsOpen = false;
}

bool UUIWidget::IsOpen()
{
	return bIsOpen;
}