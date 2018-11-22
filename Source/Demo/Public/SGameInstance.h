// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "SGameInstance.generated.h"

class UUIManager;

/**
 * 游戏单例
 */
UCLASS()
class DEMO_API USGameInstance : public UGameInstance
{
	GENERATED_BODY()
public:

	/** virtual function to allow custom GameInstances an opportunity to set up what it needs */
	virtual void Init();

	/** virtual function to allow custom GameInstances an opportunity to do cleanup when shutting down */
	virtual void Shutdown();

public:
    
    //获取UI管理
	UFUNCTION(BlueprintPure)
	UUIManager* GetUIManager();
private:
	UUIManager* UIManager;
};
