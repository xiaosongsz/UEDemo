// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UIWidget.generated.h"

/**
 * ´°¿ÚUI
 */
UCLASS()
class UUIWidget : public UUserWidget
{
	GENERATED_BODY()
public:

	virtual void OnOpen(const FString &Param);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic, meta = (DisplayName = "OnOpen"))
		void ReceiveOpen(const FString &Param);

	virtual void OnClose();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic, meta = (DisplayName = "OnClose"))
		void ReceiveClose();

	UFUNCTION(BlueprintPure)
	bool IsOpen();
private:
	bool bIsOpen;
};
