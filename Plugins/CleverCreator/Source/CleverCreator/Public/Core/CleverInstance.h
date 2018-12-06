// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "BaseManager.h"
#include "CleverInstance.generated.h"

/**
 * 
 */
UCLASS(config = Game, transient, BlueprintType, Blueprintable)
class CLEVERCREATOR_API UCleverInstance : public UGameInstance
{
	GENERATED_BODY()
public:

	virtual void Init();

	virtual void Shutdown();

public:

	void AddManager(UClass *ManagerClass);

	UBaseManager* GetManager(UClass *ManagerClass);

	UBaseManager* GetManager(const FName &Name);

protected:
	UPROPERTY()
	TMap<FName, UBaseManager*> ManagerMap;
};
