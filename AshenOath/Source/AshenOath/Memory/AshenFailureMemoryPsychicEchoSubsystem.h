// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenFailureMemoryPsychicEchoSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnFailurePsychicEchoImprintedSignature, FName, FailureID, FVector, EchoLocation);

/**
 * UAshenFailureMemoryPsychicEchoSubsystem
 *
 * World Subsystem tracking permanent failure imprints and spawning Psychic Echoes at failure locations (Directive #2).
 * Inflicts Virtue Fractures like Survivor's Guilt upon failure events.
 */
UCLASS()
class ASHENOATH_API UAshenFailureMemoryPsychicEchoSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|FailureMemory")
	void ImprintFailurePsychicEcho(FName FailureID, FVector EchoLocation);

	UFUNCTION(BlueprintPure, Category = "AshenOath|FailureMemory")
	int32 GetTotalImprintedFailureCount() const { return ImprintedFailures.Num(); }

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|FailureMemory|Events")
	FOnFailurePsychicEchoImprintedSignature OnPsychicEchoImprinted;

private:
	TArray<FName> ImprintedFailures;
};
