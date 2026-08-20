// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSpatialAudioOcclusionMeshComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAudioOcclusionCalculatedSignature, float, TransmissionLossdB, float, LowPassFilterHz);

/**
 * UAshenSpatialAudioOcclusionMeshComponent
 *
 * Procedural volume component modulating raytraced sound occlusion through walls & doorways.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSpatialAudioOcclusionMeshComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSpatialAudioOcclusionMeshComponent();

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|AudioOcclusion")
	void CalculateSpatialOcclusion(FVector SoundOrigin, FVector ListenerPosition);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|AudioOcclusion|Events")
	FOnAudioOcclusionCalculatedSignature OnOcclusionCalculated;
};
