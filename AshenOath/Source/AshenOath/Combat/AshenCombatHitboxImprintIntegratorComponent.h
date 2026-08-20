// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenCombatHitboxImprintIntegratorComponent.generated.h"

/**
 * UAshenCombatHitboxImprintIntegratorComponent
 * Connects hitbox component near-death hits to ImprintBuffer.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCombatHitboxImprintIntegratorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCombatHitboxImprintIntegratorComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Combat")
	void RecordHitImprint(float Damage, bool bFatal);
};
