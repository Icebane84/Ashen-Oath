// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSoulConstellationTypes.h"
#include "AshenDiegeticLensAudioComponent.generated.h"

/**
 * UAshenDiegeticLensAudioComponent
 * Manages diegetic audio cues for lens selection: harmonic bells for Grace, resonant anvil strike for Accountability, and crystal tick for Utility.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDiegeticLensAudioComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenDiegeticLensAudioComponent();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void PlayLensSelectionCue(EInterpretiveLens Lens);
};
