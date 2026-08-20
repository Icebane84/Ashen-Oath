// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenDiegeticBreathingAudioComponent.generated.h"

/**
 * UAshenDiegeticBreathingAudioComponent
 * Plays spatialized ragged breathing (inhale/exhale) and off-key discordant blade hums during the Discordant Hum struggle.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDiegeticBreathingAudioComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenDiegeticBreathingAudioComponent();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void PlayRaggedBreath(bool bIsInhale);
};
