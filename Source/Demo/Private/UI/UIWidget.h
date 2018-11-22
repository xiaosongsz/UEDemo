// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UIWidget.generated.h"

UENUM()
enum class EUIStatus : uint8
{
    //创建
    Create,
    
    //打开
    Open,
    
    //关闭
    Close,
    
    //销毁
    Destory
};

/**
 * UI管理
 */
UCLASS()
class UUIWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	//当UI打开
	virtual void OnOpen(const FString &Param);

	//当UI打开
	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic, meta = (DisplayName = "OnOpen"))
		void ReceiveOpen(const FString &Param);

	//当UI关闭
	virtual void OnClose();

	//当UI关闭
	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic, meta = (DisplayName = "OnClose"))
		void ReceiveClose();

	//UI是否打开
	UFUNCTION(BlueprintPure)
	bool IsOpen();
private:
	EUIStatus EUIStatus;
};
