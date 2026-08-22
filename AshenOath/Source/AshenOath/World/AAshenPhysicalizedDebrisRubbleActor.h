// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Combat/AshenKineticBerserkTypes.h"
#include "AAshenPhysicalizedDebrisRubbleActor.generated.h"

class UBoxComponent;

/**
 * AAshenPhysicalizedDebrisRubbleActor
 * 
 * Physicalized stone rubble actor resulting from planar Chaos structural fractures, providing audio occlusion.
 */
UCLASS()
class ASHENOATH_API AAshenPhysicalizedDebrisRubbleActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenPhysicalizedDebrisRubbleActor();

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintPure, Category = "Ashen|World|KineticBerserk")
	float GetRubbleVolumeFootprint() const { return RubbleVolumeFootprint; }

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UBoxComponent* RubbleBounds;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|World|KineticBerserk")
	float RubbleVolumeFootprint = 75000.0f; // cubic cm
};
