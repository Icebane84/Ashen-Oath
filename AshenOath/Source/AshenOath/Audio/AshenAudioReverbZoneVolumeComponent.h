// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenAudioReverbSubsystem.h"
#include "AshenAudioReverbZoneVolumeComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnReverbZoneEnteredSignature, EAshenReverbPreset, Preset, float, FadeTime);

/**
 * UAshenAudioReverbZoneVolumeComponent
 *
 * Trigger volume component managing spatial audio environment transitions.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenAudioReverbZoneVolumeComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenAudioReverbZoneVolumeComponent();

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|ReverbZone")
	void TriggerReverbTransition();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|ReverbZone")
	EAshenReverbPreset EnvironmentPreset = EAshenReverbPreset::CaveCathedral;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|ReverbZone")
	float FadeTimeSeconds = 2.0f;

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|ReverbZone|Events")
	FOnReverbZoneEnteredSignature OnReverbZoneEntered;
};
