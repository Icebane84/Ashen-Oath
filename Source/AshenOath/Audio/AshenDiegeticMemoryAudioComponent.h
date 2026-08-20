// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenDiegeticMemoryAudioComponent.generated.h"

/**
 * UAshenDiegeticMemoryAudioComponent
 * Manages reverse reverb memory whispers, heartbeat slow-mo pacing, and cathartic bell chimes upon echo resolution.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDiegeticMemoryAudioComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenDiegeticMemoryAudioComponent();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void PlayMemoryWhisperLoop();

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void PlayCatharticBellChime();
};
