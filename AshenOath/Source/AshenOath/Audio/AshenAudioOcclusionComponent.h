// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenAudioOcclusionComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnComponentAudioOcclusionUpdatedSignature, float, OcclusionPercent, float, LowPassCutoffFrequency);

/**
 * UAshenAudioOcclusionComponent
 *
 * Component calculating real-time raycast audio occlusion & low-pass filtering for diegetic MetaSounds.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenAudioOcclusionComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenAudioOcclusionComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|AudioOcclusion")
	float EvaluateAudioOcclusion(FVector SoundOrigin, FVector ListenerLocation);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|AudioOcclusion|Events")
	FOnComponentAudioOcclusionUpdatedSignature OnAudioOcclusionUpdated;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|AudioOcclusion")
	float CalculatedOcclusionPercent = 0.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|AudioOcclusion")
	float CalculatedLowPassCutoff = 20000.0f;
};
