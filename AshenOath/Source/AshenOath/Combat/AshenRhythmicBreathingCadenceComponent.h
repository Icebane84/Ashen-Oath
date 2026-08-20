// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenControllerFrictionTypes.h"
#include "AshenRhythmicBreathingCadenceComponent.generated.h"

/**
 * UAshenRhythmicBreathingCadenceComponent
 * Manages alternating Cross (Inhale) and Square (Exhale) breathing cadence aligned with Kaelen's chest starburst reticle.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenRhythmicBreathingCadenceComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenRhythmicBreathingCadenceComponent();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Breathing")
	FBreathingRhythmCadence CurrentCadence;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Breathing")
	bool RegisterBreathInput(bool bIsInhaleInput);
};
