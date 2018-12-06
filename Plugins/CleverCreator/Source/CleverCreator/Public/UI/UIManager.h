// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Core/BaseManager.h"
#include "UIManager.generated.h"

/**
 * 
 */
UCLASS()
class CLEVERCREATOR_API UUIManager : public UBaseManager
{
	GENERATED_BODY()
	
public:
	virtual void Init();

	virtual void Shutdown();

};
