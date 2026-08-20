// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenRehabilitationAudioResonatorComponent.generated.h"

/**
 * UAshenRehabilitationAudioResonatorComponent
 * Audio component playing therapeutic harmonic chords during identity alignment.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenRehabilitationAudioResonatorComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenRehabilitationAudioResonatorComponent();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void TriggerHarmonicResonanceChord();
};
