// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Companions/AshenCampfireMarginaliaTypes.h"
#include "AshenPenmanshipDiegeticAudioComponent.generated.h"

class USoundBase;
class UAudioComponent;

/**
 * UAshenPenmanshipDiegeticAudioComponent
 * 
 * Plays tactile penmanship audio cues:
 * - Garrett: Harsh charcoal scraping on parchment
 * - Serafina: Soft quill scratching and ink blotting
 * - Kaelen: Heavy iron nib scratching with friction jitter
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenPenmanshipDiegeticAudioComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenPenmanshipDiegeticAudioComponent();

	virtual void BeginPlay() override;

	/** Plays penmanship inscription sound */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Audio|Penmanship")
	void PlayPenmanshipSound(EMarginaliaAuthor Author, USoundBase* CueSound);

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UAudioComponent* InscriptionAudioComponent;
};
