// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenScarsOfCorruptionComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnScarOfCorruptionIncurredSignature, int32, ScarCount, float, MaxSanityPenalty);

/**
 * UAshenScarsOfCorruptionComponent
 *
 * Attached to Kaelen. Tracks permanent max Sanity reductions incurred from using peak Resonance Echo abilities.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenScarsOfCorruptionComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenScarsOfCorruptionComponent();

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|ScarsOfCorruption")
	void IncurCorruptionScar(float PenaltyAmount);

	UFUNCTION(BlueprintPure, Category = "AshenOath|ScarsOfCorruption")
	int32 GetScarCount() const { return ScarCount; }

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|ScarsOfCorruption|Events")
	FOnScarOfCorruptionIncurredSignature OnScarIncurred;

private:
	int32 ScarCount = 0;
	float TotalMaxSanityPenalty = 0.0f;
};
