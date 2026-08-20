// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenAlchemicalTrapActor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnTrapDetonatedSignature, FVector, DetonationLocation, int32, TargetsHit);

/**
 * AAshenAlchemicalTrapActor
 * World Actor for deployable alchemical traps dealing damage, staggering enemies, and spawning volatile flame pools.
 */
UCLASS()
class ASHENOATH_API AAshenAlchemicalTrapActor : public AActor
{
	GENERATED_BODY()
public:
	AAshenAlchemicalTrapActor();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Trap|Events")
	FOnTrapDetonatedSignature OnTrapDetonated;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Trap")
	float DetonationDamage = 650.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Trap")
	float DetonationRadius = 450.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Trap")
	float FlameDuration = 5.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Trap")
	bool bIsArmed = true;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Trap")
	void TriggerTrapDetonation();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Trap")
	void DetonateAlchemicalTrap();
};
