// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenUserWidget_JournalSoulConstellationNodeMap.generated.h"

/**
 * UAshenUserWidget_JournalSoulConstellationNodeMap
 * UMG widget backing class rendering interactive constellation nodes in journal.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_JournalSoulConstellationNodeMap : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void OnSoulStateInvalidated(const FSoulStateVector& StateVector);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	int32 GetUnlockedConstellationNodeCount() const { return UnlockedConstellationNodeCount; }

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|UI")
	int32 UnlockedConstellationNodeCount = 1;
};
