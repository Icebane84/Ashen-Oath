// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_ConstellationNode.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnConstellationNodeUnlockedSignature, FName, NodeId);

/**
 * UAshenUserWidget_ConstellationNode
 *
 * Single star node widget within the Soul Constellation UI lens.
 * Represents an unlockable identity trait or statutory perk.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_ConstellationNode : public UUserWidget
{
	GENERATED_BODY()

public:
	// --- Properties ---
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Constellation")
	FName NodeId = NAME_None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Constellation")
	FText NodeDisplayName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Constellation")
	float EmberCost = 100.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Constellation")
	bool bIsUnlocked = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Constellation")
	bool bCanUnlock = false;

	// --- API ---
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Constellation")
	bool AttemptUnlock(float AvailableEmbers);

	// --- Events ---
	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Constellation|Events")
	FOnConstellationNodeUnlockedSignature OnNodeUnlocked;

	UFUNCTION(BlueprintImplementableEvent, Category = "AshenOath|Constellation")
	void OnNodeStateUpdated(bool bUnlocked, bool bUnlockable);
};
