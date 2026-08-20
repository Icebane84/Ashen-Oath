// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_ConstellationPerkTree.generated.h"

/**
 * UAshenUserWidget_ConstellationPerkTree
 *
 * UMG backing widget rendering Soul Constellation node connections and active perk boons.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_ConstellationPerkTree : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void UpdateConstellationTreeDisplay(FName NodeID, int32 TotalUnlockedNodes);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	FName DisplayedNodeID;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	int32 TotalActiveNodes = 0;
};
