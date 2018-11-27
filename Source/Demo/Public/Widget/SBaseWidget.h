// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SBaseWidget.generated.h"

struct FWidgetTableRow;

UENUM(BlueprintType)
enum class EWidgetStatus : uint8
{
	Construct,
    Open,
    Close,
	Destruct
};

/**
 * 
 */
UCLASS(Abstract, editinlinenew, BlueprintType, Blueprintable, meta = (DontUseGenericSpawnObject = "True", DisableNativeTick))
class DEMO_API USBaseWidget : public UUserWidget
{
	GENERATED_BODY()
public:

	void SetInfo(FWidgetTableRow *WidgetInfo);

    void Open(const FString &Param = "");
    
    void Close(const FString &Param = "");
    
    UFUNCTION(BlueprintPure)
		EWidgetStatus GetStatus();

	UFUNCTION(BlueprintCallable)
		void CloseWidget(const FString &Param = "");

	FWidgetTableRow* GetInfo();

	UFUNCTION(BlueprintPure)
		USBaseWidget* GetRoot();
    
protected:

    virtual void NativeConstruct() override;

    virtual void NativeDestruct() override;
    
    virtual void OnOpen(const FString &Param);
    
    virtual void OnClose(const FString &Param);
    
    UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic, meta = (DisplayName = "OnOpen"))
        void ReceiveOpen(const FString &Param);
    
    UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic, meta = (DisplayName = "OnClose"))
        void ReceiveClose(const FString &Param);

protected:

	USBaseWidget *Root;

	FWidgetTableRow *WidgetInfo;

	EWidgetStatus WidgetStatus;
};
