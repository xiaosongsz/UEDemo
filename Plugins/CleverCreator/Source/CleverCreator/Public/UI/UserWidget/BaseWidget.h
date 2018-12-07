// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BaseWidget.generated.h"

/**
 * 
 */
UCLASS()
class CLEVERCREATOR_API UBaseWidget : public UUserWidget
{
	GENERATED_BODY()
public:

	void Init();

	void DoOpen(const FString &Param);

	void DoClose(const FString &Param);

	void Close(const FString &Param);

protected:
	virtual void NativeConstruct() override;

	virtual void NativeDestruct() override;

	virtual void NativeOpen(const FString &Param);

	virtual void NativeClose(const FString &Param);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
		void OnOpen(const FString &Param);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
		void OnClose(const FString &Param);
};
