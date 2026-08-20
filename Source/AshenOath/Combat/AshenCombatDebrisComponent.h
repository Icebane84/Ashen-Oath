// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenCombatDebrisComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCombatDebrisSpawnedSignature, FVector, ImpactLocation, float, DebrisScale);

/**
 * UAshenCombatDebrisComponent
 *
 * Component spawning physical debris and dust clouds on heavy weapon impacts.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCombatDebrisComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCombatDebrisComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|CombatDebris")
	void SpawnCombatDebris(FVector ImpactLocation, float Scale = 1.0f);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|CombatDebris|Events")
	FOnCombatDebrisSpawnedSignature OnDebrisSpawned;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|CombatDebris")
	int32 TotalDebrisSpawned = 0;
};
