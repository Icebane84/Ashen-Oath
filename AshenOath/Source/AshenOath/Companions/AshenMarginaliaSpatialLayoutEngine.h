// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Companions/AshenCampfireMarginaliaTypes.h"
#include "AshenMarginaliaSpatialLayoutEngine.generated.h"

/**
 * UAshenMarginaliaSpatialLayoutEngine
 * 
 * Manages spatial anchor slots and text-character budgets:
 * - Max 90 characters for Left/Right margins
 * - Max 140 characters for Footer
 * - Prevents multiple annotations from colliding in the same slot
 */
UCLASS()
class ASHENOATH_API UAshenMarginaliaSpatialLayoutEngine : public UObject
{
	GENERATED_BODY()

public:
	UAshenMarginaliaSpatialLayoutEngine();

	/** Resolves spatial slot conflicts and enforces character budgets */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Journal|Layout")
	TArray<FMarginaliaEntry> ResolveSpatialCollisions(const TArray<FMarginaliaEntry>& InEntries) const;

	/** Clamps text length to slot budget */
	UFUNCTION(BlueprintPure, Category = "Ashen|Journal|Layout")
	FString ClampTextToSlotBudget(const FString& InText, EMarginAnchorSlot Slot) const;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Journal|Layout")
	int32 MarginSlotMaxChars = 90;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Journal|Layout")
	int32 FooterSlotMaxChars = 140;
};
