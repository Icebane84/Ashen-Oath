// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenDiegeticFractureResonanceAudioComponent.generated.h"

/**
 * UAshenDiegeticFractureResonanceAudioComponent
 * Audio component emitting harmonic fracture resonance chimes during mindscape instability transitions.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDiegeticFractureResonanceAudioComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenDiegeticFractureResonanceAudioComponent();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Audio")
	float FractureChimePitch = 1.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void TriggerFractureResonancePulse(float InstabilityIndex);
};
