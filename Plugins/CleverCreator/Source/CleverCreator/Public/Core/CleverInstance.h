// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "CleverInstance.generated.h"

class UBaseManager;
class ULuaManager;
class USceneManager;
class UUIManager;

/**
 * 
 */
UCLASS(config = Game, transient, BlueprintType, Blueprintable)
class CLEVERCREATOR_API UCleverInstance : public UGameInstance
{
	GENERATED_BODY()
public:

	virtual void Init() override;

	virtual void Shutdown() override;

public:

	UFUNCTION(BlueprintCallable)
		void AddManager(UClass *ManagerClass);

	UBaseManager* GetManager(UClass *ManagerClass);

	UFUNCTION(BlueprintCallable)
		UBaseManager* GetManager(const FName &Name);

public:
	UFUNCTION(BlueprintPure)
		ULuaManager* GetLuaManager();

	UFUNCTION(BlueprintPure)
		USceneManager* GetSceneManager();

	UFUNCTION(BlueprintPure)
		UUIManager* GetUIManager();

private:
	ULuaManager *LuaManager;

	USceneManager *SceneManager;

	UUIManager *UIManager;

protected:
	UPROPERTY()
		TMap<FName, UBaseManager*> ManagerMap;
};
