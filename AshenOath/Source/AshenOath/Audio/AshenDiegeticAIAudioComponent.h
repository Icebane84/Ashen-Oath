// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenDiegeticAIAudioComponent.generated.h"

/**
 * UAshenDiegeticAIAudioComponent
 * Audio component modulating AI attack telegraph cues, posture break cues, and punish window audio feedback.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDiegeticAIAudioComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenDiegeticAIAudioComponent();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Audio")
	float TelegraphAudioVolume = 0.85f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void TriggerAttackTelegraphAudio();

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void TriggerPunishWindowOpportunityAudio();
};
