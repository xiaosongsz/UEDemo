// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Core/CleverInstance.h"
#include "SGameInstance.generated.h"

/**
 * 游戏单例
 */
UCLASS(config = Game, transient, BlueprintType, Blueprintable)
class DEMO_API USGameInstance : public UCleverInstance
{
	GENERATED_BODY()
public:

	/** virtual function to allow custom GameInstances an opportunity to set up what it needs */
	virtual void Init();

	/** virtual function to allow custom GameInstances an opportunity to do cleanup when shutting down */
	virtual void Shutdown();

protected:

	/** Called when the game instance is started either normally or through PIE. */
	virtual void OnStart();
};
