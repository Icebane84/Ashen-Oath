// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenOathbringerWeaponRackWorldActor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnWeaponRackInteractedSignature, AActor*, InteractingPlayer, bool, bIsWeaponMounted);

/**
 * AAshenOathbringerWeaponRackWorldActor
 *
 * Interactive weapon rack actor in level space for weapon inspection, maintenance, and upgrade (PRS-001 Oathbringer Slice).
 */
UCLASS()
class ASHENOATH_API AAshenOathbringerWeaponRackWorldActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenOathbringerWeaponRackWorldActor();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|WeaponRack")
	void InteractWithWeaponRack(AActor* InteractingPlayer);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|WeaponRack|Events")
	FOnWeaponRackInteractedSignature OnRackInteracted;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|WeaponRack")
	bool bIsWeaponMounted = true;
};
