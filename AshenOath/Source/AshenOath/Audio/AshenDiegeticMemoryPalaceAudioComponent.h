// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenDiegeticMemoryPalaceAudioComponent.generated.h"

/**
 * UAshenDiegeticMemoryPalaceAudioComponent
 * Manages 3D spatialized psychic whispers, crystalline reconstruction harmonics, and locus proximity hums.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDiegeticMemoryPalaceAudioComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenDiegeticMemoryPalaceAudioComponent();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void UpdateLocusAudioResonance(float ProximityIntensity, float ResonanceFrequency);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void PlayReconstructionChime();
};
