// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_RevisitedMemoriesInspector.generated.h"

/**
 * UAshenUserWidget_RevisitedMemoriesInspector
 * UMG widget inspecting evolving revisited memories across campaign acts.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_RevisitedMemoriesInspector : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	int32 TotalRevisitedPagesCount = 0;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void RefreshRevisitedMemoriesDisplay(int32 PageCount);
};
