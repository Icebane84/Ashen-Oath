// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenSolarBeaconActor.generated.h"

class USphereComponent;
class UStaticMeshComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSolarBeaconPulseExecutedSignature, int32, HealedAllyCount, int32, DamagedEnemyCount);

/**
 * AAshenSolarBeaconActor
 *
 * World actor placed by Serafina emitting a 500uu holy ward pulse every 3 seconds.
 * Heals allied pawns (+40 HP) and deals holy damage to corrupted enemy pawns (50 HP).
 */
UCLASS()
class ASHENOATH_API AAshenSolarBeaconActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenSolarBeaconActor();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USphereComponent* WardVolume;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* BeaconMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Beacon")
	float HealAmountPerPulse = 40.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Beacon")
	float HolyDamagePerPulse = 50.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Beacon")
	float PulseInterval = 3.0f;

	// --- Delegates ---
	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Beacon|Events")
	FOnSolarBeaconPulseExecutedSignature OnPulseExecuted;

private:
	float TimerTracker = 0.0f;
	void ExecuteHolyPulse();
};
