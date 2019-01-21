// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CleverInstance.h"
#include "BaseManager.generated.h"
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

	virtual void LoadTable();

protected:
	UCleverInstance* GameInstance;
};