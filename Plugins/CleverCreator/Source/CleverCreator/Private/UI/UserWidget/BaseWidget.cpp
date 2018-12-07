// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseWidget.h"

DEFINE_LOG_CATEGORY_STATIC(BaseWidget, Log, All);

void UBaseWidget::Init()
{

}

void UBaseWidget::DoOpen(const FString &Param)
{

}

void UBaseWidget::DoClose(const FString &Param)
{

}

void UBaseWidget::Close(const FString &Param)
{

}

void UBaseWidget::NativeConstruct()
{
	UE_LOG(BaseWidget, Log, TEXT("NativeConstruct"));
}

void UBaseWidget::NativeDestruct()
{
	UE_LOG(BaseWidget, Log, TEXT("NativeDestruct"));
}

void UBaseWidget::NativeOpen(const FString &Param)
{
	UE_LOG(BaseWidget, Log, TEXT("NativeOpen"));
}

void UBaseWidget::NativeClose(const FString &Param)
{
	UE_LOG(BaseWidget, Log, TEXT("NativeClose"));
}
