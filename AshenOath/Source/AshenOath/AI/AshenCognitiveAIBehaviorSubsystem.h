// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenCognitiveAIBehaviorSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAIAggressivenessModulatedSignature, float, SanityLevel, float, AggressivenessMultiplier);

/**
 * UAshenCognitiveAIBehaviorSubsystem
 *
 * World Subsystem modulating enemy & neutral NPC AI aggressiveness based on Kaelen's Sanity level.
 */
UCLASS()
class ASHENOATH_API UAshenCognitiveAIBehaviorSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|CognitiveAI")
	void ModulateAIBasedOnSanity(float CurrentSanity);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|CognitiveAI|Events")
	FOnAIAggressivenessModulatedSignature OnAIAggressivenessModulated;
};
