// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenStarStriderAnomalyActor.generated.h"

/**
 * AAshenStarStriderAnomalyActor
 * 3D celestial entity creating luminous pathways of light across chasms and localized sanctuaries where the Shadow Self's whispers are silenced.
 */
UCLASS()
class ASHENOATH_API AAshenStarStriderAnomalyActor : public AActor
{
	GENERATED_BODY()
public:
	AAshenStarStriderAnomalyActor();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Celestial")
	bool bPathwayOfLightFormed = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Celestial")
	void FormPathwayOfLight();
};
