// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "SGameStatics.generated.h"

/**
 * 游戏静态方法
 */
UCLASS()
class DEMO_API USGameStatics : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
    
    //获取游戏单例
	UFUNCTION(BlueprintPure, Category = "SGame", meta = (WorldContext = "WorldContextObject"))
		static class USGameInstance* GetSGameInstance(const UObject* WorldContextObject);

    //获取UI管理
	UFUNCTION(BlueprintPure, Category = "SGame", meta = (WorldContext = "WorldContextObject"))
		static class UUIManager* GetUIManager(const UObject* WorldContextObject);
};
