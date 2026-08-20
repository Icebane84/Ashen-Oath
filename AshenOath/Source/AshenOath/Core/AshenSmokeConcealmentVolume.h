// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenSmokeConcealmentVolume.generated.h"

class UBoxComponent;
class UParticleSystemComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSmokeConcealmentVolumeExpiredSignature);

/**
 * AAshenSmokeConcealmentVolume
 *
 * World volume spawned by Garrett's smoke balm.
 * Conceals overlapping player/companion pawns from enemy AI perception,
 * clearing threat memory on UAshenOath_ThreatPerceptionComponent.
 */
UCLASS()
class ASHENOATH_API AAshenSmokeConcealmentVolume : public AActor
{
	GENERATED_BODY()

public:
	AAshenSmokeConcealmentVolume();

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UBoxComponent* SmokeVolume;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Stealth")
	float Duration = 10.0f;

	// --- Delegates ---
	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Stealth|Events")
	FOnSmokeConcealmentVolumeExpiredSignature OnVolumeExpired;

private:
	FTimerHandle ExpirationTimerHandle;
	void ExpireVolume();
};
