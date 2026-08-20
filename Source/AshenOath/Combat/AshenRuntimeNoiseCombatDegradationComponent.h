// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenSoulConstellationTypes.h"
#include "AshenRuntimeNoiseCombatDegradationComponent.generated.h"

/**
 * UAshenRuntimeNoiseCombatDegradationComponent
 * Combat component applying Runtime Noise mechanics (15% parry window narrowing factor, stamina recovery dampening, poise delay).
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenRuntimeNoiseCombatDegradationComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenRuntimeNoiseCombatDegradationComponent();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Combat")
	float ParryWindowMultiplier = 1.0f;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Combat")
	float StaminaRegenDampening = 1.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Combat")
	void ApplyRuntimeNoiseDegradation(EAshenIntegrationDebtStage Stage);
};
