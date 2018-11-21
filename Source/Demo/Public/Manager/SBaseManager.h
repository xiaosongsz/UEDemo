// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SBaseManager.generated.h"

/**
 * 
 */
UCLASS()
class DEMO_API USBaseManager : public UObject
{
	GENERATED_BODY()
public:
	/** virtual function to allow custom GameInstances an opportunity to set up what it needs */
	virtual void Init();

	/** virtual function to allow custom GameInstances an opportunity to do cleanup when shutting down */
	virtual void Shutdown();
};
