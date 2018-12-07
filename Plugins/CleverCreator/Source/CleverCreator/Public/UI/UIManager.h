// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Core/BaseManager.h"
#include "UIManager.generated.h"

class UBaseWidget;

/**
 * 
 */
UCLASS()
class CLEVERCREATOR_API UUIManager : public UBaseManager
{
	GENERATED_BODY()
	
public:
	virtual void Init() override;

	virtual void Shutdown() override;

public:

	UFUNCTION()
		UBaseWidget* OpenWidget(FName Name, FString Param);

	UFUNCTION()
		UBaseWidget* FindWidget(FName Name);

	UFUNCTION()
		void CloseWidget(FName Name, FString Param);

	UFUNCTION()
		void OpenGroup(FName Name);

	UFUNCTION()
		void CloseGroup(FName Name);

	UFUNCTION()
		UBaseWidget* OpenDialog(FName Name, FString Param);

	UFUNCTION()
		UBaseWidget* FindDialog(FName Name);

	UFUNCTION()
		void CloseDialog(FName Name, FString Param);

	UFUNCTION()
		UBaseWidget* CreateWidget(UObject *OwningObject, FName Name);

protected:

	UPROPERTY()
		UDataTable *GroupTable;

	UPROPERTY()
		UDataTable *WidgetTable;

	UPROPERTY()
		TMap<FName, UBaseWidget*> WidgetMap;
};
