// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenDiegeticJournalAudioComponent.generated.h"

/**
 * UAshenDiegeticJournalAudioComponent
 * Plays diegetic acoustics: crisp parchment page flips, charcoal quill scratches, and brass astrolabe ratchets.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDiegeticJournalAudioComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenDiegeticJournalAudioComponent();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void PlayPageFlipSFX();

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void PlayQuillScribingSFX();

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void PlayAstrolabeAttunedChimeSFX();
};
