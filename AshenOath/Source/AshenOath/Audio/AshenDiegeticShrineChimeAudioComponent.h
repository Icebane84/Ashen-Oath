// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenDiegeticShrineChimeAudioComponent.generated.h"

/**
 * UAshenDiegeticShrineChimeAudioComponent
 * Audio component modulating sacred chime harmonic frequencies at consecrated purification shrines.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDiegeticShrineChimeAudioComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenDiegeticShrineChimeAudioComponent();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Audio")
	float ChimeHarmonicResonance = 1.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void TriggerHarmonicChimePulse();
};
