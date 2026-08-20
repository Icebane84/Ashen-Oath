// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenDiegeticJournalParchmentAudioComponent.generated.h"

/**
 * UAshenDiegeticJournalParchmentAudioComponent
 * Manages spatial sound effects for quill ink scratching, charcoal friction sketching, dried page turning, and leyline resonance.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDiegeticJournalParchmentAudioComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenDiegeticJournalParchmentAudioComponent();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void PlayPageTurnCue();

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void PlayResolutionInscribedCue(bool bIsSynarchy);
};
