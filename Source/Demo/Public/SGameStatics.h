// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "SGameStatics.generated.h"

/**
 * 
 */
UCLASS()
class DEMO_API USGameStatics : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintPure, Category = "SGame", meta = (WorldContext = "WorldContextObject"))
		static class USGameInstance* GetSGameInstance(const UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, Category = "SGame", meta = (WorldContext = "WorldContextObject"))
		static class UUIManager* GetUIManager(const UObject* WorldContextObject);
};
