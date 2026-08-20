// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenDiegeticJournalPageTurnAudioComponent.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDiegeticJournalPageTurnAudioComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenDiegeticJournalPageTurnAudioComponent();

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void PlayPageTurnAudio(bool bForward);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void PlayInkScratchAudio(float ScratchDuration);
};
