// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Companions/AshenRelationalEcologyTypes.h"
#include "Orchestration/AshenMacroSystemicContractTypes.h"
#include "AshenRelationalEcologyMasterBridge.generated.h"

/**
 * UAshenRelationalEcologyMasterBridge
 * 
 * Master domain bridge coordinating:
 * - Event routing between UAshenRelationalEcologySubsystem and Combat GAS
 * - Dynamic AI formation adjustment broadcasts
 * - Wordless reconciliation execution triggers
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenRelationalEcologyMasterBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenRelationalEcologyMasterBridge();

	/** Broadcasts costly presence event to world and companion AI */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Orchestration|Ecology")
	void BroadcastCostlyPresenceTriggered(const FAshenCostlyPresenceIntent& Intent, const FVector& TargetLocation);

	/** Broadcasts wordless reconciliation execution */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Orchestration|Ecology")
	void BroadcastWordlessReconciliation(FName CompanionName);

	/** Broadcasts dynamic formation spacing update to companion AI tree */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Orchestration|Ecology")
	void BroadcastFormationSpacingUpdate(FName CompanionName, float TargetSpacingUU, float LerpSpeed = 3.5f);

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Orchestration|Ecology")
	FOnCostlyPresenceTriggered OnCostlyPresenceTriggered;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Orchestration|Ecology")
	FOnWordlessReconciliationExecuted OnWordlessReconciliationExecuted;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Orchestration|Ecology")
	FOnDynamicFormationOffsetUpdated OnDynamicFormationOffsetUpdated;
};
