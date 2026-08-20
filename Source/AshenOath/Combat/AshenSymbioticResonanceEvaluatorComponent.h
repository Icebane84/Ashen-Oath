// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AI/AshenCombatEcosystemTypes.h"
#include "AshenSymbioticResonanceEvaluatorComponent.generated.h"

/**
 * UAshenSymbioticResonanceEvaluatorComponent
 * Evaluates real-time Symbiotic Resonance conditions: fades HUD clutter and unlocks frictionless triple-combination sync finishers.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSymbioticResonanceEvaluatorComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenSymbioticResonanceEvaluatorComponent();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Resonance")
	bool bIsResonanceActive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Resonance")
	void SetResonanceState(bool bActive);
};
