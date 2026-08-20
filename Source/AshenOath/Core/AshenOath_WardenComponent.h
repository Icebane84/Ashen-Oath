// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenOath_WardenComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnBurnoutLevelChangedSignature, float, CurrentBurnout, float, MaxBurnout);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnWardenSpellCastSignature, FString, SpellName, FVector, Location);

/**
 * UAshenOath_WardenComponent
 *
 * Implements Serafina's Empathic Warden abilities, Sun Pulse purification,
 * Sanctuary Anchor deployment, and Empathic Transference Load/Burnout tracking.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenOath_WardenComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenOath_WardenComponent();

protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// --- Empathic Burnout Tracking ---
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Warden")
	float CurrentBurnout = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Warden")
	float MaxBurnout = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Warden")
	float BurnoutDissipationRate = 2.5f; // Dissipates over time when resting

	/** Returns true when Serafina is experiencing Empathic Burnout exhaustion. */
	UFUNCTION(BlueprintPure, Category = "AshenOath|Warden")
	bool IsBurnoutExhausted() const { return CurrentBurnout >= MaxBurnout; }

	// --- Spells & Actions ---

	/** Emits a radiant Sun Pulse wave purifying Null Zone corruption and repelling spectral phantoms within Radius. */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Warden")
	bool CastSunPulse(float Radius = 600.0f);

	/** Deploys a protective Sanctuary Anchor ward reducing sanity drain for all allies within 600uu. */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Warden")
	bool DeploySanctuaryAnchor(FVector WardLocation);

	/** Serafina absorbs Kaelen's shadow sickness transference load, restoring Kaelen's sanity while adding burnout to Serafina. */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Warden")
	bool AbsorbTransferenceLoad(AActor* KaelenActor, float Amount = 25.0f);

	/** Manually triggers resting recovery to clear Serafina's burnout accumulator. */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Warden")
	void RecoverBurnout();

	// --- Events ---
	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Warden|Events")
	FOnBurnoutLevelChangedSignature OnBurnoutLevelChanged;

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Warden|Events")
	FOnWardenSpellCastSignature OnWardenSpellCast;
};
