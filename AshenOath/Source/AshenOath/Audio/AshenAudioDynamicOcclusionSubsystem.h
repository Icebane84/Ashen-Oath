// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenAudioDynamicOcclusionSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAudioOcclusionUpdatedSignature, AActor*, SoundSource, float, LowPassFilterCutoff);

/**
 * UAshenAudioDynamicOcclusionSubsystem
 *
 * World Subsystem performing geometry line trace raycasting to dynamically calculate audio occlusion and low-pass filter frequency cutoff.
 */
UCLASS()
class ASHENOATH_API UAshenAudioDynamicOcclusionSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|AudioOcclusion")
	float CalculateOcclusionFrequency(AActor* Listener, AActor* SoundSource);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|AudioOcclusion")
	float MaxCutoffFrequency = 20000.0f; // Unoccluded clear audio

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|AudioOcclusion")
	float MinCutoffFrequency = 800.0f; // Heavily muffled wall audio

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|AudioOcclusion|Events")
	FOnAudioOcclusionUpdatedSignature OnAudioOcclusionUpdated;
};
