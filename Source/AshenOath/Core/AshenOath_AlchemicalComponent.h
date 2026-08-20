// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenOath_AlchemicalComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAlchemicalMatrixDeployedSignature, FString, MatrixName, FVector, Location);

/**
 * UAshenOath_AlchemicalComponent
 *
 * Implements Garrett Alerion's zero-magical alchemical utility matrix.
 * Manages inventory reserves, posture-breaking oils, shadow dampeners, sulfurous smoke, and tripwire flares.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenOath_AlchemicalComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenOath_AlchemicalComponent();

protected:
	virtual void BeginPlay() override;

public:
	// --- Alchemical Charges ---
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Alchemical|Inventory")
	int32 BurningSteelOilCharges = 3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Alchemical|Inventory")
	int32 GloomwoodDampenerCharges = 2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Alchemical|Inventory")
	int32 SulfurousSmokeBalmCharges = 4;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Alchemical|Inventory")
	int32 GhostbloomTripwireCharges = 3;

	// --- Deployment Actions ---

	/** Matrix I: Burning Steel Oil -- Infuses cutlasses/weapons with kinetic ignition oil (+35 Posture Damage, -15% Armor). */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Alchemical")
	bool DeployBurningSteelOil(AActor* TargetActor);

	/** Matrix II: Gloomwood Dampener -- Suppresses Kaelen's shadow sickness scaling and reduces corruption drain. */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Alchemical")
	bool AdministerGloomwoodDampener(AActor* KaelenActor);

	/** Matrix III: Sulfurous Smoke Balm -- Throws dense smoke cloud blinding all units within 400uu radius. */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Alchemical")
	bool ThrowSulfurousSmokeBalm(FVector TargetLocation);

	/** Matrix IV: Ghostbloom Tripwire Flare -- Seeds high-frequency flash-powder tripwire stunning targets within 600uu. */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Alchemical")
	bool DeployGhostbloomTripwire(FVector TripwireLocation);

	// --- Events ---

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Alchemical|Events")
	FOnAlchemicalMatrixDeployedSignature OnMatrixDeployed;
};
