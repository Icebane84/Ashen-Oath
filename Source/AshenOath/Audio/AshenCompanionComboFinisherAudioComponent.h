// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenCompanionComboFinisherAudioComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnComboFinisherAudioTriggeredSignature, FName, CompanionID, FName, AudioBarkTag);

/**
 * UAshenCompanionComboFinisherAudioComponent
 *
 * Procedural audio component syncing voice barks and dual-execution sound layers during companion combo finishers.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCompanionComboFinisherAudioComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCompanionComboFinisherAudioComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Audio")
	void TriggerFinisherVoiceBark(FName CompanionID, FName AudioBarkTag);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Audio|Events")
	FOnComboFinisherAudioTriggeredSignature OnFinisherAudioTriggered;
};
