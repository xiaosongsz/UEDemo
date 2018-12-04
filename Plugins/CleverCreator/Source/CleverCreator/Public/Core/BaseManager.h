// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseManager.generated.h"

class UCleverInstance;

/**
 * 
 */
UCLASS()
class CLEVERCREATOR_API UBaseManager : public UObject
{
	GENERATED_BODY()

public:
	virtual void Init();

	virtual void Shutdown();

protected:
	UCleverInstance* GameInstance;
};