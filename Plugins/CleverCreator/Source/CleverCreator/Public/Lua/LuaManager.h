// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Core/BaseManager.h"
#include "LuaState.h"
#include "LuaManager.generated.h"

using namespace slua;

/**
 * 
 */
UCLASS()
class CLEVERCREATOR_API ULuaManager : public UBaseManager
{
	GENERATED_BODY()
	
public:

	virtual void Init() override;

	virtual void Shutdown() override;

public:

	LuaState* GetState();

private:
	LuaState State;
};
