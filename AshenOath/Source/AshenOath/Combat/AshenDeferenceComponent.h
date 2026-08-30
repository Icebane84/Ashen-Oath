// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenSoulTypes.h"
#include "AshenDeferenceComponent.generated.h"

UENUM(BlueprintType)
enum class EDeferenceTarget : uint8
{
	Garrett  UMETA(DisplayName = "Garrett (Vault Flank / Stagger)"),
	Serafina UMETA(DisplayName = "Serafina (Conduit Burst / Slag Cleansing)")
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCalculatedDeferenceEngaged, EDeferenceTarget, Target, float, LockoutDuration);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDeferenceCompanionStrikeDelivered, EDeferenceTarget, Target);

/**
 * UAshenDeferenceComponent
 * Implements Calculated Deference & The Martial Fulcrum (COMBAT-101 / AOP-MASTER-CONVERGENCE-SPEC-V2.0).
 * "Don't confuse suffering with responsibility."
 * Surrenders offensive DPS (0.60s lockout) and absorbs 80% poise strain to create an immovable fulcrum for companions.
 */
UCLASS(BlueprintType, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDeferenceComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenDeferenceComponent();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	/** Engages the high longsword bind (Ochs / Mordhau) and locks offensive agency for 0.60s */
	UFUNCTION(BlueprintCallable, Category = "Combat|Deference")
	void ExecuteCalculatedDeference(EDeferenceTarget Target);

	/** Called when companion vault / conduit strike connects, delivering payoff and stabilizing state */
	UFUNCTION(BlueprintCallable, Category = "Combat|Deference")
	void OnCompanionStrikeDelivered();

	UFUNCTION(BlueprintPure, Category = "Combat|Deference")
	bool IsDeferenceActive() const { return bIsDeferenceActive; }

	UFUNCTION(BlueprintPure, Category = "Combat|Deference")
	float GetPoiseStrainAbsorption() const { return PoiseStrainAbsorptionMultiplier; }

	UPROPERTY(BlueprintAssignable, Category = "Combat|Deference")
	FOnCalculatedDeferenceEngaged OnCalculatedDeferenceEngaged;

	UPROPERTY(BlueprintAssignable, Category = "Combat|Deference")
	FOnDeferenceCompanionStrikeDelivered OnDeferenceCompanionStrikeDelivered;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Combat|Deference")
	float DeferenceLockoutSeconds = 0.60f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Combat|Deference")
	float PoiseStrainAbsorptionMultiplier = 0.80f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Combat|Deference")
	bool bIsDeferenceActive = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Combat|Deference")
	float CurrentLockoutRemaining = 0.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Combat|Deference")
	EDeferenceTarget ActiveTarget = EDeferenceTarget::Garrett;
};
