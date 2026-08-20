// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenAudioSpatialVoiceComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnDialogueBarkPlayedSignature, FName, VoiceLineID, float, Duration);

/**
 * UAshenAudioSpatialVoiceComponent
 *
 * Attached to NPCs and companions. Handles 3D spatialized dialogue barks with attenuation & occlusion support.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenAudioSpatialVoiceComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenAudioSpatialVoiceComponent();

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|AudioVoice")
	void PlaySpatialDialogueBark(FName VoiceLineID, float Duration = 2.5f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|AudioVoice")
	float MaxVoiceDistance = 1500.0f;

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|AudioVoice|Events")
	FOnDialogueBarkPlayedSignature OnDialogueBarkPlayed;
};
