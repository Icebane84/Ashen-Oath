// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenPurifyingAuraComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAuraPurifyAppliedSignature, AActor*, TargetActor, float, PurifyAmount);

/**
 * UAshenPurifyingAuraComponent
 *
 * Attached to Serafina companion pawn or Consecrated Light actors.
 * Uses UKismetSystemLibrary::SphereOverlapActors to detect nearby allies,
 * passively reducing Kaelen's Shadow Mark corruption (-0.05/s) and cleansing status ailments.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenPurifyingAuraComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenPurifyingAuraComponent();

protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Aura")
	float AuraRadius = 450.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Aura")
	float PurifyRatePerSecond = 0.05f;

	// --- Delegates ---
	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Aura|Events")
	FOnAuraPurifyAppliedSignature OnPurifyApplied;

private:
	void PerformPurificationPulse();
	float TimerTracker = 0.0f;
};
