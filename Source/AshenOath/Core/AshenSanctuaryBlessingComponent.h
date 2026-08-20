// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSanctuaryBlessingComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSanctuaryBlessingAppliedSignature, float, HealthHealed, float, SanityRestored);

/**
 * UAshenSanctuaryBlessingComponent
 *
 * Sanctuary blessing aura component attached to Serafina or Sanctuary campfires.
 * Provides passive health (+5 HP/s) and sanity recovery (+0.05/s) to allies within 400uu.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSanctuaryBlessingComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSanctuaryBlessingComponent();

protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Sanctuary")
	float HealingRate = 5.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Sanctuary")
	float SanityRestorationRate = 5.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Sanctuary")
	float BlessingRadius = 400.0f;

	// --- Delegates ---
	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Sanctuary|Events")
	FOnSanctuaryBlessingAppliedSignature OnBlessingApplied;
};
