// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenFinisherCinematicPostProcessAdapter.generated.h"

/**
 * UAshenFinisherCinematicPostProcessAdapter
 * High-contrast radial blur, golden bloom flashes, and letterboxed cinematic framing during synchronized finishers.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenFinisherCinematicPostProcessAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenFinisherCinematicPostProcessAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Visuals")
	void ApplyFinisherCinematicFX(float Intensity, bool bLetterboxActive);
};
