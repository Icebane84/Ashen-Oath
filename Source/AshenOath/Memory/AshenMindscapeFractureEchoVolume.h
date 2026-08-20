// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Volume.h"
#include "AshenMindscapeFractureEchoVolume.generated.h"

/**
 * AAshenMindscapeFractureEchoVolume
 * Spatial volume triggering psychic fracture imprints and memory reflections upon player entry.
 */
UCLASS()
class ASHENOATH_API AAshenMindscapeFractureEchoVolume : public AVolume
{
	GENERATED_BODY()

public:
	AAshenMindscapeFractureEchoVolume();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Memory")
	float FractureInstabilityIndex = 0.65f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Memory")
	void TriggerFractureImprintReflection(AActor* InstigatorActor);
};
