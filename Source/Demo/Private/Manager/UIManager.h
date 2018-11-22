// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "UI/UIWidget.h"
#include "Manager/SBaseManager.h"
#include "UIManager.generated.h"

/**
* UI层级枚举
*/
UENUM(BlueprintType)
enum class EUIHierarchy : uint8
{
	Basic = 10,

	Dialog = 20,

	Notice = 30
};

/**
* UI配置结构体
*/
USTRUCT(BlueprintType)
struct FUITableRow : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	FUITableRow()
	{
		UIHierarchy = EUIHierarchy::Dialog;
	}

	/**
	 * Can be overridden by subclasses; Called whenever the owning data table is imported or re-imported.
	 * Allows for custom fix-ups, parsing, etc. after initial data is read in.
	 *
	 * @param InDataTable					The data table that owns this row
	 * @param InRowName						The name of the row we're performing fix-up on
	 * @param OutCollectedImportProblems	List of problems accumulated during import; Can be added to via this method
	 */
	virtual void OnPostDataImport(const UDataTable* InDataTable, const FName InRowName, TArray<FString>& OutCollectedImportProblems)
	{
		//UI名 = 行名
		Name = InRowName;
	}
public:

	FName Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FText Describe;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSoftClassPtr<UUIWidget> UIWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		EUIHierarchy UIHierarchy;
};

/**
 * UI管理
 */
UCLASS(NotBlueprintable)
class DEMO_API UUIManager : public USBaseManager
{
	GENERATED_BODY()
public:

	virtual void Init() override;

	virtual void Shutdown() override;
	
private:

	void LoadTable();
public:

	UFUNCTION(BlueprintCallable)
		void OpenUI(FName Name);

	UFUNCTION(BlueprintCallable)
		void CloseUI(FName Name);

private:
	UDataTable *UITable;
};
