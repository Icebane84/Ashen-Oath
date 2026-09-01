// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenSoulPublisher.h"
#include "Combat/AshenOathbringerMetallurgyTypes.h"
#include "AshenOathbringerMorphComponent.generated.h"

class UMeshComponent;
class UMaterialInstanceDynamic;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMetallurgyTierMorphed, EOathbringerMetallurgicalTier, NewTier);

/**
 * UAshenOathbringerMorphComponent
 *
 * Real-time physical and visual actuator attached to Oathbringer.
 * Modulates PBR material parameters (roughness, silver inlay reflection, 2.0-inch light absorption envelope,
 * retroreflective wolf pommel), dynamic weapon handling mass (45kg <-> 120kg), and acoustic profiles.
 * (PATCH v158.17.0 / METALLURGY-SPEC-102)
 */
UCLASS(ClassGroup = (AshenCombat), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenOathbringerMorphComponent : public UActorComponent, public IAshenStateConsumer
{
	GENERATED_BODY()

public:
	UAshenOathbringerMorphComponent();

	virtual void BeginPlay() override;

	/** IAshenStateConsumer Interface */
	virtual void OnStateSnapshotCommitted_Implementation(const FAshenStateSnapshot& Snapshot) override;

	/** Manually triggers an evaluation and morph to the target tier */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Metallurgy")
	void ApplyMetallurgyMorph(EOathbringerMetallurgicalTier TargetTier, float InResolve, float InCorruption, float InDebt);

	/** Binds the target mesh component for material parameter modulation */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Metallurgy")
	void SetTargetMesh(UMeshComponent* InMesh);

	UFUNCTION(BlueprintPure, Category = "Ashen|Metallurgy")
	EOathbringerMetallurgicalTier GetCurrentTier() const { return CurrentTier; }

	UFUNCTION(BlueprintPure, Category = "Ashen|Metallurgy")
	const FOathbringerMaterialParameters& GetCurrentMaterialParameters() const { return CurrentMaterialParams; }

	UFUNCTION(BlueprintPure, Category = "Ashen|Metallurgy")
	const FOathbringerAcousticProfile& GetCurrentAcousticProfile() const { return CurrentAcousticProfile; }

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Metallurgy")
	FOnMetallurgyTierMorphed OnMetallurgyTierMorphed;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Metallurgy")
	EOathbringerMetallurgicalTier CurrentTier = EOathbringerMetallurgicalTier::BurdenedIron;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Metallurgy")
	FOathbringerMaterialParameters CurrentMaterialParams;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Metallurgy")
	FOathbringerAcousticProfile CurrentAcousticProfile;

	UPROPERTY()
	TObjectPtr<UMeshComponent> TargetMeshComponent;

	UPROPERTY()
	TObjectPtr<UMaterialInstanceDynamic> DynamicMaterial;

private:
	void UpdateMaterialShaderParameters();
};
