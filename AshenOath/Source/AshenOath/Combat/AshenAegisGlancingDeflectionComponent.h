// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenAegisGlancingDeflectionComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGlancingDeflectionExecutedSignature, AActor*, AttackingEnemy, float, EnemyStaggerMagnitude);

/**
 * UAshenAegisGlancingDeflectionComponent
 *
 * Component executing Perfect Parry (Glancing Deflection) with micro-rotation, 0 stamina cost, damage negation, and heavy stagger (PRS-001 Combat Blueprint V5.0).
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenAegisGlancingDeflectionComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenAegisGlancingDeflectionComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|AegisDeflection")
	bool ExecuteGlancingDeflection(AActor* AttackingEnemy);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|AegisDeflection|Events")
	FOnGlancingDeflectionExecutedSignature OnGlancingDeflectionExecuted;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|AegisDeflection")
	int32 TotalPerfectParriesExecuted = 0;
};
