// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CleverFunctionLibrary.generated.h"

class UCleverInstance;
class ULuaManager;
class USceneManager;
class UUIManager;

/**
 * 
 */
UCLASS()
class CLEVERCREATOR_API UCleverFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintPure, meta = (WorldContext = "WorldContextObject"))
		static UCleverInstance* GetCleverInstance(const UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, meta = (WorldContext = "WorldContextObject"))
		static ULuaManager* GetLuaManager(const UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, meta = (WorldContext = "WorldContextObject"))
		static USceneManager* GetSceneManager(const UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, meta = (WorldContext = "WorldContextObject"))
		static UUIManager* GetUIManager(const UObject* WorldContextObject);
};
