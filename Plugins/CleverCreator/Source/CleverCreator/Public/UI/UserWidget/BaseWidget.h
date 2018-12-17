// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BaseWidget.generated.h"

struct FWidgetTableRow;

UENUM()
enum class EWidgetState
{
	Construct,
	Open,
	Close,
	Destruct
};

/**
 * 
 */
UCLASS()
class CLEVERCREATOR_API UBaseWidget : public UUserWidget
{
	GENERATED_BODY()
public:

	void DoOpen(const FString &Param);

	void DoClose(const FString &Param);

	UFUNCTION(BlueprintCallable)
		void Close(const FString &Param);

	UFUNCTION(BlueprintPure)
		EWidgetState GetState();

	void SetInfo(const FWidgetTableRow *Info);

	const FWidgetTableRow* GetInfo();

	UFUNCTION(BlueprintPure)
		UBaseWidget* GetCreator();

	UFUNCTION(BlueprintPure)
		UBaseWidget* GetRoot();

protected:

	virtual void NativeConstruct() override;

	virtual void NativeDestruct() override;

	virtual void NativeOpen(const FString &Param);

	virtual void NativeClose(const FString &Param);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
		void OnOpen(const FString &Param);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
		void OnClose(const FString &Param);

private:
	const FWidgetTableRow *Info;

	EWidgetState State;

	UBaseWidget *Creator;

	UBaseWidget *Root;
};
