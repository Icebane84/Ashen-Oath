// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Scenarios/AshenScenario4WhisperwoodTypes.h"
#include "AshenPurpleMistVolumeActor.generated.h"

class UBoxComponent;

/**
 * AAshenPurpleMistVolumeActor
 * 
 * Environmental trigger volume in Whisperwood modulating volumetric fog density and chromatic aberration.
 */
UCLASS()
class ASHENOATH_API AAshenPurpleMistVolumeActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenPurpleMistVolumeActor();

	virtual void BeginPlay() override;

	/** Sets the purple mist density scalar */
	UFUNCTION(BlueprintCallable, Category = "Ashen|World|Scenario4")
	void SetMistDensity(float NewDensity);

	UFUNCTION(BlueprintPure, Category = "Ashen|World|Scenario4")
	float GetMistDensity() const { return CurrentMistDensity; }

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UBoxComponent* VolumeBounds;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|World|Scenario4")
	float CurrentMistDensity = 0.50f;
};
