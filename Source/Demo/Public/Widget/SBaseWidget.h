// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SBaseWidget.generated.h"

UENUM(BlueprintType)
enum class EUIStatus : uint8
{
    //创建
    Create,
    
    //打开
    Open,
    
    //隐藏
    Hide,
    
    //关闭
    Close,
    
    //销毁
    Destory
};

/**
 * 
 */
UCLASS()
class DEMO_API USBaseWidget : public UUserWidget
{
	GENERATED_BODY()
public:
    
    /**
     打开

     @param Param 参数
     */
    void Open(const FString &Param);
    
    
    /**
     关闭

     @param Param 参数
     */
    void Close(const FString &Param);
    
    
    /**
     打开状态

     @param BlueprintPure BlueprintPure
     @return 是否打开
     */
    UFUNCTION(BlueprintPure)
        bool IsOpen();
    
protected:
    
    virtual void NativeOnInitialized() override;
    virtual void NativePreConstruct() override;
    virtual void NativeConstruct() override;
    virtual void NativeDestruct() override;
    
    /**
     当控件打开时回调

     @param Param 参数
     */
    virtual void OnOpen(const FString &Param);
    
    
    /**
     当控件关闭时回调

     @param Param 参数
     */
    virtual void OnClose(const FString &Param);
    
    /**
     当控件打开时回调
     
     @param BlueprintImplementableEvent BlueprintImplementableEvent
     @param BlueprintCosmetic BlueprintCosmetic
     @param "OnOpen" "OnOpen"
     @return return value
     */
    UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic, meta = (DisplayName = "OnOpen"))
        void ReceiveOpen(const FString &Param);
    
    /**
     当控件关闭时回调

     @param BlueprintImplementableEvent BlueprintImplementableEvent
     @param BlueprintCosmetic BlueprintCosmetic
     @param "OnClose" "OnClose"
     @return return value
     */
    UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic, meta = (DisplayName = "OnClose"))
        void ReceiveClose(const FString &Param);
private:
    EUIStatus EStatus;
};
