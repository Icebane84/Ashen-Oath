// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Audio/AshenQuartzAudioTypes.h"
#include "AAshenQuartzAudioConductorActor.generated.h"

/**
 * AAshenQuartzAudioConductorActor
 * 
 * Spatial world actor orchestrating arena-wide Quartz music quantization and spatialized companion audio emitters.
 */
UCLASS()
class ASHENOATH_API AAshenQuartzAudioConductorActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenQuartzAudioConductorActor();

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintPure, Category = "Ashen|Audio|Quartz")
	float GetConductorBPM() const { return ConductorBPM; }

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* SceneRoot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Audio|Quartz")
	float ConductorBPM = 115.0f;
};
