// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenPsychologicalRuntimeBroadcaster.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnPsychologicalRuntimeBroadcastedSignature, float, IntegrationDebt, float, Resolve, float, NarrativeEntropy);

/**
 * UAshenPsychologicalRuntimeBroadcaster
 *
 * Subsystem broadcasting updated soul state metrics to AI, UI, C++ components, and Audio subsystems.
 */
UCLASS()
class ASHENOATH_API UAshenPsychologicalRuntimeBroadcaster : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|PsychologicalRuntime")
	void BroadcastPsychologicalRuntimeState(float IntegrationDebt, float Resolve, float NarrativeEntropy);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|PsychologicalRuntime|Events")
	FOnPsychologicalRuntimeBroadcastedSignature OnRuntimeBroadcasted;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|PsychologicalRuntime")
	int32 TotalBroadcastsSent = 0;
};
