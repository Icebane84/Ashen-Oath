// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenCompanionTrustDialogueTreeAdapter.generated.h"

/**
 * UAshenCompanionTrustDialogueTreeAdapter
 * Adapter mapping companion trust scores into unlocked dialogue nodes.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCompanionTrustDialogueTreeAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenCompanionTrustDialogueTreeAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Narrative")
	bool IsDialogueNodeUnlockedByTrust(FName CompanionID, FName NodeID, float CurrentTrust);
};
