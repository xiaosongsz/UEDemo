// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Core/BaseManager.h"
#include "UserWidget/BaseWidget.h"
#include "UIManager.generated.h"

/**
 *
 */
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
struct FGroupWidgetTableRow : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString Param;
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
		TArray<FGroupWidgetTableRow> Widgets;
};

/**
 * 
 */
UCLASS(Config = Clever, defaultconfig)
class CLEVERCREATOR_API UUIManager : public UBaseManager
{
	GENERATED_BODY()
	
public:

	virtual void Init() override;

	virtual void Shutdown() override;

public:

	UFUNCTION(BlueprintCallable)
		UBaseWidget* OpenWidget(FName Name, FString Param);

	UFUNCTION(BlueprintCallable)
		UBaseWidget* FindWidget(FName Name);

	UFUNCTION(BlueprintCallable)
		void CloseWidget(FName Name, FString Param);

	UFUNCTION(BlueprintCallable)
		void ClearWidgets();

	UFUNCTION(BlueprintCallable)
		void OpenGroup(FName Name);

	UFUNCTION(BlueprintCallable)
		void CloseGroup(FName Name);

	UFUNCTION(BlueprintCallable)
		UBaseWidget* GetWidget(FName Name);

protected:

	virtual void LoadTable() override;

protected:

	UPROPERTY(Config)
		FSoftObjectPath WidgetTablePath;

	UPROPERTY(Config)
		FSoftObjectPath GroupTablePath;

	UPROPERTY()
		TMap<FName, FGroupTableRow> GroupMap;

	UPROPERTY()
		TMap<FName, FWidgetTableRow> TypeMap;

	UPROPERTY()
		TMap<FName, UBaseWidget*> WidgetMap;
};
