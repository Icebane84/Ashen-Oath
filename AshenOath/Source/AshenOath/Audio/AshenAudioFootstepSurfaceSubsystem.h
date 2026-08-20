// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenAudioFootstepSurfaceSubsystem.generated.h"

UENUM(BlueprintType)
enum class EAshenSurfaceMaterial : uint8
{
	Snow             UMETA(DisplayName = "Snow"),
	RustedMetal      UMETA(DisplayName = "Rusted Metal"),
	StoneFlagstone   UMETA(DisplayName = "Stone Flagstone"),
	VoidIce          UMETA(DisplayName = "Void Ice")
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnFootstepAudioTriggeredSignature, AActor*, WalkerActor, EAshenSurfaceMaterial, Surface, FVector, Location);

/**
 * UAshenAudioFootstepSurfaceSubsystem
 *
 * World Subsystem line tracing physical surface materials under characters to trigger contextual footstep audio cues.
 */
UCLASS()
class ASHENOATH_API UAshenAudioFootstepSurfaceSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Footsteps")
	EAshenSurfaceMaterial EvaluateFootstepSurface(AActor* WalkerActor);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Footsteps|Events")
	FOnFootstepAudioTriggeredSignature OnFootstepAudioTriggered;
};
