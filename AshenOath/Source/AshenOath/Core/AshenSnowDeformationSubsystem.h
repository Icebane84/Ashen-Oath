// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenSnowDeformationSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnFootprintDeformationRegisteredSignature, FVector, WorldLocation, float, Radius);

/**
 * UAshenSnowDeformationSubsystem
 *
 * World subsystem managing dynamic snow surface footprint deformation buffers.
 * Registers character footstep locations to drive dynamic snow displacement materials across Frozen Tarn.
 */
UCLASS()
class ASHENOATH_API UAshenSnowDeformationSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	// --- Public API ---
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Deformation")
	void RegisterFootprintDeformation(FVector WorldLocation, float FootprintRadius = 25.0f);

	UFUNCTION(BlueprintPure, Category = "AshenOath|Deformation")
	int32 GetActiveFootprintCount() const { return RegisteredFootprints.Num(); }

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Deformation")
	TArray<FVector> RegisteredFootprints;

	// --- Delegates ---
	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Deformation|Events")
	FOnFootprintDeformationRegisteredSignature OnFootprintRegistered;
};
