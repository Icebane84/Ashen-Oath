// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Narrative/AshenLivingCodexTypes.h"
#include "AshenDiegeticCodexAudioComponent.generated.h"

/**
 * UAshenDiegeticCodexAudioComponent
 * Manages parchment rustling, ancient runic hums, and whispered lore exposition audio cues.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDiegeticCodexAudioComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenDiegeticCodexAudioComponent();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void PlayCodexUnlockAudio(ECodexFaction Faction);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void PlayWhisperEchoCue();
};
