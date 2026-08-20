// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenTransferenceVFXComponent.generated.h"

class UNiagaraComponent;
class UNiagaraSystem;
class UMaterialInstanceDynamic;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnTransferenceVFXTriggeredSignature, FVector, Source, FVector, Destination);

/**
 * UAshenTransferenceVFXComponent
 *
 * Drives real-time Niagara particle systems, material parameters, ocular emissive curves,
 * and Transference tethers across Kaelen's corruption phases and the Umbral Symbiote.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenTransferenceVFXComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenTransferenceVFXComponent();

protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// --- Visual Parameters ---
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|VFX")
	float SmoothStepT1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|VFX")
	float SmoothStepT2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|VFX")
	TObjectPtr<UNiagaraSystem> TransferenceRibbonSystem;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|VFX")
	TObjectPtr<UNiagaraSystem> DeflectionSparksSystem;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|VFX")
	TObjectPtr<UNiagaraSystem> ArmorFractureSystem;

	// --- Actions ---

	/** Dynamically updates ocular emissive curves, soot veil opacity, and Shadow's Mark via two-phase smoothstep curves. */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|VFX")
	void UpdateCorruptionVFX(float CorruptionAmount);

	/** Triggers white-gold holy ember transference burst and ribbon tether between Serafina and target. */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|VFX")
	void TriggerTransferenceBurst(FVector SourceLocation, FVector TargetLocation);

	/** Triggers Bastion armor impact VFX (Sparks if deflected/immune, Fractures if vulnerable). */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|VFX")
	void TriggerBastionShieldImpact(FVector ImpactPoint, bool bIsDeflected);

	// --- Events ---
	UPROPERTY(BlueprintAssignable, Category = "AshenOath|VFX|Events")
	FOnTransferenceVFXTriggeredSignature OnTransferenceVFXTriggered;

private:
	UPROPERTY(Transient)
	TArray<TObjectPtr<UMaterialInstanceDynamic>> DynamicMaterials;

	float SmoothStepCustom(float Edge0, float Edge1, float X) const;
};
