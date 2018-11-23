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
	//基础
	Basic,

	//对话框
	Dialog,

	//公告
	Notice
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

	//名字
	FName Name;

	//描述
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FText Describe;

	//控件
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSoftClassPtr<UUIWidget> UIWidget;
	
	//层级
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

	//打开UI
	UFUNCTION(BlueprintCallable)
		void OpenUI(FName Name, FString Param);

	//关闭UI
	UFUNCTION(BlueprintCallable)
		void CloseUI(FName Name);

private:

	//UI表
	UDataTable *UITable;

	//存在的UI
	TMap<FName, UUIWidget*> UIMap;
};
