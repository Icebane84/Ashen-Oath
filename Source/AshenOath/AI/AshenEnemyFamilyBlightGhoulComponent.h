// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenEnemyFamilyBlightGhoulComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGhoulSwarmStateChangedSignature, int32, SwarmMemberCount, float, FlankDamageMultiplier);

/**
 * UAshenEnemyFamilyBlightGhoulComponent
 *
 * Blight Ghoul swarm AI component projecting into 3 distinct layers under Constitutional Law #476:
 * Layer 1 (Combat): Flanking attack damage boost per swarm member.
 * Layer 2 (Audio/VFX): Hissing MetaSound audio & green poison drool particles.
 * Layer 3 (AI): Squad coordination alert driving swarm encirclement.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenEnemyFamilyBlightGhoulComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenEnemyFamilyBlightGhoulComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|EnemyFamily")
	void UpdateSwarmCoordination(int32 NearbyGhoulCount);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|EnemyFamily|Events")
	FOnGhoulSwarmStateChangedSignature OnSwarmStateChanged;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|EnemyFamily")
	int32 ActiveSwarmMemberCount = 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|EnemyFamily")
	float CalculatedFlankMultiplier = 1.0f;
};
