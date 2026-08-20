// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenDiegeticAscensionChimeAudioComponent.generated.h"

/**
 * UAshenDiegeticAscensionChimeAudioComponent
 * Audio component modulating sacred ascension chime harmonics during Sovereign Phoenix rituals.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDiegeticAscensionChimeAudioComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenDiegeticAscensionChimeAudioComponent();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Audio")
	float AscensionChimeHarmonics = 1.5f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void TriggerAscensionHarmonicChimePulse();
};
