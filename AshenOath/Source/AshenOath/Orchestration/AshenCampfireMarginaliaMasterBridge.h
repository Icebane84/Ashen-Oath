// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Companions/AshenCampfireMarginaliaTypes.h"
#include "Orchestration/AshenMacroSystemicContractTypes.h"
#include "AshenCampfireMarginaliaMasterBridge.generated.h"

/**
 * UAshenCampfireMarginaliaMasterBridge
 * 
 * Master orchestrator routing campfire rest triggers, marginalia evaluations,
 * and multi-author UI updates.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCampfireMarginaliaMasterBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCampfireMarginaliaMasterBridge();

	/** Broadcasts generated marginalia batch to UI spread */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Orchestration|Marginalia")
	void BroadcastMarginaliaBatch(const TArray<FMarginaliaEntry>& GeneratedEntries);

	/** Broadcasts scratch-out crossout event */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Orchestration|Marginalia")
	void BroadcastCrossoutApplied(const FString& TargetEntryId, const FString& ScratchOutText);

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Orchestration|Marginalia")
	FOnMarginaliaBatchGenerated OnMarginaliaBatchGenerated;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Orchestration|Marginalia")
	FOnMarginaliaCrossoutApplied OnMarginaliaCrossoutApplied;
};
