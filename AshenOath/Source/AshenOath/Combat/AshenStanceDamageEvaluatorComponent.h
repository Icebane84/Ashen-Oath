// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenCombatStanceTypes.h"
#include "AshenStanceDamageEvaluatorComponent.generated.h"

/**
 * UAshenStanceDamageEvaluatorComponent
 * Computes stance-specific combat modifiers (Aegis +50% Poise, Berserk +35% Attack Speed/+20% Damage Taken, Flow balance).
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenStanceDamageEvaluatorComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenStanceDamageEvaluatorComponent();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Combat")
	FStanceModifiers GetModifiersForStance(ECombatStance Stance) const;
};
