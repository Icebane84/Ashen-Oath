// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenGaslightingGhoulsEnemyComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGaslightingAttackTriggeredSignature, FName, GaslightType, int32, PhantomCloneCount);

/**
 * UAshenGaslightingGhoulsEnemyComponent
 *
 * Specialized enemy component attached to Gaslighting Ghouls. Triggers gaslighting whispers & phantom clone spawns.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenGaslightingGhoulsEnemyComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenGaslightingGhoulsEnemyComponent();

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Gaslighting")
	void TriggerGaslightingAttack();

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Gaslighting|Events")
	FOnGaslightingAttackTriggeredSignature OnGaslightingAttackTriggered;
};
