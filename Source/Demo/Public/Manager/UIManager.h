// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Manager/SBaseManager.h"
#include "UIManager.generated.h"

/**
 * 
 */
UCLASS()
class DEMO_API UUIManager : public USBaseManager
{
	GENERATED_BODY()
public:
	/** virtual function to allow custom GameInstances an opportunity to set up what it needs */
	virtual void Init() override;

	/** virtual function to allow custom GameInstances an opportunity to do cleanup when shutting down */
	virtual void Shutdown() override;

public:

	UFUNCTION(BlueprintCallable)
		void OpenDialog(FName Name);

	UFUNCTION(BlueprintCallable)
		void CloseDialog(FName Name);
};
