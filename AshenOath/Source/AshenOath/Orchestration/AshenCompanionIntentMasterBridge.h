// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Companions/AshenCompanionIntentTypes.h"
#include "Orchestration/AshenMacroSystemicContractTypes.h"
#include "AshenCompanionIntentMasterBridge.generated.h"

/**
 * UAshenCompanionIntentMasterBridge
 * 
 * Master orchestrator connecting player telemetry, companion intent evaluation,
 * GAS abilities, and audio bark dispatchers.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCompanionIntentMasterBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCompanionIntentMasterBridge();

	/** Broadcasts evaluated companion intent */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Orchestration|Intent")
	void BroadcastCompanionIntent(const FCompanionIntentEvaluationResult& Result);

	/** Broadcasts shoulder to shoulder initiation */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Orchestration|Intent")
	void BroadcastShoulderToShoulder(FName CompanionName, float PoiseScalar);

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Orchestration|Intent")
	FOnCompanionIntentEvaluated OnCompanionIntentEvaluated;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Orchestration|Intent")
	FOnShoulderToShoulderInitiated OnShoulderToShoulderInitiated;
};
