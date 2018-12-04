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

	template<typename ManagerT>
	ManagerT* GetManager();

	UBaseManager* GetManager(const FName &Name);

protected:
	TMap<FName, UBaseManager> ManagerMap;
};

template<typename ManagerT>
ManagerT* UCleverInstance::GetManager()
{
	if (ManagerT == UBaseManager)
	{
		for (auto& Value : ManagerMap)
		{
			UBaseManager *Manager = Value.second;
			if (Manager->GetClass() == ManagerT)
			{
				return Manager;
			}
		}
	}
	return nullptr;
}
