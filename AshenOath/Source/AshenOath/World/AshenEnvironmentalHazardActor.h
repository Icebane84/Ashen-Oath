// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenEnvironmentalHazardActor.generated.h"

class UBoxComponent;
class UStaticMeshComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnHazardDamageAppliedSignature, AActor*, HazardActor, AActor*, TargetActor, float, DamageAmount);

/**
 * AAshenEnvironmentalHazardActor
 *
 * Interactive environmental hazard actor (Corrupted Brambles, Shadow Spikes, Blight Geysers).
 * Deals periodic health and poise damage to pawns standing inside the hazard volume.
 */
UCLASS()
class ASHENOATH_API AAshenEnvironmentalHazardActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenEnvironmentalHazardActor();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UBoxComponent* HazardVolume;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* HazardMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Hazard")
	float DamagePerSecond = 20.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Hazard")
	float PoiseDamagePerSecond = 15.0f;

	// --- Delegates ---
	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Hazard|Events")
	FOnHazardDamageAppliedSignature OnHazardDamageApplied;

private:
	float TimerTracker = 0.0f;
	void ApplyHazardDamage();
};
