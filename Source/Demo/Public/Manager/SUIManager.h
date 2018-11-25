// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Widget/SBaseWidget.h"
#include "Manager/SBaseManager.h"
#include "SUIManager.generated.h"

/**
 * UI层级枚举
 */
UENUM(BlueprintType)
enum class EUIHierarchy : uint8
{
    Basic,
    
    Dialog,
    
    Notice
};

/**
 * UI配置结构体
 */
USTRUCT(BlueprintType)
struct FWidgetTableRow : public FTableRowBase
{
    GENERATED_USTRUCT_BODY()
    
	FWidgetTableRow()
    {
        Hierarchy = EUIHierarchy::Dialog;
    }
    
    /**
     * Can be overridden by subclasses; Called whenever the owning data table is imported or re-imported.
     * Allows for custom fix-ups, parsing, etc. after initial data is read in.
     *
     * @param InDataTable                    The data table that owns this row
     * @param InRowName                        The name of the row we're performing fix-up on
     * @param OutCollectedImportProblems    List of problems accumulated during import; Can be added to via this method
     */
    virtual void OnPostDataImport(const UDataTable* InDataTable, const FName InRowName, TArray<FString>& OutCollectedImportProblems)
    {
        Name = InRowName;
    }
public:
    
    FName Name;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        FText Describe;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        TSoftClassPtr<USBaseWidget> Widget;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        EUIHierarchy Hierarchy;
};

/**
 * UI管理
 */
UCLASS(NotBlueprintable)
class DEMO_API USUIManager : public USBaseManager
{
    GENERATED_BODY()
public:
    
    virtual void Init() override;
    
    virtual void Shutdown() override;
    
private:
    
    void LoadTable();
public:
    
    UFUNCTION(BlueprintCallable)
		USBaseWidget* OpenWidget(FName Name, FString Param = "");
    
    UFUNCTION(BlueprintCallable)
        void CloseWidget(FName Name, FString Param = "");
    
	UFUNCTION(BlueprintCallable)
		void Clear(FString Param = "");

protected:
    
    UDataTable *WidgetTable;
    
    TMap<FName, USBaseWidget*> AllWidget;
};
