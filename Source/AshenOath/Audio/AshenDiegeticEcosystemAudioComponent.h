// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenDiegeticEcosystemAudioComponent.generated.h"

/**
 * UAshenDiegeticEcosystemAudioComponent
 * Manages spatial sound design for boss phase transitions, Star-Strider celestial hums, and rhythmic resonance alignments.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDiegeticEcosystemAudioComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenDiegeticEcosystemAudioComponent();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void PlaySymbioticResonanceHarmonicHum();
};
