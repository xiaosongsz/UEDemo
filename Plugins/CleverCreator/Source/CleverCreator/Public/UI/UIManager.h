// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Core/BaseManager.h"
#include "UserWidget/BaseWidget.h"
#include "UIManager.generated.h"

UENUM(BlueprintType)
enum class EWidgetHierarchy : uint8
{
	Basic,

	Dialog,

	Notice
};

/**
 *
 */
USTRUCT(BlueprintType)
struct FWidgetTableRow : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FText Describe;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSoftClassPtr<UBaseWidget> Widget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		uint8 ZOrder;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		EWidgetHierarchy Hierarchy;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bStack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bMulti;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		ESlateVisibility Visibility;
};

/**
 *
 */
USTRUCT(BlueprintType)
struct FGroupTableRow : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FText Describe;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName ParentName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FName> WidgetNames;
};

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
		UBaseWidget* CreateWidget(UObject *OwningObject, FName Name);

protected:

	UPROPERTY()
		TMap<FName, FGroupTableRow> GroupMap;

	UPROPERTY()
		TMap<FName, FWidgetTableRow> TypeMap;

	UPROPERTY()
		TArray<UBaseWidget*> WidgetMap;
};
